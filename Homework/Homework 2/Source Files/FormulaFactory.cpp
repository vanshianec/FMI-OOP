#ifndef _FORMULAFACTORY_CPP
#define _FORMULAFACTORY_CPP

#include "FormulaFactory.h"
#include "ElementDivision.h"
#include "Equation.h"

Formula* FormulaFactory::createFormula(const std::vector<Element*>& parameters,
	const std::vector<Element*>& result)
{
	if (parameters.size() == 1 && result.size() == 2)
	{
		return new ElementDivision(parameters, result);
	}
	else if (result.size() == 1)
	{
		return new Equation(parameters, result);
	}

	return nullptr;
}

#endif