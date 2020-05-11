#ifndef _RECTANGLE_CPP
#define _RECTANGLE_CPP

#include "Rectangle.h"
#include "Visitor.h"

Rectangle::Rectangle(const double _x, const double _y, const std::string& _fill,
	const double _height, const double _width) : Shape(_x, _y, _fill)
{
	height = _height;
	width = _width;
}

void Rectangle::accept(Visitor* visitor)
{
	visitor->processRectangle(*this);
}

const double Rectangle::getHeight() const
{
	return height;
}

const double Rectangle::getWidth() const
{
	return width;
}

#endif