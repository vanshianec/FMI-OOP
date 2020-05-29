#ifndef _RECT_CPP
#define _RECT_CPP

#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "Visitor.h"

Rect::Rect(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, const double _width, const double _height) : Shape(_x, _y, _type, _fill)
{
	width = _width;
	height = _height;
}

/**
*   @brief Applies modifications to this object with the help of a visitor object.
*
*	@param visitor A visitor object which will modify the current object.
*/

void Rect::accept(Visitor* visitor)
{
	visitor->processRectangle(*this);
}

/**
*   @brief Checks if the current object is inside of another shape object.
*
*	@param shape A shape object which will check if it contains the current object.
*
*   @return Returns true if the current object is inside the other shape object or false otherwise.
*/

bool Rect::isInside(Shape* shape)
{
	return shape->contains(*this);
}

/**
*   @brief Checks if the current object contains a circle object inside it.
*
*	@param circle A circle object to be checked if it is inside the current object.
*
*   @return Returns true if the current object contains a circle object or false otherwise.
*/

bool Rect::contains(Circle& circle)
{
	Point mostLeftPoint = this->getLocation();
	mostLeftPoint.setY(circle.getY());
	Point mostRightPoint = mostLeftPoint;
	mostRightPoint.setX(mostLeftPoint.getX() + width);
	Point mostBottomPoint = this->getLocation();
	mostBottomPoint.setY(mostBottomPoint.getY() + height);
	mostBottomPoint.setX(circle.getX());
	Point mostTopPoint = mostBottomPoint;
	mostTopPoint.setY(mostBottomPoint.getY() - height);
	Point circleCenter = circle.getLocation();
	double radius = circle.getRadius();

	return mostLeftPoint.distance(circleCenter) >= radius
		&& mostRightPoint.distance(circleCenter) >= radius
		&& mostBottomPoint.distance(circleCenter) >= radius
		&& mostTopPoint.distance(circleCenter) >= radius;
}

/**
*   @brief Checks if the current object contains a rectangle object inside it.
*
*	@param other A rectangle object to be checked if it is inside the current object.
*
*   @return Returns true if the current object class contains a rectangle object or false otherwise.
*/

bool Rect::contains(Rect& other)
{
	Point topLeft = other.getLocation();
	Point bottomRight = topLeft;
	bottomRight.setX(topLeft.getX() + other.getWidth());
	bottomRight.setY(topLeft.getY() + other.getHeight());

	return getX() <= topLeft.getX() && bottomRight.getX() <= getX() + width
		&& getY() <= topLeft.getY() && bottomRight.getY() <= getY() + height;
}

/**
*   @brief Checks if the current object contains a line object inside it.
*
*	@param line A line object to be checked if it is inside the current object.
*
*   @return Returns true if the current object class contains a line object or false otherwise.
*/

bool Rect::contains(Line& line)
{
	Point lineStart = line.getLocation();
	Point lineEnd = line.getEndLocation();
	double x = getX();
	double y = getY();

	return x <= lineStart.getX() && lineStart.getX() <= x + width
		&& y <= lineStart.getY() && lineStart.getY() <= y + height
		&& x <= lineEnd.getX() && lineEnd.getX() <= x + width
		&& y <= lineEnd.getY() && lineEnd.getY() <= y + height;
}

const double Rect::getHeight() const
{
	return height;
}

const double Rect::getWidth() const
{
	return width;
}

#endif