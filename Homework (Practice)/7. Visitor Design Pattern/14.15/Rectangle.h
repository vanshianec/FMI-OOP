#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, const char* text, double w, double h);
	Shape* clone();
	void accept(Visitor*);
	const double getWidth() const;
	const double getHeight() const;
	void setWidth(const double _width);
	void setHeight(const double _height);
	~Rectangle();
private:
	double width;
	double height;
};

#endif
