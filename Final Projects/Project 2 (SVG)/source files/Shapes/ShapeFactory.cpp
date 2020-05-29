#ifndef _FIGUREFACTORY_CPP
#define _FIGUREFACTORY_CPP

#include <iostream>
#include "ShapeFactory.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "StringTrimmer.h"

/**
*   @brief Creates a shape object.
*
*	@param type The type of shape to be created.
*	@param params The parameters of the specified shape object.
*
*	@return  The newly created shape object or nullptr if the type was invalid.
*/

Shape* ShapeFactory::create(const std::string& type, const std::vector<std::string>& params)
{
	double x = std::stoi(params[0]);
	double y = std::stoi(params[1]);
	std::string fill;

	if (type == "circle")
	{
		double radius = std::stoi(params[2]);
		fill = params[3];
		return new Circle(x, y, type, fill, radius);
	}
	else if (type == "rect")
	{
		double width = std::stoi(params[2]);
		double height = std::stoi(params[3]);
		fill = params[4];
		return new Rect(x, y, type, fill, width, height);
	}
	else if (type == "line")
	{
		double xEnd = std::stoi(params[2]);
		double yEnd = std::stoi(params[3]);
		fill = params[4];
		return new Line(x, y, type, fill, xEnd, yEnd);
	}

	return nullptr;
}

/**
*   @brief Creates an xml node object.
*
*	@param shape The shape to be converted as an xml object.
*	@param node The xml node to which the newly created shape node will be appended.
*
*	@return  The newly created xml node from the shape.
*/

const pugi::xml_node ShapeFactory::createNode(Shape* shape, pugi::xml_node& node)
{
	node.append_attribute("x") = shape->getX();
	node.append_attribute("y") = shape->getY();
	std::string type = shape->getType();

	if (type == "circle")
	{
		node.append_attribute("r") = ((Circle*)shape)->getRadius();
	}
	else if (type == "rectangle")
	{
		node.append_attribute("width") = ((Rect*)shape)->getWidth();
		node.append_attribute("height") = ((Rect*)shape)->getHeight();
	}
	else if (type == "line")
	{
		node.append_attribute("xEnd") = ((Line*)shape)->getXEnd();
		node.append_attribute("yEnd") = ((Line*)shape)->getYEnd();
	}

	node.append_attribute("fill") = shape->getFill().c_str();

	return node;
}

#endif