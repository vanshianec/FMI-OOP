#ifndef _SHAPE_CPP
#define _SHAPE_CPP

#include "Shape.h"

Shape::Shape(const double _x, const double _y, const std::string& _fill)
{
	x = _x;
	y = _y;
	fill = _fill;
}

const double Shape::getX() const
{
	return x;
}
const double Shape::getY() const
{
	return y;
}
const std::string& Shape::getFill() const
{
	return fill;
}

#endif