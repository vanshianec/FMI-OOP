#ifndef _ENERGY_CPP
#define _ENERGY_CPP

#include "Energy.h"

Energy::Energy(const size_t _amount)
	: Water(0), Air(0), PhilosophersStone(0), Element(_amount, "Energy") {}

bool Energy::reactsWith(Element* other)
{
	return composedReactsWith(this, other);
}

const std::vector<Element*> Energy::baseElements() const
{
	std::vector<Element*> elements;
	elements.push_back(new Water(1));
	elements.push_back(new Air(1));
	return elements;
}

bool Energy::isBaseElement() const
{
	return false;
}

#endif