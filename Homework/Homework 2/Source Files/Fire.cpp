#ifndef _FIRE_CPP
#define _FIRE_CPP

#include "Fire.h"

Fire::Fire(const size_t _amount)
	: PhilosophersStone(0), Element(_amount, "Fire") {}

bool Fire::reactsWith(Element* other)
{
	std::string otherType = other->getType();
	if (other->isBaseElement())
	{
		return (otherType == "Fire" || otherType == "Earth" || otherType == "Water");		
	}

	return baseReactsWith(this, other);
}

const std::vector<Element*> Fire::baseElements() const
{
	return std::vector<Element*>();
}

bool Fire::isBaseElement() const
{
	return true;
}

#endif