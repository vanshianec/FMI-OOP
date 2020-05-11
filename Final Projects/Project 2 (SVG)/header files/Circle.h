#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(const double _x, const double _y, const std::string& _fill, double _radius);

	void accept(Visitor*);

	const double getRadius() const;
};

#endif