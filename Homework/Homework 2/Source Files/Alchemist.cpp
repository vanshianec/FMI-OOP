#ifndef _ALCHEMIST_CPP
#define _ALCHEMIST_CPP

#include "Alchemist.h"

void Alchemist::setBook(const Book& other)
{
	book = other;
}

void Alchemist::addElement(Element* element)
{
	if (element != nullptr)
	{
		elements.push_back(element);
	}
}

#endif