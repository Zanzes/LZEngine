#pragma once
#include <Math/Matrix2DH.h>
#include <ComponentSystem/Components/RendererComponent.h>

namespace LZSoft
{
	namespace Rendering
	{
		class Geometry;
		class Renderable
		{
			friend class Renderer;
			const Geometry* what;
		public:
			Math::Matrix2DH where;
		};
	}
}
