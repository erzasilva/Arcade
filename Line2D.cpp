#include "Line2D.h"
#include "Vec2D.h"
#include "Utils.h"
#include <cmath>

Line2D::Line2D() : Line2D(Vec2D::ZERO, Vec2D::ZERO){}

Line2D::Line2D(float x0, float y0, float x1, float y1): Line2D(Vec2D(x0, y0), Vec2D(x1, y1)){}

Line2D::Line2D(const Vec2D& V0, const Vec2D& V1) : P0(V0), P1(V1){}

bool Line2D::operator==(const Line2D& oLine) const
{
	return oLine.GetP0() == P0 && oLine.GetP1() == P1;
}

float Line2D::MinDistFrom(const Vec2D& p, bool limitToSegment) const
{
	return p.Distance(ClosestPoint(p, limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& p, bool limitToSegment) const
{
	Vec2D P0toP = p - P0;
	Vec2D P0toP1 = P1 - P0;

	float l2 = P0toP.Mag2();

	float dot = P0toP.Dot(P0toP1);

	float t = dot / l2;

	if (limitToSegment)
	{
		t = std::fmaxf(0, std::fminf(1.0f, t));
	}

	return P0 + P0toP1 * t;

}

Vec2D Line2D::MidPoint() const
{
	return Vec2D((P0.GetX() + P1.GetX()) / 2.0f, (P0.GetY() + P1.GetY()) / 2.0f);
}

float Line2D::Slope() const
{
	float dx = P1.GetX() - P0.GetX();
	float dy = P1.GetY() - P1.GetY();
	if (fabsf(dx) < EPSILON)
	{
		return 0;
	}

	return dy / dx;
}

float Line2D::Length() const
{
	return P1.Distance(P0);
}