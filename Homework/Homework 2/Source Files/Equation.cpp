#ifndef _EQUATION_CPP
#define _EQUATION_CPP

#include "Equation.h"

Equation::Equation(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result)
	: Formula(_parameters, _result, "Equation") {}

bool Equation::isValid() const
{
	std::vector<Element*> params = this->getParameters();

	/* Example equation : Fire + Air + Earth = Stone */

	for (size_t i = 0; i < params.size() - 1; i++)
	{
		for (size_t j = i + 1; j < params.size(); j++)
		{
			if (!(params[i]->reactsWith(params[j])))
			{
				return false;
			}
		}
	}

	return true;
}



#endif