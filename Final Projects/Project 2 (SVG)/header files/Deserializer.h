#ifndef _DESERIALIZER_H
#define _DESERIALIZER_H

#include "Visitor.h"

class Deserializer : Visitor
{
public:
	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif