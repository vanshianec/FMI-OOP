#ifndef _FORMULAFACTORY_H
#define _FORMULAFACTORY_H

#include <string>
#include "Formula.h"

class FormulaFactory
{
public:
	static Formula* createFormula(const std::string& formula);
};

#endif