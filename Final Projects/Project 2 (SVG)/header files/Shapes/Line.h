#ifndef _LINE_H
#define _LINE_H

#include "Shape.h"


/// @brief Line shape class.

class Line : public Shape
{
private:
	Point endLocation;

public:
	Line(double _x, double _y, const std::string& _type,
		const std::string& _fill, double _xEnd, double _yEnd);
	/// @brief Applies modifications to this line object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Checks if the current line object is inside of another shape object.
	bool isInside(Shape*);

	const double getXEnd() const;
	const double getYEnd() const;
	const Point& getEndLocation() const;

	void setXEnd(double _xEnd);
	void setYEnd(double _yEnd);
};

#endif