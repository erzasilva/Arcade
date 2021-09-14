#ifndef SHAPE_H
#define SHAPE_H

#include "Vec2D.h"
#include <vector>

class Shape
{
protected:
	std::vector<Vec2D> Points;
public:
	virtual Vec2D GetCenterPoint() const = 0;
	virtual ~Shape() {}
	inline virtual std::vector<Vec2D> GetPoints() const { return Points; }
	void MoveBy(const Vec2D& deltaOffset);

};

#endif
