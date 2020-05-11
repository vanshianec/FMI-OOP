#ifndef _LINE_CPP
#define _LINE_CPP

#include "Line.h"
#include "Visitor.h"

Line::Line(const double _x, const double _y, const std::string& _fill,
	const double _xEnd, const double _yEnd) : Shape(_x, _y, _fill)
{
	xEnd = _xEnd;
	yEnd = _yEnd;
}

void Line::accept(Visitor* visitor)
{
	visitor->processLine(*this);
}

const double Line::getXEnd() const
{
	return xEnd;
}

const double Line::getYEnd() const
{
	return yEnd;
}

#endif