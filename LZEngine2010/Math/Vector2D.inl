Vector2D operator+(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x + right.x, left.y + right.y);
}

Vector2D operator-(const Vector2D& left, const Vector2D& right)
{
	return Vector2D(left.x - right.x, left.y - right.y);
}

Vector2D operator*(float scaler, const Vector2D& vector)
{
	return Vector2D(scaler*vector.x, scaler*vector.y);
}

Vector2D operator*(const Vector2D& vector, float scaler)
{
	return scaler * vector;
}

Vector2D& Vector2D::operator+=(const Vector2D& right)
{
	x += right.x;
	y += right.y;
	return *this;
}

Vector2D& Vector2D::operator-=( const Vector2D& right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

//Vector2D::Vector2D(const Vector2D& source)
//{
//	x = source.x;
//	y = source.y;
//}
//
//Vector2D& Vector2D::operator=(const Vector2D& right)
//{
//	x = right.x;
//	y = right.y;
//	return *this;
//}