#ifndef _FIGUREFACTORY_CPP
#define _FIGUREFACTORY_CPP

#include <iostream>
#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "StringTrimmer.h"

Shape* ShapeFactory::create(const std::string& type)
{
	double x, y;
	std::string fill;
	std::cin >> x >> y;
	if (type == "circle")
	{
		double radius;
		std::cin >> radius;
		std::getline(std::cin, fill);
		StringTrimmer::trim(fill);
		return new Circle(x, y, type, fill, radius);
	}
	else if (type == "rectangle")
	{
		double width, height;
		std::cin >> width >> height;
		std::getline(std::cin, fill);
		StringTrimmer::trim(fill);
		return new Rectangle(x, y, type, fill, width, height);
	}
	else if (type == "line")
	{
		double xEnd, yEnd;
		std::cin >> xEnd >> yEnd;
		std::getline(std::cin, fill);
		StringTrimmer::trim(fill);
		return new Line(x, y, type, fill, xEnd, yEnd);
	}

	std::cout << "Invalid shape!" << std::endl;
	return nullptr;
}

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
	else if (type == "rectangle")
	{
		double width = std::stoi(params[2]);
		double height = std::stoi(params[3]);
		fill = params[4];
		return new Rectangle(x, y, type, fill, width, height);
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
		node.append_attribute("width") = ((Rectangle*)shape)->getWidth();
		node.append_attribute("height") = ((Rectangle*)shape)->getHeight();
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