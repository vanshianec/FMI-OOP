#ifndef _SPIRIT_CPP
#define _SPIRIT_CPP

#include "Spirit.h"

Spirit::Spirit(const size_t _amount)
	: Air(0), PhilosophersStone(0), Element(_amount, "Spirit") {}

bool Spirit::reactsWith(Element* other)
{
	return composedReactsWith(this, other);
}

const std::vector<Element*> Spirit::baseElements() const
{
	std::vector<Element*> elements;
	elements.push_back(new Air(1));
	return elements;
}

bool Spirit::isBaseElement() const
{
	return false;
}

#endif