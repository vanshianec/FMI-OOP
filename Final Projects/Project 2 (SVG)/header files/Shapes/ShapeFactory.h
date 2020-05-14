#ifndef _FIGUREFACTORY_H
#define _FIGUREFACTORY_H

#include <string>
#include <vector>
#include "Shape.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"

class ShapeFactory
{
public:
	static Shape* create(const std::string& type);
	static Shape* create(const std::string& type, const std::vector<std::string>& params);
	static const pugi::xml_node createNode(Shape* shape, pugi::xml_node& node);
};

#endif