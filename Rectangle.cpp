#include "Rectangle.h"
#include "Utils.h"

#include <cmath>

Rectangle::Rectangle() : Rectangle(Vec2D::ZERO, Vec2D::ZERO)
{
	
}

Rectangle::Rectangle(const Vec2D& topLeft, unsigned int Width, unsigned int Height)
{
	Points.push_back(topLeft);
	Points.push_back(Vec2D(topLeft.GetX() + (Width - 1), topLeft.GetY() + (Height - 1)));
}

Rectangle::Rectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
	Points.push_back(topLeft);
	Points.push_back(bottomRight);
}

float Rectangle::GetWidth() const
{
	return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float Rectangle::GetHeight() const
{
	return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

void Rectangle::MoveTo(const Vec2D& position)
{
	float w = GetWidth();
	float h = GetHeight();

	SetTopLeftPoint(position);
	SetBottomRightPoint(Vec2D(GetTopLeftPoint().GetX() + w, GetTopLeftPoint().GetY() + h));
}

Vec2D Rectangle::GetCenterPoint() const
{
	return Vec2D((GetTopLeftPoint().GetX() + GetBottomRightPoint().GetX()) / 2, (GetTopLeftPoint().GetY() + GetBottomRightPoint().GetY()) / 2);

}

bool Rectangle::Intersects(const Rectangle& otherRect) const
{
	return !(otherRect.GetBottomRightPoint().GetX() < GetTopLeftPoint().GetX() ||
			otherRect.GetTopLeftPoint().GetX() > GetBottomRightPoint().GetX() ||
			otherRect.GetBottomRightPoint().GetY() < GetTopLeftPoint().GetY() ||
			otherRect.GetTopLeftPoint().GetY() > GetBottomRightPoint().GetY());
}

bool Rectangle::ContainsPoint(const Vec2D& point) const
{
	bool Xaxis = point.GetX() >= GetTopLeftPoint().GetX() && point.GetX() <= GetBottomRightPoint().GetX();
	bool Yaxis = point.GetY() >= GetTopLeftPoint().GetY() && point.GetY() <= GetBottomRightPoint().GetY();

	return Xaxis && Yaxis;
}

Rectangle Rectangle::Inset(const Rectangle& rect, Vec2D& insets)
{
	return Rectangle(rect.GetTopLeftPoint() + insets, rect.GetBottomRightPoint() - insets);
}

std::vector<Vec2D> Rectangle::GetPoints() const
{
	std::vector<Vec2D> Temp;
	Temp.push_back(GetTopLeftPoint());
	Temp.push_back(Vec2D(GetBottomRightPoint().GetX(), GetTopLeftPoint().GetY()));
	Temp.push_back(GetBottomRightPoint());
	Temp.push_back(Vec2D(GetTopLeftPoint().GetX(), GetBottomRightPoint().GetY()));

	return Temp;
}