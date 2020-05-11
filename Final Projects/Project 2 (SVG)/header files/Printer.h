#ifndef _PRINTER_H
#define _PRINTER_H

#include "Visitor.h"

class Printer : Visitor
{
public:
	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif