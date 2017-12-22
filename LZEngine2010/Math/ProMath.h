#pragma once
#include <Math/Vector3D.h>

using LZSoft::Math::Vector3D;

namespace LZSoft
{
	namespace Math
	{
		class ProMath
		{
		public:
			static Vector3D lerp(const float α,const Vector3D& a, const Vector3D& b);
		};

		inline Vector3D ProMath::lerp(const float α,const Vector3D& a, const Vector3D& b)
		{
			return ((1 - α)*a) + (α*b);
		}
	}
}