#pragma once
#include <ComponentSystem/Component.h>
#include <Math/Vector3D.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		class PhysicsComponent;
		class __declspec(dllexport) ColiderComponent : public Component
		{
			int BORDER_VERT_COUNT;
			const Math::Vector3D* borderVerts;

			PhysicsComponent* physics;
			Math::Vector3D lastPosition;
		public:
			ColiderComponent();
			bool initialize() override;
			void update() override;
			void setData(Math::Vector3D* borderVerts, int vertCount);
		};
	}
}

