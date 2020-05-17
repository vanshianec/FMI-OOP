#ifndef _FORMULAFACTORY_CPP
#define _FORMULAFACTORY_CPP

#include <vector>
#include "FormulaFactory.h"
#include "ElementFactory.h"
#include "Element.h"

Formula* FormulaFactory::createFormula(const std::string& formula)
{
	std::vector<Element*> parameters;
	std::vector<Element*> result;
	if (formula.find("/") == 0)
	{
		std::string elementType = formula.substr(1);
		parameters.push_back(ElementFactory::createElement(elementType, 1));
		if (elementType == "Philosopher's stone" || elementType == "Earth"
			|| elementType == "Fire" || elementType == "Water" || elementType == "Air")
		{
			result.push_back(ElementFactory::createElement(elementType, 2));
		}
		return new Formula();

	}

	return nullptr;
}

#endif