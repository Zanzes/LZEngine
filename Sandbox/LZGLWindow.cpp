#include <GL/glew.h>
#include "LZGLWindow.h"
#include <Math/Vector3D.h>
#include <Math/Matrix2DH.h>
#include <Timing/FrameTimer.h>
#include <Profiling/Profile.h>
#include <Profiling/Profiler.h>
#include <QtGui/QKeyEvent>
#include <QtCore/QDebug>
#include <cassert>
#include "Math/ProMath.h"
#include "Math/Constants.h"
#include <cmath>

using LZSoft::Math::Vector3D;
using LZSoft::Math::Matrix2DH;
using LZSoft::Profiling::Profiler;

class Player
{
public:
	Vector3D myVerts[3] =
	{
		Vector3D(+0.0f, +0.1f, +1.f),
		Vector3D(-0.1f, -0.1f, +1.f),
		Vector3D(+0.1f, -0.1f, +1.f)
	};
	Vector3D position = Vector3D(0.2f, 0.1f);
	Vector3D lastPosition = Vector3D(0.0f, 0.0f);
	Vector3D velocity = Vector3D(0.0f, 0.0f);
	float acceleration = 1.f;
	float angular_acceleration = 3.f;
	float rotation;
	static const unsigned int vertCount;
};
const unsigned int Player::vertCount = sizeof(myVerts) / sizeof(*myVerts);

using namespace LZSoft::Profiling;
using namespace LZSoft::Timing;

namespace
{
	GLuint shipVertexBufferID;
	GLuint enemyVertexBufferID;
	GLuint boundaryVertexBufferID;
	GLuint boundaryIVertexBufferID;
	Vector3D border[] =
	{
		Vector3D(+0.0f, +1.0f, +0.0f),
		Vector3D(-1.0f, +0.0f, +0.0f),
		Vector3D(+0.0f, -1.0f, +0.0f),
		Vector3D(+1.0f, +0.0f, +0.0f)
	};

	GLushort boundaryVBIndecies[] = { 0,1,1,2,2,3,3,0 };

	Vector3D lerpPoints[] =
	{
		Vector3D(-0.5f, +0.5f, +0.0f),
		Vector3D(-0.5f, -0.5f, +0.0f),
		Vector3D(+0.5f, -0.5f, +0.0f),
		Vector3D(+0.5f, +0.5f, +0.0f)
	};
	/*__int64 lerpStart;
	__int64 lerpEnd;*/
	int lerps = sizeof(lerpPoints) / sizeof(*lerpPoints);
	int lerpStart = 0;
	int lerpEnd = 1;
	float alpha;


	Player player;
	Player enemy;
	static const unsigned int numBoundaryVerts = sizeof(border) / sizeof(*border);
	Vector3D updatedVerts[player.vertCount];
	Vector3D updatedVertsEnemy[enemy.vertCount];
	float DeltaTime = 0;

}

void LZGLWindow::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key::Key_F)
		if (e->modifiers().testFlag(Qt::ControlModifier))
			if (isFullScreen())
				showNormal();
			else
				showFullScreen();
}

bool LZGLWindow::Initialize()
{
	return profiler.Initialize("Results.txt");
}

void LZGLWindow::initializeGL()
{
	profiler.NextFrame();
	PROFILE("initializeGL");
	GLenum errCode = glewInit();
	assert(errCode == 0);

	// Boundary
	glGenBuffers(1, &boundaryVertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, boundaryVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(border), border, GL_STATIC_DRAW);

	// Indecies
	glGenBuffers(1, &boundaryIVertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, boundaryIVertexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(boundaryVBIndecies), boundaryVBIndecies, GL_STATIC_DRAW);

	// Player
	glGenBuffers(1, &shipVertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, shipVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(player.myVerts), NULL, GL_DYNAMIC_DRAW);

	// Enemy
	glGenBuffers(1, &enemyVertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, enemyVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(enemy.myVerts), NULL, GL_DYNAMIC_DRAW);

	connect(&timer, SIGNAL(timeout()), this, SLOT(UpdateLoop()));
	timer.start(0);
}

void LZGLWindow::UpdatePlayer()
{
	player.lastPosition = player.position;
	player.position += player.velocity * DeltaTime;
}

void LZGLWindow::theUpdate()
{
	profiler.NextFrame();
	PROFILE("theUpdate");
	DeltaTime = FrameTimer::Frame();
	updateRotation();
	updateAcceleration();
	UpdatePlayer();
	bounce();
	handleMiscKeys();
	lerpTheLerper();
}

void LZGLWindow::setupViewport()
{
	PROFILE("Setup Viewport");
	glViewport(0, 0, width(), height());
}

