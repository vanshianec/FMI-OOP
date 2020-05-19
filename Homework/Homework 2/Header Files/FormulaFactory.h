#ifndef _FORMULAFACTORY_H
#define _FORMULAFACTORY_H

#include <string>
#include "BaseFormula.h"

class FormulaFactory
{
public:
	static BaseFormula* createFormula(const std::vector<Element*>& parameters,
		const std::vector<Element*>& result);
};

#endif