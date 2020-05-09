#ifndef _SHAPE_H
#define _SHAPE_H

#include <iostream>

class Visitor;

class Shape
{
public:
	Shape();
	Shape(int x, int y, const char* text);
	Shape(const Shape&);
	Shape& operator=(const Shape&);
	virtual Shape* clone() = 0;
	void setX(int);
	void setY(int);
	void setText(const char*);
	const int getX() const;
	const int getY() const;
	const char* getText() const;
	virtual void accept(Visitor*) = 0;
	virtual ~Shape();

protected:
	int x;
	int y;
	char* text;
};

#endif