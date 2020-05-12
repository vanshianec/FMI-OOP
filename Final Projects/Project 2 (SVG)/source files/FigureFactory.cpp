#ifndef _FIGUREFACTORY_CPP
#define _FIGUREFACTORY_CPP

#include <iostream>
#include "FigureFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

Shape* FigureFactory::create(const std::string& type)
{
	double x, y;
	std::string fill;
	std::cin >> x >> y;
	std::cin >> fill;
	if (type == "circle")
	{
		double radius;
		std::cin >> radius;
		return new Circle(x, y, fill, radius);
	}
	else if (type == "rectangle")
	{
		double height, width;
		std::cin >> height >> width;
		return new Rectangle(x, y, fill, height, width);
	}
	else if (type == "line")
	{
		double xEnd, yEnd;
		std::cin >> xEnd >> yEnd;
		return new Line(x, y, fill, xEnd, yEnd);
	}

	std::cout << "Invalid shape!" << std::endl;
	return nullptr;
}

#endif