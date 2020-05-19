#ifndef _AIR_CPP
#define _AIR_CPP

#include "Air.h"

Air::Air(const size_t _amount)
	: PhilosophersStone(0), Element(_amount, "Air") {}

bool Air::reactsWith(Element* other)
{
	std::string otherType = other->getType();
	if (other->isBaseElement())
	{
		return (otherType == "Fire" || otherType == "Air" || otherType == "Earth" || otherType == "Water");
	}

	return baseReactsWith(this, other);
}

const std::vector<Element*> Air::baseElements() const
{
	std::vector<Element*> noBaseElements;
	return noBaseElements;
}

bool Air::isBaseElement() const
{
	return true;
}

#endif