#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	 Circle(int x, int y, const char* text, double _r);
	 Shape* clone();
	 ~Circle();
	 void accept(Visitor*);
	 const double getRadius() const;
	 void setRadius(const double _r);
private:
	double r;
};

#endif;