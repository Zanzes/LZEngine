Vector3D operator+(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3D operator-(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3D operator*(float scaler, const Vector3D& vector)
{
	return Vector3D(scaler*vector.x, scaler*vector.y, scaler*vector.z);
}

Vector3D operator*(const Vector3D& vector, float scaler)
{
	return scaler * vector;
}

Vector3D& Vector3D::operator+=(const Vector3D& right)
{
	x += right.x;
	y += right.y;
	z += right.z;
	return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;
	return *this;
}

Vector3D Vector3D::perpCwXy() const
{
	return Vector3D(y, -x);
}

Vector3D Vector3D::perpCcwXy() const
{
	return Vector3D(-y, x);
}

float Vector3D::dot(const Vector3D& victim) const
{
	return x * victim.x + y * victim.y + z * victim.z;
}

float Vector3D::magnitude() const
{
	return sqrt(this->dot(*this));
}

float Vector3D::magnitudeSquared() const
{
	return this->dot(*this);
}

Vector3D Vector3D::normalized() const
{
	auto mag = 1.f / magnitude();
	return mag * (*this);
}

Vector3D Vector3D::projectOnto(const Vector3D& target) const
{
	return this->dot(target) / target.magnitudeSquared() * target;
}

float Vector3D::GetAngle(const Vector3D& target) const
{
	return (*this).dot(target) / ((*this).magnitude() * target.magnitude());
}

static const Vector3D zerox;

inline Vector3D Vector3D::Zero()
{
	return zerox;
}