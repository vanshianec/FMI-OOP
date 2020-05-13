#ifndef _PRINTER_CPP
#define _PRINTER_CPP

#include <iostream>
#include "Printer.h"

void Printer::processCircle(Circle& circle)
{
	std::cout << circle.getType() << " " << circle.getX() << " " << circle.getY() << " "
		<< circle.getRadius() << " " << circle.getFill();
}


void Printer::processRectangle(Rectangle& rectangle)
{
	std::cout << rectangle.getType() << " " << rectangle.getX() << " " << rectangle.getY()
		<< " " << rectangle.getWidth() << " " << rectangle.getHeight() << " " << rectangle.getFill();
}

void Printer::processLine(Line& line)
{
	std::cout << line.getType() << " " << line.getX() << " " << line.getY() << " "
		<< line.getXEnd() << " " << line.getYEnd() << " " << line.getFill();
}

#endif