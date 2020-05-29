#ifndef _CIRCLE_CPP
#define _CIRCLE_CPP

#include <cmath>
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "Visitor.h"

Circle::Circle(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, double _radius) : Shape(_x, _y, _type, _fill)
{
	radius = _radius;
}

/**
*   @brief Applies modifications to this object with the help of a visitor object.
*
*	@param visitor A visitor object which will modify the current object.
*/

void Circle::accept(Visitor* visitor)
{
	visitor->processCircle(*this);
}

/**
*   @brief Checks if the current object is inside of another shape object.
*
*	@param shape A shape object which will check if it contains the current object.
*
*   @return Returns true if the current object is inside the other shape object or false otherwise.
*/

bool Circle::isInside(Shape* shape)
{
	return shape->contains(*this);
}

/**
*   @brief Checks if the current object contains a circle object inside it.
*
*	@param other A circle object to be checked if it is inside the current object.
*
*   @return Returns true if the current object class contains a circle object or false otherwise.
*/

bool Circle::contains(Circle& other)
{
	Point otherLocation = other.getLocation();
	double distance = otherLocation.distance(this->getLocation());
	return radius >= other.getRadius() + distance;
}

/**
*   @brief Checks if the current object contains a rectangle object inside it.
*
*	@param rect A rectangle object to be checked if it is inside the current object.
*
*   @return Returns true if the current object class contains a rectangle object or false otherwise.
*/

bool Circle::contains(Rect& rect)
{
	Point topLeft = rect.getLocation();
	Point bottomLeft = topLeft;
	bottomLeft.setY(topLeft.getY() + rect.getHeight());
	Point bottomRight = bottomLeft;
	bottomRight.setX(bottomLeft.getX() + rect.getWidth());
	Point topRight = topLeft;
	topRight.setX(topLeft.getX() + rect.getWidth());
	Point circleCenter = this->getLocation();

	return bottomLeft.distance(circleCenter) <= radius
		&& bottomRight.distance(circleCenter) <= radius
		&& topRight.distance(circleCenter) <= radius
		&& topLeft.distance(circleCenter) <= radius;
}

/**
*   @brief Checks if the current object contains a line object inside it.
*
*	@param line A line object to be checked if it is inside the current object.
*
*   @return Returns true if the current object class contains a line object or false otherwise.
*/

bool Circle::contains(Line& line)
{
	Point lineStart = line.getLocation();
	Point lineEnd = line.getEndLocation();
	Point circleCenter = this->getLocation();
	return lineStart.distance(circleCenter) <= radius
		&& lineEnd.distance(circleCenter) <= radius;
}

const double Circle::getRadius() const
{
	return radius;
}

#endif