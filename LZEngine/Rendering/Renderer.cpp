#include <gl/glew.h>
#include "Renderer.h"
#include "Geometry.h"
#include <Math/Matrix2DH.h>
#include <cassert>

namespace LZSoft
{
	namespace Rendering
	{
		bool Renderer::initialize()
		{
			vertexBufferID = -1;
			indexBufferID = -1;

			numGeometries = 0;
			numRenderables = 0;
			show();
			return numGeometries == 0 && numRenderables == 0;
		}

		void Renderer::initializeGL()
		{
			GLenum status = glewInit();
			assert(status == 0);
			glClearColor(0, 0, 0, 1);

			glGenBuffers(1, &vertexBufferID);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
			glBufferData(GL_ARRAY_BUFFER, MAX_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glGenBuffers(1, &indexBufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		}

		bool Renderer::shutdown()
		{
			if (vertexBufferID != -1)
				glDeleteBuffers(1, &vertexBufferID);
			if (indexBufferID != -1)
				glDeleteBuffers(1, &indexBufferID);
			return true;
		}

		Geometry* Renderer::addGeometry(Math::Vector3D* vertices, const int numVertices, const unsigned short * const indices, const unsigned numIndices, const GLenum drawMode)
		{
			assert(numGeometries != MAX_GEOMETRY);
			assert(numVertices <= MAX_VERTICES);
			Geometry& g = geometries[numGeometries++];
			g.vertices = vertices;
			g.numVertices = numVertices;
			g.indices = indices;
			g.numIndices = numIndices;
			g.drawMode = drawMode;

			return &g;
		}

		Renderable* Renderer::addRenderable(Geometry* geometry)
		{
			assert(numRenderables != MAX_RENDERABLE);
			Renderable& r = renderables[numRenderables++];
			r.what = geometry;

			return &r;
		}

		void Renderer::renderBuffers()
		{
			glDraw();
		}

		Math::Matrix2DH Renderer::getAspectRationMatriox() const
		{
			const float ratio = static_cast<float>(width()) / height();

			if (ratio > 1)
				return Math::Matrix2DH::scale(1 / ratio, 1);
			return Math::Matrix2DH::scale(1, ratio);
		}

		void Renderer::paintEvent()
		{		}

		void Renderer::paintGL()
		{
			glClear(GL_COLOR_BUFFER_BIT);

			Math::Vector3D transformedVerts[MAX_VERTICES];

			for (uint j = 0; j < numRenderables; j++)
			{
				Renderable& r = renderables[j];

				glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(unsigned short)* r.what->numIndices, r.what->indices);

				const Math::Matrix2DH ajusted = getAspectRationMatriox() * r.where;

				for (int i = 0; i < r.what->numVertices; i++)
				{
					transformedVerts[i] = ajusted * r.what->vertices[i];
				}

					glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Math::Vector3D)*r.what->numVertices, transformedVerts);
					glDrawElements(r.what->drawMode, r.what->numIndices, GL_UNSIGNED_SHORT, 0);
			}
		}
	}
}
