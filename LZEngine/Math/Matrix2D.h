#pragma once
#include "Vector2D.h"
#include "Vector3D.h"

float cosf(float);
float sinf(float);
namespace LZSoft
{
	namespace Math
	{
		struct Matrix2D
		{
			float r0c0, r0c1, r1c0, r1c1;
			inline explicit Matrix2D(float r0c0 = 1, float r0c1 = 0, float r1c0 = 0, float r1c1 = 1) : r0c0(r0c0), r0c1(r0c1), r1c0(r1c0), r1c1(r1c1) {}
			inline static Matrix2D rotate(float angle);
		};

		inline Vector2D operator*(const Matrix2D& left, const Vector2D& right);
		inline Vector3D operator*(const Matrix2D& left, const Vector3D& right);

#include "Matrix2D.inl"
	}

}