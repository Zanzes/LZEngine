#pragma once
#include <ComponentSystem/Component.h>
#include "Math/Vector3D.h"

namespace LZSoft
{
	namespace ComponentSystem
	{
		class __declspec(dllexport) PhysicsComponent : public Component
		{
		public:
			Math::Vector3D velocity;
			Math::Vector3D acceleration;
			void update() override;
			float angularVelocity;
			PhysicsComponent() :angularVelocity(0){};
		};

	}
}
