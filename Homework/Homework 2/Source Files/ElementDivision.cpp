#ifndef _ELEMENTDIVISION_CPP
#define _ELEMENTDIVISION_CPP

#include "ElementDivision.h"

ElementDivision::ElementDivision(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result)
	: Formula(_parameters, _result, "Formula") {}

bool ElementDivision::isValid() const
{
	std::string type = getParameters()[0]->getType();
	return type == "Philosopher's Stone" || type == "Fire" || type == "Water"
		|| type == "Earth" || type == "Air" || type == "Spirit" || type == "Metal"
		|| type == "Stone" || type == "Energy" || type == "Gold";
}

#endif