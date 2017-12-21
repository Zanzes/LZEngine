#pragma once
#include <ComponentSystem/Component.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		class PhysicsComponent;
		class ControllerComponent : public Component
		{
			PhysicsComponent* physics;
		public:
			void update() override;
			bool initialize() override;
		};
	}
}
