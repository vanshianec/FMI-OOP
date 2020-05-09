#ifndef _CIRCLE_CPP
#define _CIRCLE_CPP

#include "Circle.h"
#include "Visitor.h"

Circle::Circle(int x, int y, const char* text, double _r) : Shape(x, y, text)
{
	r = _r;
}

Shape* Circle::clone()
{
	return new Circle(*this);
}

void Circle::accept(Visitor* visitor)
{
	visitor->processCircle(this);
}

const double Circle::getRadius() const
{
	return r;
}
void Circle::setRadius(const double _r)
{
	r = _r;
}

Circle::~Circle()
{
	std::cout << "Circle destructor" << std::endl;
	if (text != nullptr)
	{
		delete[]text;
	}
}

#endif