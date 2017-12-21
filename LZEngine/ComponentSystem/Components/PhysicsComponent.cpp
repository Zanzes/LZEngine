#include "PhysicsComponent.h"
#include <ComponentSystem/GameObject.h>
#include <Timing/GameTime.h>


namespace LZSoft
{
	namespace ComponentSystem
	{
		void PhysicsComponent::update()
		{
			velocity += acceleration*DeltaTime;
			acceleration = Math::Vector3D::Zero();
			getGameObject()->position += velocity * DeltaTime;
			getGameObject()->orientation += angularVelocity * DeltaTime;
		}
	}
}
