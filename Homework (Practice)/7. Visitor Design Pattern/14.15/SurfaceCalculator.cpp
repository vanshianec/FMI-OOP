#ifndef _CALCULATOR_CPP
#define _CALCULATOR_CPP

#include "SurfaceCalculator.h"

SurfaceCalculator::SurfaceCalculator() : sum(0) {}

void SurfaceCalculator::processRectangle(Rectangle* rect)
{
	sum += rect->getHeight() * rect->getWidth();
}

void SurfaceCalculator::processCircle(Circle* circle)
{
	sum += 3.14 * circle->getRadius() * circle->getRadius();
}

void SurfaceCalculator::processGroup(Group* group)
{
	size_t size = group->getNChildren();

	for (size_t i = 0; i < size; i++)
	{
		group->getChild(i)->accept(this);
	}
}

double SurfaceCalculator::getSum()
{
	return sum;
}

#endif 