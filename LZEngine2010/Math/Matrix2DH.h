#pragma once
#include "Vector3D.h"
#include "Vector2D.h"

float cosf(float);
float sinf(float);
namespace LZSoft
{
	namespace Math
	{
		struct Matrix2DH
		{
			float r0c0, r0c1, r0c2, r1c0, r1c1, r1c2;
			inline explicit Matrix2DH(
				float r0c0 = 1, float r0c1 = 0, float r0c2 = 0,
				float r1c0 = 0, float r1c1 = 1, float r1c2 = 0) :
				r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
				r1c0(r1c0), r1c1(r1c1), r1c2(r1c2) {}
			inline static Matrix2DH rotateOnZ(float angle);
			inline static Matrix2DH translate(const Vector3D vector);
			inline static Matrix2DH scale(const float x, const float y);
		};

		inline Matrix2DH operator*(const Matrix2DH& left, const Matrix2DH& right);
		inline Vector3D operator*(const Matrix2DH& left, const Vector3D& right);
		inline Vector3D operator*(const Vector3D& right, const Matrix2DH& left);

#include "Matrix2DH.inl"
	}

}