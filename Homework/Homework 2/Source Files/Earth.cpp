#ifndef _EARTH_CPP
#define _EARTH_CPP

#include "Earth.h"

Earth::Earth(const size_t _amount)
	: PhilosophersStone(0), Element(_amount, "Earth") {}

bool Earth::reactsWith(Element* other)
{
	std::string otherType = other->getType();
	if (other->isBaseElement())
	{
		return (otherType == "Fire" || otherType == "Air" || otherType == "Water");		
	}

	return baseReactsWith(this, other);
}

const std::vector<Element*> Earth::composingElements() const
{
	std::vector<Element*> noComposingElements;
	return noComposingElements;
}

bool Earth::isBaseElement() const
{
	return true;
}

#endif