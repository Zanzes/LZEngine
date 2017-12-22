#pragma once
#include <Rendering/Renderer.h>
#include <QtOpenGL/QGLWidget>
#include <Qt/qtimer.h>
#include <ComponentSystem/GameObject.h>
#include <ComponentSystem/Components/RendererComponent.h>
#include <ComponentSystem/Components/PhysicsComponent.h>
#include <ComponentSystem/Components/ColiderComponent.h>
#include <Input/NewKeyMapper.h>
#include <Components/ControllerComponent.h>

namespace LZSoft
{

	namespace Rendering { class Renderable; }

	class MyGame : public QObject
	{
		Q_OBJECT
			
		QTimer timer;

		Input::NewKeyMapper keyMapper;

		Rendering::Renderer renderer;

		ComponentSystem::GameObject Player;
		ComponentSystem::RendererComponent PlayerRenderer;
		Rendering::Renderable* playerRenderable;
		ComponentSystem::PhysicsComponent PlayerPhysics;
		ComponentSystem::ControllerComponent PlayerControler;
		ComponentSystem::ColiderComponent PlayerColider;

		ComponentSystem::GameObject Border;
		ComponentSystem::RendererComponent BorderRenderer;
		Rendering::Renderable* borderRenderable;
		
		static const int PLAYER_VERT_COUNT = 3;
		Math::Vector3D playerVerts[PLAYER_VERT_COUNT];
		static const int PLAYER_INDICES_COUNT = 3;
		unsigned short playerIndices[PLAYER_INDICES_COUNT];

		static const int BORDER_VERT_COUNT = 4;
		Math::Vector3D borderVerts[BORDER_VERT_COUNT];
		static const int BORDER_INDICES_COUNT = 8;
		unsigned short borderIndices[BORDER_INDICES_COUNT];

		bool initializePlayer();
		bool initializeBorder();
	private slots:
		void update();
	public:
		MyGame() {};
		bool initialize();
		bool shutdown();
		void go();
	};
}
