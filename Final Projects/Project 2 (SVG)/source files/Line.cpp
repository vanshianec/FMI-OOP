#ifndef _LINE_CPP
#define _LINE_CPP

#include "Line.h"
#include "Visitor.h"

Line::Line(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, const double _xEnd, const double _yEnd)
	: Shape(_x, _y, _type, _fill), endLocation(_xEnd, _yEnd) {}

void Line::accept(Visitor* visitor)
{
	visitor->processLine(*this);
}

bool Line::isInside(Shape* shape)
{
	return shape->contains(*this);
}

const double Line::getXEnd() const
{
	return endLocation.getX();
}

const double Line::getYEnd() const
{
	return endLocation.getY();
}

const Point& Line::getEndLocation() const
{
	return endLocation;
}

void Line::setXEnd(const double _xEnd)
{
	endLocation.setX(_xEnd);
}

void Line::setYEnd(const double _yEnd)
{
	endLocation.setY(_yEnd);
}

#endif