#pragma once
#include <Rendering/Renderable.h>
#include <Rendering/Geometry.h>
#include <QtOpenGL/qgl.h>

namespace LZSoft
{
	namespace Math { struct Vector3D; }
	namespace Rendering
	{
		class __declspec(dllexport) Renderer : public QGLWidget
		{
			friend class Renderable;
		private:
			static const int MAX_GEOMETRY = 10;
			Geometry geometries[MAX_GEOMETRY];
			uint numGeometries;

			static const int MAX_RENDERABLE = 10;
			Renderable renderables[MAX_RENDERABLE];
			uint numRenderables;

			static const int MAX_BUFFER_SIZE = 1024;

			GLuint vertexBufferID;
			GLuint indexBufferID;

			static const int MAX_VERTICES = 10;
			Math::Matrix2DH getAspectRationMatriox() const;
		protected:
			void initializeGL();
			void paintEvent();
			void paintGL();
		public:
			bool initialize();
			bool shutdown();
			Geometry* addGeometry(Math::Vector3D* vertices, const int numVertices, const unsigned short* indices, const unsigned numIndices, GLenum drawMode = GL_TRIANGLES);
			Renderable* addRenderable(Geometry* geometry);
			void renderBuffers();
		};
	}
}
