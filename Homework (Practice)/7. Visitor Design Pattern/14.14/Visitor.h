#ifndef _VISITOR_H
#define _VISITOR_H

#include "Group.h"
#include "Circle.h"
#include "Rectangle.h"

class Visitor
{
public:
	virtual void processRectangle(Rectangle*) = 0;
	virtual void processCircle(Circle*) = 0;
	virtual void processGroup(Group*) = 0;
	virtual std::vector<Circle*> getCircles() = 0;
	virtual std::vector<Rectangle*> getRectangles() = 0;
};

#endif