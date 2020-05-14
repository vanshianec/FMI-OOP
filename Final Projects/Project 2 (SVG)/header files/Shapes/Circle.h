#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, double _radius);

	void accept(Visitor*);

	bool isInside(Shape*);
	bool contains(Circle&);
	bool contains(Rectangle&);
	bool contains(Line&);

	const double getRadius() const;
};

#endif