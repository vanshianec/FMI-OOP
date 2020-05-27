#ifndef _ELEMENTDIVISION_H
#define _ELEMENTDIVISION_H

#include "Formula.h"

class ElementDivision : public Formula
{
public:
	ElementDivision(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result);
	bool isValid() const;
};

#endif