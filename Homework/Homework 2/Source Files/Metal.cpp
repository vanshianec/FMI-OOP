#ifndef _METAL_CPP
#define _METAL_CPP

#include "Metal.h"

Metal::Metal(const size_t _amount)
	: Earth(0), Fire(0), PhilosophersStone(0), Element(_amount, "Metal") {}

bool Metal::reactsWith(Element* other)
{
	return composedReactsWith(this, other);
}

const std::vector<Element*> Metal::baseElements() const
{
	std::vector<Element*> elements;
	elements.push_back(new Earth(1));
	elements.push_back(new Fire(1));
	return elements;
}

bool Metal::isBaseElement() const
{
	return false;
}

#endif