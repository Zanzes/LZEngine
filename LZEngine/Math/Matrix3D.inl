inline Matrix3D Matrix3D::rotateOnZ(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return Matrix3D(
		c, -s, 0,
		s, c, 0,
		0, 0, 1);
}

inline Matrix3D Matrix3D::translate(const Vector3D vector)
{
	return Matrix3D(
		1, 0, vector.x,
		0, 1, vector.y,
		0, 0, 1);
}

inline Matrix3D Matrix3D::scale(const float x, const float y)
{
	
	return Matrix3D(
		x, 0, 0,
		0, y, 0,
		0, 0, 1);
}

inline Matrix3D operator*(const Matrix3D& left, const Matrix3D& right)
{
	return Matrix3D(
		left.r0c0 * right.r0c0 + left.r0c1 * right.r1c0 + left.r0c2 * right.r2c0,
		left.r0c0 * right.r0c1 + left.r0c1 * right.r1c1 + left.r0c2 * right.r2c1,
		left.r0c0 * right.r0c2 + left.r0c1 * right.r1c2 + left.r0c2 * right.r2c2,

		left.r1c0 * right.r0c0 + left.r1c1 * right.r1c0 + left.r1c2 * right.r2c0,
		left.r1c0 * right.r0c1 + left.r1c1 * right.r1c1 + left.r1c2 * right.r2c1,
		left.r1c0 * right.r0c2 + left.r1c1 * right.r1c2 + left.r1c2 * right.r2c2,

		left.r2c0 * right.r0c0 + left.r2c1 * right.r1c0 + left.r2c2 * right.r2c0,
		left.r2c0 * right.r0c1 + left.r2c1 * right.r1c1 + left.r2c2 * right.r2c1,
		left.r2c0 * right.r0c2 + left.r2c1 * right.r1c2 + left.r2c2 * right.r2c2
	);
}

inline Vector3D operator*(const Matrix3D& matrix, const Vector3D& vector)
{
	return Vector3D(
		matrix.r0c0 * vector.x + matrix.r0c1 * vector.y + matrix.r0c2 * vector.z,
		matrix.r1c0 * vector.x + matrix.r1c1 * vector.y + matrix.r1c2 * vector.z,
		matrix.r2c0 * vector.x + matrix.r2c1 * vector.y + matrix.r2c2 * vector.z);
}

inline Vector3D operator*(const Vector3D& vector, const Matrix3D& matrix)
{
	return matrix * vector;
}