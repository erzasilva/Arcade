#include "Vec2D.h"
#include "Utils.h"

#include <cassert>
#include <cmath>

const Vec2D Vec2D::ZERO;

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec)
{
	std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
	return consoleOut;
}

Vec2D operator*(float scale, Vec2D& V1)
{
	return V1 * scale;
}

bool Vec2D::operator==(const Vec2D& V2) const
{
	return IsEqual(mX, V2.mX) && IsEqual(mY, V2.mY);
}

bool Vec2D::operator!=(const Vec2D& V2) const
{
	return !(*this == V2);
}

Vec2D Vec2D::operator-() const
{
	return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator*(float scale) const
{
	return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const
{
	assert(fabsf(scale) > EPSILON);
	return Vec2D(mX / scale, mY / scale);
}

Vec2D& Vec2D::operator*=(float scale)
{
	*this = *this * scale;
	return *this;
}

Vec2D& Vec2D::operator/=(float scale)
{
	assert(fabsf(scale) > EPSILON);
	*this = *this / scale;
	return *this;
}

Vec2D Vec2D::operator+(const Vec2D& V2) const
{
	return Vec2D(mX + V2.mX, mY + V2.mY);
}
Vec2D Vec2D::operator-(const Vec2D& V2) const
{
	return Vec2D(mX - V2.mX, mY - V2.mY);
}
Vec2D& Vec2D::operator+=(const Vec2D& V2)
{
	*this = *this + V2;
	return *this;
}
Vec2D& Vec2D::operator-=(const Vec2D& V2)
{
	*this = *this - V2;
	return *this;
}


float Vec2D::Mag2() const
{
	return (mX * mX) + (mY * mY);
}
float Vec2D::Mag() const
{
	return sqrtf(Mag2());

}

Vec2D Vec2D::GetUnitVec() const
{
	float mag = Mag();
	if (mag > EPSILON)
	{
		return *this / mag;
	}
	return Vec2D::ZERO;

}

Vec2D& Vec2D::Normalize()
{
	float mag = Mag();
	if (mag > EPSILON)
	{
		*this /= mag;
	}
	return *this;
}

float Vec2D::Distance(const Vec2D& V2) const
{
	return (V2 - *this).Mag();
}

float Vec2D::Dot(const Vec2D& V2) const
{
	return ((mX * V2.mX) + (mY * V2.mY));
}

Vec2D Vec2D::ProjectOnto(const Vec2D& V2) const
{
	Vec2D uVec = V2.GetUnitVec();
	
	float dot = Dot(uVec);

	return uVec * dot;
}

float Vec2D::AngleBetween(const Vec2D& V2) const
{
	return acosf(GetUnitVec().Dot(V2.GetUnitVec()));
}

Vec2D Vec2D::Reflect(const Vec2D& normal) const
{
	return (*this - (ProjectOnto(normal) * 2.0f));
}


void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D Rot = Vec2D(xRot, yRot);

	*this = Rot + aroundPoint;
}

Vec2D Vec2D::RotationResult(float angle, const Vec2D& aroundPoint) const
{

	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vec2D thisVec(mX, mY);

	thisVec -= aroundPoint;

	float xRot = thisVec.mX * cosine - thisVec.mY * sine;
	float yRot = thisVec.mX * sine + thisVec.mY * cosine;

	Vec2D Rot = Vec2D(xRot, yRot);

	return Rot + aroundPoint;

}

