#pragma once

#include <cmath>
#include <cassert>
#include <typeinfo>
#include <QtCore/QDebug>

namespace LZSoft
{
	namespace Math
	{
		struct __declspec(dllexport) Vector3D
		{
			float x;
			float y;
			float z;
			explicit Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}
			inline Vector3D& operator += (const Vector3D& right);
			inline Vector3D& operator -= (const Vector3D& right);
			inline Vector3D perpCwXy() const;
			inline Vector3D perpCcwXy() const;
			inline float dot(const Vector3D& victim) const;
			inline float magnitude() const;
			inline float magnitudeSquared() const;
			inline Vector3D normalized() const;
			inline Vector3D projectOnto(const Vector3D& target) const;
			inline float GetAngle(const Vector3D& target) const;
			inline static Vector3D Zero();
		};

		inline Vector3D operator+(const Vector3D& left, const Vector3D& right);
		inline Vector3D operator-(const Vector3D& left, const Vector3D& right);
		inline Vector3D operator*(float scaler, const Vector3D& vector);
		inline Vector3D operator*(const Vector3D& vector, float scaler);
		
#include "Vector3D.inl"
	}
}