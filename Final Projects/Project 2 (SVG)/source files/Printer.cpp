#ifndef _PRINTER_CPP
#define _PRINTER_CPP

#include <iostream>
#include "Printer.h"

void Printer::processCircle(Circle& circle)
{
	std::cout << "circle " << circle.getX() << " " << circle.getY() << circle.getRadius
		<< " " << circle.getFill() << std::endl;
}

void Printer::processRectangle(Rectangle& rectangle)
{
	std::cout << "rectangle " << rectangle.getX() << " " << rectangle.getY()
		<< " " << rectangle.getHeight() << " " << rectangle.getWidth()
		<< " " << rectangle.getFill() << std::endl;
}

void Printer::processLine(Line& line)
{
	std::cout << "line " << line.getX() << " " << line.getY() << " " << line.getXEnd()
		<< " " << line.getYEnd() << " " << line.getFill() << std::endl;
}

#endif