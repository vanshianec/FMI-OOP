#ifndef _RECTANGLE_CPP
#define _RECTANGLE_CPP

#include "Rectangle.h"
#include "Visitor.h"

Rectangle::Rectangle(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, const double _width, const double _height) : Shape(_x, _y, _type, _fill)
{
	width = _width;
	height = _height;
}

void Rectangle::accept(Visitor* visitor)
{
	visitor->processRectangle(*this);
}

bool Rectangle::isInside(Shape* shape)
{
	return shape->contains(*this);
}

bool Rectangle::contains(Circle& circle)
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

bool Rectangle::contains(Rectangle& other)
{
	Point topLeft = other.getLocation();
	Point bottomRight = topLeft;
	bottomRight.setX(topLeft.getX() + other.getWidth());
	bottomRight.setY(topLeft.getY() + other.getHeight());

	return getX() <= topLeft.getX() && bottomRight.getX() <= getX() + width
		&& getY() <= topLeft.getY() && bottomRight.getY() <= getY() + height;
}

bool Rectangle::contains(Line& line)
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

const double Rectangle::getHeight() const
{
	return height;
}

const double Rectangle::getWidth() const
{
	return width;
}

#endif