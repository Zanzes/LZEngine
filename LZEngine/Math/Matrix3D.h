#pragma once
#include "Vector3D.h"
#include "Vector2D.h"

float cosf(float);
float sinf(float);
namespace LZSoft
{
	namespace Math
	{
		struct Matrix3D
		{
			float r0c0, r0c1, r0c2, r1c0, r1c1, r1c2, r2c0, r2c1, r2c2;
			inline explicit Matrix3D(
				float r0c0 = 1, float r0c1 = 0, float r0c2 = 0,
				float r1c0 = 0, float r1c1 = 1, float r1c2 = 0,
				float r2c0 = 0, float r2c1 = 0, float r2c2 = 1) :
				r0c0(r0c0), r0c1(r0c1), r0c2(r0c2),
				r1c0(r1c0), r1c1(r1c1), r1c2(r1c2),
				r2c0(r2c0), r2c1(r2c1), r2c2(r2c2) {}
			inline static Matrix3D rotateOnZ(float angle);
			inline static Matrix3D translate(const Vector3D vector);
			inline static Matrix3D scale(const float width, const float height);
		};

		inline Matrix3D operator*(const Matrix3D& left, const Matrix3D& right);
		inline Vector3D operator*(const Matrix3D& left , const Vector3D& right);
		inline Vector3D operator*(const Vector3D& right, const Matrix3D& left );

#include "Matrix3D.inl"
	}

}