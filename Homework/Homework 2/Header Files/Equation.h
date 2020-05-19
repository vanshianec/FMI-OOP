#ifndef _EQUATION_H
#define _EQUATION_H

#include "BaseFormula.h"

class Equation : public BaseFormula
{
public:
	Equation(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result);
	bool isValid() const;
};

#endif