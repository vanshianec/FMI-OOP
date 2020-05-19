#ifndef _EQUATION_CPP
#define _EQUATION_CPP

#include "Equation.h"

Equation::Equation(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result)
	: BaseFormula(_parameters, _result, "Equation") {}

bool Equation::isValid() const
{
	std::vector<Element*> params = this->getParameters();

	/* Example equation : Fire + Air = Stone */

	for (size_t i = 0; i < params.size() - 1; i++)
	{
		if (!(params[i]->reactsWith(params[i + 1])))
		{
			return false;
		}
		if (params[i]->isBaseElement() && params[i + 1]->isBaseElement()
			&& !(params[i + 1]->reactsWith(params[i])))
		{
			return false;
		}
	}

	return true;
}



#endif