void LZGLWindow::bounce()
{
	for (int i = 0; i < numBoundaryVerts; i++)
	{
		const Vector3D& first = border[i];
		auto ib = (i + 1) % numBoundaryVerts;
		const Vector3D& second = border[ib];

		auto wall = second - first;
		auto normal = wall.perpCcwXy();
		auto resp = player.position - first;
		float dr = normal.dot(resp);
		if (dr < 0)
		{
			player.position = player.lastPosition;
			player.velocity = player.velocity - 2 * player.velocity.projectOnto(normal);
		}
		auto x = i + 1;
	}
	/*if (player.position.x < -1)
	{
		player.position.x = -1;
		player.velocity.x = -player.velocity.x;
	}
	if (player.position.x > 1)
	{
		player.position.x = 1;
		player.velocity.x = -player.velocity.x;
	}
	if (player.position.y < -1)
	{
		player.position.y = -1;
		player.velocity.y = -player.velocity.y;
	}
	if (player.position.y > 1)
	{
		player.position.y = 1;
		player.velocity.y = -player.velocity.y;
	}*/
}

void LZGLWindow::warp()
{
	if (player.position.x < -1)
		player.position.x = 1;
	if (player.position.x > 1)
		player.position.x = -1;

	if (player.position.y < -1)
		player.position.y = 1;
	if (player.position.y > 1)
		player.position.y = -1;
}

void LZGLWindow::handleMiscKeys()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		close();
}

void LZGLWindow::lerpTheLerper()
{
	if (alpha > 1 || lerpStart == lerpEnd)
	{
		lerpStart = (++lerpStart) % lerps;
		lerpEnd = (lerpStart + 1) % lerps;
		switch (lerpStart)
		{
		case 2:
			enemy.rotation = 0;
			break;
		case 3:
			enemy.rotation = LZSoft::Math::PI / 2;
			break;
		case 0:
			enemy.rotation = LZSoft::Math::PI;
			break;
		case 1:
			enemy.rotation = LZSoft::Math::PI / 2 + LZSoft::Math::PI;
			break;
		default:
			enemy.rotation = 0;
			break;
		}

		Vector3D pixelposWorld = enemy.position.normalized();
		//Vector3D pixelposWorld = Vector3D.Normalize(pixelpos - center);
		float dot = Vector3D(1).normalized().dot(pixelposWorld);
		float rotation = (pixelposWorld.y >= 0)
			? (1.f - dot) / 4.f
			: (dot + 3.f) / 4.f;
		//enemy.rotation = rotation;
		alpha = 0;
	}
	else
	{
		float speed = 0.8f*DeltaTime;
		enemy.position = LZSoft::Math::ProMath::lerp(alpha, lerpPoints[lerpStart], lerpPoints[lerpEnd]);
		alpha += speed;
		//qDebug() << alpha;
	}
}

void LZGLWindow::drawGL() //jamie: doGL
{
	setupViewport();

	PROFILE("drawGL");
	glClear(GL_COLOR_BUFFER_BIT);

	// Player
	glBindBuffer(GL_ARRAY_BUFFER, shipVertexBufferID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(updatedVerts), updatedVerts);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Enemy
	glBindBuffer(GL_ARRAY_BUFFER, enemyVertexBufferID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(updatedVertsEnemy), updatedVertsEnemy);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Border
	glBindBuffer(GL_ARRAY_BUFFER, boundaryVertexBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawElements(GL_LINES, 8, GL_UNSIGNED_SHORT, 0);

}

void LZGLWindow::draw()
{
	Matrix2DH m, m2;
	{
		PROFILE("Matrix Multipl");
		const float aspectRatio = static_cast<float>(width()) / height();
		m = Matrix2DH::translate(player.position) * Matrix2DH::scale(1 / aspectRatio, 1) * Matrix2DH::rotateOnZ(player.rotation);
		m2 = Matrix2DH::translate(enemy.position) * Matrix2DH::scale(1 / aspectRatio, 1) * Matrix2DH::rotateOnZ(enemy.rotation);
	}
	{
		PROFILE("Vector transform");
		for (unsigned int i = 0; i < player.vertCount; i++)
			updatedVerts[i] = (m * player.myVerts[i]);
		for (unsigned int i = 0; i < enemy.vertCount; i++)
			updatedVertsEnemy[i] = (m2 * enemy.myVerts[i]);
	}

	drawGL();
}

void LZGLWindow::paintGL()
{
	theUpdate();
	draw();
}

bool LZGLWindow::Shutdown()
{
	return profiler.Shutdown();
}

void LZGLWindow::updateAcceleration()
{
	const float acc = player.acceleration * DeltaTime;
	Vector3D adjAcc(-sin(player.rotation), cos(player.rotation));
	if (GetAsyncKeyState(VK_UP))
		player.velocity += adjAcc * acc;
	if (GetAsyncKeyState(VK_DOWN))
		player.velocity -= adjAcc * acc;

}

void LZGLWindow::updateRotation()
{
	const float AngularMovement = player.angular_acceleration * DeltaTime;
	if (GetAsyncKeyState(VK_RIGHT))
		player.rotation -= AngularMovement;
	if (GetAsyncKeyState(VK_LEFT))
		player.rotation += AngularMovement;
}

void LZGLWindow::Repainter()
{
	repaint();
}

