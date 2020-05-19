#ifndef _STONE_CPP
#define _STONE_CPP

#include "Stone.h"

Stone::Stone(const size_t _amount)
	: Fire(0), Water(0), PhilosophersStone(0), Element(_amount, "Stone") {}

bool Stone::reactsWith(Element* other)
{
	return composedReactsWith(this, other);
}

const std::vector<Element*> Stone::baseElements() const
{
	std::vector<Element*> elements;
	elements.push_back(new Water(1));
	elements.push_back(new Fire(1));
	return elements;
}

bool Stone::isBaseElement() const
{
	return false;
}

#endif