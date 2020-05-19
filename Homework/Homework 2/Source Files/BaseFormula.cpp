#ifndef _BASEFORMULA_CPP
#define _BASEFORMULA_CPP

#include "BaseFormula.h"

BaseFormula::BaseFormula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result
	, const std::string& _type) : parameters(_parameters), result(_result), type(_type), used(false) {}


const std::vector<Element*>& BaseFormula::getResult() const
{
	return result;
}

const std::vector<Element*>& BaseFormula::getParameters() const
{
	return parameters;
}

const std::string& BaseFormula::getType() const
{
	return type;
}

bool BaseFormula::isUsed() const
{
	return used;
}

void BaseFormula::setUsed(bool _used)
{
	used = _used;
}

#endif