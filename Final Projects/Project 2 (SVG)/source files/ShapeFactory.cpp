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

#endif