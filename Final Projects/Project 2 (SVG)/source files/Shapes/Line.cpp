#ifndef _LINE_CPP
#define _LINE_CPP

#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "Visitor.h"

Line::Line(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, const double _xEnd, const double _yEnd)
	: Shape(_x, _y, _type, _fill), endLocation(_xEnd, _yEnd) {}

/**
*   @brief Applies modifications to this object with the help of a visitor object.
*
*	@param visitor A visitor object which will modify the current object.
*/

void Line::accept(Visitor* visitor)
{
	visitor->processLine(*this);
}

/**
*   @brief Checks if the current object is inside of another shape object.
*
*	@param shape A shape object which will check if it contains the current object.
*
*   @return Returns true if the current object is inside the other shape object or false otherwise.
*/

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