#ifndef _FORMULA_CPP
#define _FORMULA_CPP

#include "Formula.h"

Formula::Formula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result)
	: BaseFormula(_parameters, _result, "Formula") {}

bool Formula::isValid() const
{
	std::string type = getParameters()[0]->getType();
	return type == "Philosopher's Stone" || type == "Fire" || type == "Water"
		|| type == "Earth" || type == "Air" || type == "Spirit" || type == "Metal"
		|| type == "Stone" || type == "Energy" || type == "Gold";
}

#endif