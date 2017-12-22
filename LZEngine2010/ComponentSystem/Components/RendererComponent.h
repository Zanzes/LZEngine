#pragma once
#include <ComponentSystem/Component.h>
#include <Rendering/Renderable.h>

namespace LZSoft
{
	namespace Rendering	{ class Renderable;	}
	namespace ComponentSystem
	{
		class __declspec(dllexport) RendererComponent : public Component
		{
			Rendering::Renderable* renderable;
		public:
			void setData(Rendering::Renderable* renderable);
			void update() override;
		};
	}
}
