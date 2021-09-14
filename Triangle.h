#ifndef TRAINGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle :
    public Shape
{
public:
    Triangle();
    Triangle(const Vec2D& P0, const Vec2D& P1, const Vec2D& P2);

    inline void SetP0(const Vec2D& p0) { Points[0] = p0; }
    inline void SetP1(const Vec2D& p1) { Points[1] = p1; }
    inline void SetP2(const Vec2D& p2) { Points[2] = p2; }

    inline Vec2D GetP0() const { return Points[0]; }
    inline Vec2D GetP1() const { return Points[1]; }
    inline Vec2D GetP2() const { return Points[2]; }

    virtual Vec2D GetCenterPoint() const override;

    float Area() const;

    bool ContainsPoint(const Vec2D& point) const;
private:
    float Area(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2) const;
};

#endif

