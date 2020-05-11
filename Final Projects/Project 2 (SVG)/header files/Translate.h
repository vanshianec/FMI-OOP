#ifndef _TRANSLATE_H
#define _TRANSLATE_H

#include "Visitor.h"

class Translate : Visitor
{
public:
	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif