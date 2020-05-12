#ifndef _TRANSLATE_H
#define _TRANSLATE_H

#include "Visitor.h"

class Translate : public Visitor
{
private:
	double vertical, horizontal;

public:
	Translate(const double _vertical, const double _horizontal);

	void processCircle(Circle&);
	void processRectangle(Rectangle&);
	void processLine(Line&);
};

#endif