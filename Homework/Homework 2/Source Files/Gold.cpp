#ifndef _GOLD_CPP
#define _GOLD_CPP

#include "Gold.h"

Gold::Gold(const size_t _amount)
	: Metal(0), PhilosophersStone(0), Element(_amount, "Gold") {}

bool Gold::reactsWith(Element* other)
{
	Element* baseElement = &(Metal(1));
	return composedReactsWith(other, baseElement);
}

const std::vector<Element*> Gold::baseElements() const
{
	std::vector<Element*> elements;
	elements.push_back(new Metal(1));
	return elements;
}

bool Gold::isBaseElement() const
{
	return false;
}

#endif