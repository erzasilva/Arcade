#ifndef LINE2D_H
#define LINE2D_H

#include "Vec2D.h"


class Line2D
{
private:
	Vec2D P0;
	Vec2D P1;
public:
	Line2D();
	Line2D(float x0, float y0, float x1, float y1);
	Line2D(const Vec2D& V0, const Vec2D& V1);

	inline const Vec2D& GetP0() const { return P0; }
	inline const Vec2D& GetP1() const { return P1; }

	inline void SetP0(const Vec2D& V) { P0 = V; }
	inline void SetP1(const Vec2D& V) { P1 = V; }

	bool operator==(const Line2D& line) const;
	float MinDistFrom(const Vec2D& p, bool limitToSegment = false) const;
	Vec2D ClosestPoint(const Vec2D& p, bool limitToSegment = false) const;

	Vec2D MidPoint() const;
	float Slope() const;
	float Length() const;
};

#endif

