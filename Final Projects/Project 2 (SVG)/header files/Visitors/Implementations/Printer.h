#ifndef _PRINTER_H
#define _PRINTER_H

#include "Visitor.h"

/// @brief Class used for printing objects.

class Printer : public Visitor
{
public:
	/// @brief Prints a circle object.
	void processCircle(Circle&);
	/// @brief Prints a rectangle object.
	void processRectangle(Rect&);
	/// @brief Prints a line object. 
	void processLine(Line&);
};

#endif