#ifndef _ELEMENT_CPP
#define _ELEMENT_CPP

#include "Element.h"

Element::Element(const size_t _amount, const std::string& _type) : amount(_amount), type(_type) {}


const std::string& Element::getType() const
{
	return type;
}

const size_t Element::getAmount() const
{
	return amount;
}

void Element::setAmount(const size_t _amount)
{
	amount = _amount;
}

Element::~Element()
{

}

#endif