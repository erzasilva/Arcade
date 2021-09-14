#include "Rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(const Vec2D& topLeft, unsigned int Width, unsigned int Height)
{

}

Rectangle::Rectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{

}

float Rectangle::GetWidth() const
{

}

float Rectangle::GetHeight() const
{

}

void Rectangle::MoveTo(const Vec2D& position)
{

}

Vec2D Rectangle::GetCenterPoint() const
{

}

bool Rectangle::Intersects(const Rectangle& otherRect) const
{

}

bool Rectangle::ContainsPoint(const Vec2D& point) const
{

}

Rectangle Rectangle::Inset(const Rectangle& rect, Vec2D& insets)
{

}

std::vector<Vec2D> Rectangle::GetPoints() const
{

}