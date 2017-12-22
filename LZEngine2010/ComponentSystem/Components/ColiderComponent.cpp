#include "ColiderComponent.h"
#include <ComponentSystem/Components/PhysicsComponent.h>
#include <ComponentSystem/GameObject.h>
#include <Math/Vector3D.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		ColiderComponent::ColiderComponent()
		{
			physics = nullptr;
			borderVerts = nullptr;
		}

		bool ColiderComponent::initialize()
		{
			physics = getGameObject()->getComponent<PhysicsComponent>();
			return physics != nullptr && borderVerts != nullptr;
		}

		void ColiderComponent::update()
		{
			for (int i = 0; i < BORDER_VERT_COUNT; i++)
			{
				const Math::Vector3D& first = borderVerts[i];
				const Math::Vector3D& second = borderVerts[(i + 1) % BORDER_VERT_COUNT];

				Math::Vector3D wall = second - first;
				Math::Vector3D normal = wall.perpCcwXy();
				const Math::Vector3D shipRSP = getGameObject()->position - first;
				const float dotRes = normal.dot(shipRSP);

				if (dotRes < 0)
				{
					physics->velocity = physics->velocity - 2 * physics->velocity.projectOnto(normal);
					getGameObject()->position = lastPosition;
				}
			}

			lastPosition = getGameObject()->position;
		}

		void ColiderComponent::setData(Math::Vector3D* borderVerts, int vertCount)
		{
			this->borderVerts = borderVerts;
			BORDER_VERT_COUNT = vertCount;
		}
	}
}