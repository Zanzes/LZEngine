#include "Matrix2DH.h"
inline Matrix2DH Matrix2DH::rotateOnZ(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return Matrix2DH(
		c, -s, 0,
		s, c, 0
	);
}

inline Matrix2DH Matrix2DH::translate(const Vector3D vector)
{
	return Matrix2DH(
		1, 0, vector.x,
		0, 1, vector.y
	);
}

inline Matrix2DH Math::Matrix2DH::scale(const float x, const float y)
{
	return Matrix2DH(
		x,0,0,
		0,y,0
	);
}

inline Matrix2DH operator*(const Matrix2DH& left, const Matrix2DH& right)
{
	return Matrix2DH(
		left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0,
		left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1,
		left.r0c0 * right.r0c2 + left.r0c1 * right.r1c2 + left.r0c2,

		left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0,
		left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1,
		left.r1c0 * right.r0c2 + left.r1c1 * right.r1c2 + left.r1c2
	);
}

inline Vector3D operator*(const Matrix2DH& matrix, const Vector3D& vector)
{
	return Vector3D(
		matrix.r0c0 * vector.x + matrix.r0c1 * vector.y + matrix.r0c2 * vector.z,
		matrix.r1c0 * vector.x + matrix.r1c1 * vector.y + matrix.r1c2 * vector.z,
		vector.z
	);
}

inline Vector3D operator*(const Vector3D& vector, const Matrix2DH& matrix)
{
	return matrix * vector;
}