#ifndef _FORMULA_H
#define _FORMULA_H

#include "BaseFormula.h"

class Formula : public BaseFormula
{
public:
	Formula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result);
	bool isValid() const;
};

#endif