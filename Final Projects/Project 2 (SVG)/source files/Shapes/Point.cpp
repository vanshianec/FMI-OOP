#ifndef _POINT_CPP
#define _POINT_CPP

#include "Point.h"
#include <cmath>

Point::Point(const double _x, const double _y)
{
	x = _x;
	y = _y;
}

const double Point::getX() const
{
	return x;
}

const double Point::getY() const
{
	return y;
}

void Point::setX(const double _x)
{
	x = _x;
}

void Point::setY(const double _y)
{
	y = _y;
}

/**
*   @brief Calculates the distance between two points.
*
*	@param other The other point object to be used to calculate the distance.
*
*   @return Returns the distance between the two points.
*/

const double Point::distance(const Point& other)
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

#endif