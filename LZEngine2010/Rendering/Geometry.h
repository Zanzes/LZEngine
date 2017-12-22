#pragma once
#include "Renderable.h"

namespace LZSoft
{
	namespace Rendering
	{
		typedef unsigned int GLenum;

		class Geometry
		{
		public:
			const Math::Vector3D* vertices;
			int numVertices;
			const unsigned short* indices;
			int numIndices;
			GLenum drawMode;
		};
	}
}