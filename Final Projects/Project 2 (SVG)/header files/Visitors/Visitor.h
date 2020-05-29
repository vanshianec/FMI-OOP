#ifndef _VISITOR_H
#define _VISITOR_H

#include "Circle.h"
#include "Rect.h"
#include "Line.h"

/// @brief Abstract class using the visitor design pattern to process different shape types.

class Visitor
{
public:
	virtual void processCircle(Circle&) = 0;
	virtual void processRectangle(Rect&) = 0;
	virtual void processLine(Line&) = 0;
};

#endif