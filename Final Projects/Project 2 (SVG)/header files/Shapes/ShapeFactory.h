#ifndef _FIGUREFACTORY_H
#define _FIGUREFACTORY_H

#include <string>
#include <vector>
#include "Shape.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"

///@brief Class used to create shape objects.

class ShapeFactory
{
public:
	///@brief Creates a shape object from a specified shape type and shape paramaters.
	static Shape* create(const std::string& type, const std::vector<std::string>& params);
	///@brief Creates an xml node from a specified shape
	static const pugi::xml_node createNode(Shape* shape, pugi::xml_node& node);
};

#endif