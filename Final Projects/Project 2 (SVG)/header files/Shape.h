#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>

class Visitor;

class Shape 
{
private:
	double x;
	double y;
	std::string fill;

protected:
	Shape(const double _x, const double _y, const std::string& _fill);

public:
	virtual void accept(Visitor*) = 0;

	const double getX() const;
	const double getY() const;
	const std::string& getFill() const;
};

#endif