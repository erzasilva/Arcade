#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"



class Circle :
    public Shape
{
public:
    Circle();
    Circle(const Vec2D& center, float radius);

    virtual Vec2D GetCenterPoint() const override { return Points[0]; }
    inline float GetRadius() const { return Radius; }
    inline void SetRadius(float r) { Radius = r; }

    void MoveTo(const Vec2D& position) { Points[0] = position; }

    bool Intersects(const Circle& otherCircle) const;
    bool ContainsPoint(const Vec2D& point) const;

private:
    float Radius;
};

#endif

