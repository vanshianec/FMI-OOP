#ifndef _SPLITTER_CPP
#define _SPLITTER_CPP

#include "Splitter.h"

void Splitter::processRectangle(Rectangle* rect)
{
	rectangles.push_back(rect);
}

void Splitter::processCircle(Circle* circle)
{
	circles.push_back(circle);
}

void Splitter::processGroup(Group* group)
{
	size_t size = group->getNChildren();
	for (size_t i = 0; i < size; i++)
	{
		group->getChild(i)->accept(this);
	}
}

std::vector<Circle*> Splitter::getCircles()
{
	return circles;
}

std::vector<Rectangle*> Splitter::getRectangles()
{
	return rectangles;
}

#endif