#pragma once
namespace LZSoft
{
	namespace Math
	{
		struct Vector2D
		{
			float x;
			float y;
			explicit Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
			inline Vector2D& operator += (const Vector2D& right);
			inline Vector2D& operator -= (const Vector2D& right);
			//inline Vector2D(const Vector2D& source);
			//inline Vector2D& operator = (const Vector2D& right);
		};

		inline Vector2D operator+(const Vector2D& left, const Vector2D& right);
		inline Vector2D operator-(const Vector2D& left, const Vector2D& right);
		inline Vector2D operator*(float scaler, const Vector2D& vector);
		inline Vector2D operator*(const Vector2D& vector, float scaler);

#include "Vector2D.inl"
	}
}