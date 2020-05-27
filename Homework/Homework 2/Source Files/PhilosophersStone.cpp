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
	std::vector<Element*> otherBaseElements = other->baseElements();
	bool reacts;

	for (Element* baseElement : baseElements)
	{
		reacts = true;

		for (Element* otherBaseElement : otherBaseElements)
		{
			if (!baseElement->reactsWith(otherBaseElement))
			{
				reacts = false;
				break;
			}
		}

		if (reacts)
		{
			clearData(baseElements);
			clearData(otherBaseElements);
			return true;
		}
	}

	clearData(baseElements);
	clearData(otherBaseElements);
	return false;
}

bool PhilosophersStone::baseReactsWith(Element* _this, Element* other)
{
	std::vector<Element*>baseElements = other->baseElements();

	for (Element* baseElement : baseElements)
	{
		if (!_this->reactsWith(baseElement))
		{
			clearData(baseElements);
			return false;
		}
	}

	clearData(baseElements);
	return true;
}

void PhilosophersStone::clearData(std::vector<Element*>& data) const
{
	for (Element* el : data)
	{
		delete el;
	}
}

#endif