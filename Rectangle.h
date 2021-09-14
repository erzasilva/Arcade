#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    Rectangle();
    Rectangle(const Vec2D& topLeft, unsigned int Width, unsigned int Height);
    Rectangle(const Vec2D& topLeft, const Vec2D& bottomRight);

    inline void SetTopLeftPoint(const Vec2D& topLeft) { Points[0] = topLeft; }
    inline void SetBottomRightPOint(const Vec2D& bottomRight) { Points[1] = bottomRight; }

    inline Vec2D GetTopLeftPoint() const { return Points[0]; }
    inline Vec2D GetBottomRightPoint() const { return Points[1]; }

    float GetWidth() const;
    float GetHeight() const;

    void MoveTo(const Vec2D& position);

    virtual Vec2D GetCenterPoint() const override;

    bool Intersects(const Rectangle& otherRect) const;
    bool ContainsPoint(const Vec2D& point) const;

    static Rectangle Inset(const Rectangle& rect, Vec2D& insets);

    virtual std::vector<Vec2D> GetPoints() const override;



};

#endif

