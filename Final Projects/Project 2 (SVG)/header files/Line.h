#ifndef _LINE_H
#define _LINE_H

#include "Shape.h"

class Line : public Shape
{
private:
	Point endLocation;

public:
	Line(const double _x, const double _y, const std::string& _type,
		const std::string& _fill, const double _xEnd, const double _yEnd);

	void accept(Visitor*);

	bool isInside(Shape*);

	const double getXEnd() const;
	const double getYEnd() const;
	const Point& getEndLocation() const;

	void setXEnd(const double _xEnd);
	void setYEnd(const double _yEnd);
};

#endif