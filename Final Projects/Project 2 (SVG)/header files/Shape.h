#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>
#include "Point.h"

class Visitor;
class Circle;
class Rectangle;
class Line;

class Shape
{
private:
	Point location;
	std::string type;
	std::string fill;

protected:
	Shape(const double _x, const double _y, const std::string& _type, const std::string& _fill);

public:
	virtual void accept(Visitor*) = 0;

	virtual bool isInside(Shape*) = 0;
	virtual bool contains(Circle&);
	virtual bool contains(Rectangle&);
	virtual bool contains(Line&);

	const double getX() const;
	const double getY() const;
	const std::string& getType() const;
	const std::string& getFill() const;
	const Point& getLocation() const;

	void setX(const double _x);
	void setY(const double _y);

	virtual ~Shape();
};

#endif