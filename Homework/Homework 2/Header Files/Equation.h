#ifndef _EQUATION_H
#define _EQUATION_H

#include "Formula.h"

class Equation : public Formula
{
public:
	Equation(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result);
	bool isValid() const;
};

#endif