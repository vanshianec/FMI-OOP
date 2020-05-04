#ifndef __SECTION_CPP
#define __SECTION_CPP

#include "Section.h"

Section::Section() : id(0), currentItemsCount(0), shelfsCount(0), capacity(0) {}

Section::Section(size_t _id, size_t _currentItemsCount, size_t _shelfsCount, size_t _capacity)
{
	id = _id;
	currentItemsCount = _currentItemsCount;
	shelfsCount = _shelfsCount;
	capacity = _capacity;
}

const size_t Section::getCapacity() const
{
	return capacity;
}

#endif
