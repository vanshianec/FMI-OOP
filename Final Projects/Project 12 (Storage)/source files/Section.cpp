#ifndef __SECTION_CPP
#define __SECTION_CPP

#include "Section.h"

Section::Section() : itemsCount(0), capacity(0) {}

Section::Section(size_t _itemsCount, size_t _capacity)
{
	itemsCount = _itemsCount;
	capacity = _capacity;
}

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
