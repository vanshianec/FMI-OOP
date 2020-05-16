#ifndef _ELEMENTFACTORY_H
#define _ELEMENTFACTORY_H

#include <string>
#include "Element.h"

class ElementFactory
{
public:
	static Element* createElement(const std::string& type, const size_t amount);
};

#endif