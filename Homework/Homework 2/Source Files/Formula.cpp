#ifndef _FORMULA_CPP
#define _FORMULA_CPP

#include "Formula.h"

Formula::Formula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result
	, const std::string& _type) : parameters(_parameters), result(_result), type(_type), used(false) {}


const std::vector<Element*>& Formula::getResult() const
{
	return result;
}

const std::vector<Element*>& Formula::getParameters() const
{
	return parameters;
}

const std::string& Formula::getType() const
{
	return type;
}

bool Formula::isUsed() const
{
	return used;
}

void Formula::setUsed(bool _used)
{
	used = _used;
}

Formula::~Formula()
{
	for (Element* el : parameters)
	{
		if (el != nullptr)
		{
			delete el;
			el = nullptr;
		}
	}

	for (Element* el : result)
	{
		if (el != nullptr)
		{
			delete el;
			el = nullptr;
		}
	}
}

#endif