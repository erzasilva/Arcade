#include "Circle.h"
#include "Utils.h"

Circle::Circle(): Circle(Vec2D::ZERO, 0)
{

}

Circle::Circle(const Vec2D& center, float radius)
{
	Radius = radius;
	Points.push_back(center);
}


bool Circle::Intersects(const Circle& otherCircle) const
{
	return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < (Radius + otherCircle.GetRadius());
}
bool Circle::ContainsPoint(const Vec2D& point) const
{
	return IsLesserThanOrEqual(GetCenterPoint().Distance(point), Radius);
}