#include "ControllerComponent.h"
#include <Input/KeyInput.h>
#include <Input/InputActions.h>
#include <ComponentSystem/GameObject.h>
#include <Math/Vector3D.h>
#include <ComponentSystem/Components/PhysicsComponent.h>
#include <Timing/GameTime.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		void ControllerComponent::update()
		{
			float speed = 0.7f;

			if (input.keyDown(Input::Accelerate))
			{
				physics->acceleration.x += -sin(getGameObject()->orientation)*speed;
				physics->acceleration.y += cos(getGameObject()->orientation)*speed;
			}
			if (input.keyDown(Input::Break))
			{
				physics->acceleration.x -= -sin(getGameObject()->orientation)*speed;
				physics->acceleration.y -= cos(getGameObject()->orientation)*speed;
			}
			if (input.keyDown(Input::RotateRight))
				getGameObject()->orientation -= 0.07f;
				//physics->angularVelocity += 0.01f;
			if (input.keyDown(Input::RorateLeft))
				getGameObject()->orientation += 0.07f;
		}

		bool ControllerComponent::initialize()
		{
			physics = getGameObject()->getComponent<PhysicsComponent>();
			return physics != 0;
		}
	}
}
