#ifndef _WATER_CPP
#define _WATER_CPP

#include "Water.h"

Water::Water(const size_t _amount)
	: PhilosophersStone(0), Element(_amount, "Water") {}

bool Water::reactsWith(Element* other)
{
	std::string otherType = other->getType();
	if (other->isBaseElement())
	{
		return (otherType == "Fire" || otherType == "Air");
	}

	return baseReactsWith(this, other);
}

const std::vector<Element*> Water::baseElements() const
{
	return std::vector<Element*>();
}

bool Water::isBaseElement() const
{
	return true;
}

#endif