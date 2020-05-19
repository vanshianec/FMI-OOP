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

bool Alchemist::removedElement(Element* param)
{
	for (size_t i = 0; i < elements.size(); i++)
	{
		if (elements[i]->getType() == param->getType())
		{
			elements[i]->setAmount(elements[i]->getAmount() - param->getAmount());

			if (elements[i]->getAmount() <= 0)
			{
				elements.erase(elements.begin() + i);
			}

			return true;
		}
	}

	return false;
}

bool Alchemist::canCreatePhilosophersStone()
{
	std::vector<BaseFormula*> philosophersStoneFormulas = book.filter();

	if (philosophersStoneFormulas.empty())
	{
		return false;
	}

	for (BaseFormula* formula : philosophersStoneFormulas)
	{
		for (Element* param : formula->getParameters())
		{ 
			/* If the alchemist does not have the required element, he can't craft the stone*/
			if (!removedElement(param))
			{
				return false;
			}
		}

		for (Element* result : formula->getResult())
		{
			elements.push_back(result);
		}
	}

	return true;
}

#endif