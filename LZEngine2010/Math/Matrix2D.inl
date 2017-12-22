inline Vector2D operator*(const Matrix2D& matrix, const Vector2D& vector)
{
	return Vector2D(matrix.r0c0*vector.x + matrix.r0c1*vector.y, matrix.r1c0*vector.x + matrix.r1c1*vector.y);
}

inline Matrix2D Matrix2D::rotate(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	return Matrix2D(c, -s, s, c);
}

inline Vector3D operator*(const Matrix2D& matrix, const Vector3D& vector)
{
	return Vector3D(matrix.r0c0*vector.x + matrix.r0c1*vector.y, matrix.r1c0*vector.x + matrix.r1c1*vector.y,vector.z);
}