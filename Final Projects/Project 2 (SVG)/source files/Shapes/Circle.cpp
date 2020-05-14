#ifndef _CIRCLE_CPP
#define _CIRCLE_CPP

#include <cmath>
#include "Circle.h"
#include "Visitor.h"

Circle::Circle(const double _x, const double _y, const std::string& _type,
	const std::string& _fill, double _radius) : Shape(_x, _y, _type, _fill)
{
	radius = _radius;
}

void Circle::accept(Visitor* visitor)
{
	visitor->processCircle(*this);
}

bool Circle::isInside(Shape* shape)
{
	return shape->contains(*this);
}

bool Circle::contains(Circle& other)
{
	Point otherLocation = other.getLocation();
	double distance = otherLocation.distance(this->getLocation());
	return radius >= other.getRadius() + distance;
}

bool Circle::contains(Rectangle& rectangle)
{
	Point topLeft = rectangle.getLocation();
	Point bottomLeft = topLeft;
	bottomLeft.setY(topLeft.getY() + rectangle.getHeight());
	Point bottomRight = bottomLeft;
	bottomRight.setX(bottomLeft.getX() + rectangle.getWidth());
	Point topRight = topLeft;
	topRight.setX(topLeft.getX() + rectangle.getWidth());
	Point circleCenter = this->getLocation();

	return bottomLeft.distance(circleCenter) <= radius
		&& bottomRight.distance(circleCenter) <= radius
		&& topRight.distance(circleCenter) <= radius
		&& topLeft.distance(circleCenter) <= radius;
}

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