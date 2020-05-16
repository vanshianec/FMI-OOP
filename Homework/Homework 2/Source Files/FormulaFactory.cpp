#ifndef _FORMULAFACTORY_CPP
#define _FORMULAFACTORY_CPP

#include "FormulaFactory.h"

Formula* FormulaFactory::createFormula(const std::string& formula)
{
	if (formula.find("/") == 0)
	{
		//todo
		return new Formula()
	}
}

#endif