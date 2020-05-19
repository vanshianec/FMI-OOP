#ifndef _PHILOSOPHERSSTONE_CPP
#define _PHILOSOPHERSSTONE_CPP

#include "PhilosophersStone.h"

PhilosophersStone::PhilosophersStone(const size_t _amount)
	: Element(_amount, "Philosopher's Stone") {}

bool PhilosophersStone::reactsWith(Element* other)
{
	return false;
}

const std::vector<Element*> PhilosophersStone::baseElements() const
{
	std::vector<Element*> noComposingElements;
	return noComposingElements;
}

bool PhilosophersStone::isBaseElement() const
{
	return true;
}

bool PhilosophersStone::composedReactsWith(Element* _this, Element* other)
{
	if (other->isBaseElement())
	{
		return other->reactsWith(_this);
	}

	std::vector<Element*> baseElements = _this->baseElements();

	for (Element* baseElement : baseElements)
	{
		if (!baseElement->reactsWith(other))
		{
			return false;
		}
	}

	return true;
}

bool PhilosophersStone::baseReactsWith(Element* _this, Element* other)
{
	std::vector<Element*>baseElements = other->baseElements();

	for (Element* baseElement : baseElements)
	{
		if (!_this->reactsWith(baseElement))
		{
			return false;
		}
	}

	return true;
}

#endif