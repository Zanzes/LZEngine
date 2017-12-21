#include "RendererComponent.h"
#include <ComponentSystem/GameObject.h>
#include <Math/Matrix2DH.h>

namespace LZSoft
{
	namespace ComponentSystem
	{
		void RendererComponent::setData(Rendering::Renderable* renderable)
		{
			this->renderable = renderable;
		}

		void RendererComponent::update()
		{
			renderable->where = Math::Matrix2DH::translate(getGameObject()->position) * Math::Matrix2DH::rotateOnZ(getGameObject()->orientation);
		}
	}
}