#ifndef _VISITOR_H
#define _VISITOR_H

#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

class Visitor
{
public:
	virtual void processCircle(Circle&) = 0;
	virtual void processRectangle(Rectangle&) = 0;
	virtual void processLine(Line&) = 0;
};

#endif