#ifndef _SHAPE_CPP
#define _SHAPE_CPP

#include "Shape.h"

Shape::Shape(const double _x, const double _y,
	const std::string& _type, const std::string& _fill) : location(_x, _y)
{
	type = _type;
	fill = _fill;
}

const double Shape::getX() const
{
	return location.getX();
}

const double Shape::getY() const
{
	return location.getY();
}

const std::string& Shape::getType() const
{
	return type;
}

const std::string& Shape::getFill() const
{
	return fill;
}

const Point& Shape::getLocation() const
{
	return location;
}

void Shape::setX(const double _x)
{
	location.setX(_x);
}

void Shape::setY(const double _y)
{
	location.setY(_y);
}

bool Shape::contains(Circle&)
{
	return false;
}

bool Shape::contains(Rectangle&)
{
	return false;
}

bool Shape::contains(Line&)
{
	return false;
}

Shape::~Shape()
{

}

#endif