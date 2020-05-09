#ifndef _RECTANGLE_CPP
#define _RECTANGLE_CPP

#include "Rectangle.h"
#include "Visitor.h"

Rectangle::Rectangle(int x, int y, const char* text, double w, double h) : Shape(x, y, text)
{
	width = w;
	height = h;
}

Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

void Rectangle::accept(Visitor* visitor)
{
	visitor->processRectangle(this);
}

const double Rectangle::getWidth() const
{
	return width;
}
const double Rectangle::getHeight() const
{
	return height;
}
void Rectangle::setWidth(const double _width)
{
	width = _width;
}
void Rectangle::setHeight(const double _height)
{
	height = _height;
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle destructor" << std::endl;

	if (text != nullptr)
	{
		delete[]text;
	}
}

#endif