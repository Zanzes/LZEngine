#include "MyGame.h"
#include <ComponentSystem/Components/RendererComponent.h>
#include <ComponentSystem/Components/ColiderComponent.h>
#include <Input/KeyInput.h>
#include "InputActions.h"
#include <Timing/GameTime.h>

using LZSoft::Rendering::Geometry;
using LZSoft::Rendering::Renderable;
using LZSoft::Math::Vector3D;
using LZSoft::Timing::GameTime;

namespace LZSoft
{
	bool MyGame::initializePlayer()
	{
		Vector3D pVerts[] = { Vector3D(+0.0f, +0.1f, +1.f),Vector3D(-0.1f, -0.1f, +1.f),Vector3D(+0.1f, -0.1f, +1.f) };
		memcpy(playerVerts, pVerts, sizeof pVerts);
		ushort pi[] = { 0,1,2 };
		memcpy(playerIndices, pi, sizeof pi);

		Player.addComponent(&PlayerPhysics);
		Player.addComponent(&PlayerControler);
		PlayerColider.setData(borderVerts, BORDER_VERT_COUNT);
		Player.addComponent(&PlayerColider);


		Geometry* playerGeometry = renderer.addGeometry(playerVerts, PLAYER_VERT_COUNT, playerIndices, PLAYER_INDICES_COUNT);
		playerRenderable = renderer.addRenderable(playerGeometry);

		PlayerRenderer.setData(playerRenderable);
		Player.addComponent(&PlayerRenderer);

		return Player.initialize();
	}

	bool MyGame::initializeBorder()
	{
		Vector3D bVerts[] = 
		{ 
			Vector3D(+0.0f, +1.0f, +0.0f),
			Vector3D(-1.0f, +0.0f, +0.0f),
			Vector3D(+0.0f, -1.0f, +0.0f),
			Vector3D(+1.0f, +0.0f, +0.0f)
		};
		memcpy(borderVerts, bVerts, sizeof bVerts);
		ushort bi[] = { 0,1,1,2,2,3,3,0 };
		memcpy(borderIndices, bi, sizeof bi);

		Geometry* borderGeometry = renderer.addGeometry(borderVerts, BORDER_VERT_COUNT, borderIndices, BORDER_INDICES_COUNT, GL_LINES);
		borderRenderable = renderer.addRenderable(borderGeometry);

		BorderRenderer.setData(borderRenderable);
		Border.addComponent(&BorderRenderer);

		return Border.initialize();
	}

	bool MyGame::initialize()
	{
		if (!renderer.initialize())
			return false;
		if (!input.initialize(&keyMapper, Input::InputActions::Max))
			return false;
		if (!initializePlayer())
			return false;
		if (!initializeBorder())
			return false;
		
		if (!connect(&timer, SIGNAL(timeout()), this, SLOT(update())))
			return false;
		timer.start(0);

		return true;
	}

	bool MyGame::shutdown()
	{
		bool r = true;
		r &= Border.shutdown();
		r &= Player.shutdown();
		r &= input.shutdown();
		r &= renderer.shutdown();
		return r;
	}

	void MyGame::go()
	{
	}

	void MyGame::update()
	{
		/*playerRenderable->where = Math::Matrix2DH::translate(pla);*/
		GameTime::getInstance().update();
		input.update();
		Player.update();
		renderer.renderBuffers();
	}
}