#include "Triangle.h"
#include "Utils.h"
#include <cmath>


Triangle::Triangle(): Triangle(Vec2D::ZERO, Vec2D::ZERO, Vec2D::ZERO) {}

Triangle::Triangle(const Vec2D& P0, const Vec2D& P1, const Vec2D& P2)
{
	Points.push_back(P0);
	Points.push_back(P1);
	Points.push_back(P2);

}


Vec2D Triangle::GetCenterPoint() const
{
	return Vec2D((Points[0].GetX() + Points[1].GetX() + Points[2].GetX()) / 3, (Points[0].GetY() + Points[1].GetY() + Points[2].GetY()) / 3);
}

float Triangle::Area() const
{
	return Area(GetP0(), GetP1(), GetP2());
}

bool Triangle::ContainsPoint(const Vec2D& point) const
{
	float thisArea = Area();

	float a1 = Area(GetP0(), GetP1(), point);
	float a2 = Area(GetP0(), point, GetP2());
	float a3 = Area(point, GetP1(), GetP2());



	return IsEqual(thisArea, (a1 + a2 + a3));
}

float Triangle::Area(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2) const
{
	return fabsf((p0.GetX() * (p1.GetY() - p2.GetY()) + p1.GetX() * (p2.GetY() - p0.GetY()) + p2.GetX() * (p0.GetY() - p1.GetY())) / 2.0f);
}
