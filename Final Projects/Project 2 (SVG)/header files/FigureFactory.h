#ifndef _FIGUREFACTORY_H
#define _FIGUREFACTORY_H

#include <string>
#include "Shape.h"

class FigureFactory
{
public:
	static Shape* create(const std::string& type);
};

#endif