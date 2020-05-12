#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	double height;
	double width;

public:
	Rectangle(const double _x, const double _y, const std::string& _fill,
		const double _height, const double _width);

	void accept(Visitor*);

	const double getHeight() const;
	const double getWidth() const;

};

#endif