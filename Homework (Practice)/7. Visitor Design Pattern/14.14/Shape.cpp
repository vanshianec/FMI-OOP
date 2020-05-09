#ifndef _SHAPE_CPP
#define _SHAPE_CPP

#include "Shape.h"

Shape::Shape() : x(0), y(0), text(nullptr) {}

Shape::Shape(int _x, int _y, const char* _text) : x(_x), y(_y)
{
	setText(_text);
}

Shape::Shape(const Shape& other)
{
	x = other.x;
	y = other.y;
	setText(other.text);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		setText(other.text);
	}

	return *this;
}

const int Shape::getX() const
{
	return x;
}

const int Shape::getY() const
{
	return y;
}

const char* Shape::getText() const
{
	return text;
}

void Shape::setX(int _x)
{
	x = _x;
}

void Shape::setY(int _y)
{
	y = _y;
}

void Shape::setText(const char* _text)
{
	if (_text != nullptr)
	{
		size_t len = strlen(_text);
		text = new char[len + 1];
		strcpy_s(text, len + 1, _text);
	}
}

Shape::~Shape()
{

}

#endif