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

bool Alchemist::removedElement(Element* param, std::vector<Element*>& requiredElements)
{
	for (size_t i = 0; i < requiredElements.size(); i++)
	{
		if (requiredElements[i]->getType() == param->getType())
		{
			requiredElements[i]->setAmount(requiredElements[i]->getAmount() - param->getAmount());

			if (requiredElements[i]->getAmount() <= 0)
			{
				requiredElements.erase(requiredElements.begin() + i);
			}

			return true;
		}
	}

	return false;
}

bool Alchemist::canCreatePhilosophersStone()
{
	std::vector<Formula*> philosophersStoneFormulas = book.filter();
	std::vector<Element*> requiredElements = elements;

	if (philosophersStoneFormulas.empty())
	{
		return false;
	}

	for (Formula* formula : philosophersStoneFormulas)
	{
		for (Element* param : formula->getParameters())
		{
			/* If the alchemist does not have the required element, he can't craft the stone*/
			if (!removedElement(param, requiredElements))
			{
				return false;
			}
		}

		for (Element* result : formula->getResult())
		{
			requiredElements.push_back(result);
		}
	}

	for (Formula* f : philosophersStoneFormulas)
	{
		if (f->getParameters().size() > 0 && f->getResult().size() > 0)
		{
			delete f;
		}
	}

	return true;
}

Alchemist::~Alchemist()
{
	for (Element* el : elements)
	{
		if (el != nullptr)
		{
			delete el;
			el = nullptr;
		}
	}
}

#endif