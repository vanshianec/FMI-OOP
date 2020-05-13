#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	double x, y;
public:
	Point(double _x, double _y);

	const double getX() const;
	const double getY() const;

	void setX(const double _x);
	void setY(const double _y);

	const double distance(const Point& other);
};

#endif