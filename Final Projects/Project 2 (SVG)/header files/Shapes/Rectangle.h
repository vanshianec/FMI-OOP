#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	double height;
	double width;

public:
	Rectangle(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, const double _width, const double _height);

	void accept(Visitor*);

	bool isInside(Shape*);
	bool contains(Circle&);
	bool contains(Rectangle&);
	bool contains(Line&);

	const double getHeight() const;
	const double getWidth() const;

};

#endif