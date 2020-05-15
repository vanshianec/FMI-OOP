#ifndef __SECTION_CPP
#define __SECTION_CPP

#include "Section.h"

Section::Section() : itemsCount(0), capacity(0) {}

Section::Section(const size_t _capacity) : capacity(_capacity), itemsCount(0) {}

const size_t Section::getCapacity() const
{
	return capacity;
}

const size_t Section::getItemsCount() const
{
	return itemsCount;
}

void Section::addItemsCount(const size_t count)
{
	itemsCount += count;
}

#endif
