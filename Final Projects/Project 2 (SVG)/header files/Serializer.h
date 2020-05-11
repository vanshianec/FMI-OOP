#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "Visitor.h"

class Serializer : public Visitor
{
public:
	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif