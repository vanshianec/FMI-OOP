#ifndef _CIRCLE_CPP
#define _CIRCLE_CPP

#include "Circle.h"
#include "Visitor.h"

Circle::Circle(const double _x, const double _y, const std::string& _fill, double _radius)
	: Shape(_x, _y, _fill)
{
	radius = _radius;
}

void Circle::accept(Visitor* visitor)
{
	visitor->processCircle(*this);
}

const double Circle::getRadius() const
{
	return radius;
}

#endif