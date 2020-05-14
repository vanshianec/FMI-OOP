#ifndef _PRINTER_H
#define _PRINTER_H

#include "Visitor.h"

class Printer : public Visitor
{
public:
	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif