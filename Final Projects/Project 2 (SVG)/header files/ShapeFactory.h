#ifndef _FIGUREFACTORY_H
#define _FIGUREFACTORY_H

#include <string>
#include "Shape.h"

class ShapeFactory
{
public:
	static Shape* create(const std::string& type);
};

#endif