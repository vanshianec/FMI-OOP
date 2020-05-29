#ifndef _PRINTER_CPP
#define _PRINTER_CPP

#include <iostream>
#include "Printer.h"

/**
*   @brief Prints a circle object.
*
*   @param circle The circle object to be printed.
*/

void Printer::processCircle(Circle& circle)
{
	std::cout << circle.getType() << " " << circle.getX() << " " << circle.getY() << " "
		<< circle.getRadius() << " " << circle.getFill();
}

/**
*   @brief Prints a rectangle object.
*
*   @param rect The rectangle object to be printed.
*/

void Printer::processRectangle(Rect& rect)
{
	std::cout << rect.getType() << " " << rect.getX() << " " << rect.getY()
		<< " " << rect.getWidth() << " " << rect.getHeight() << " " << rect.getFill();
}

/**
*   @brief Prints a line object.
*
*   @param line The line object to be printed.
*/

void Printer::processLine(Line& line)
{
	std::cout << line.getType() << " " << line.getX() << " " << line.getY() << " "
		<< line.getXEnd() << " " << line.getYEnd() << " " << line.getFill();
}

#endif