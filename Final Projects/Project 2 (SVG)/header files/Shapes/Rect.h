#ifndef _RECT_H
#define _RECT_H

#include "Shape.h"

/// @brief Rectangle shape class.

class Rect : public Shape
{
private:
	double height;
	double width;

public:
	Rect(double _x, double _y, const std::string& _type,
		const std::string& _fill, double _width, double _height);
	/// @brief Applies modifications to this rectangle object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Checks if the rectangle object is inside of another shape object.
	bool isInside(Shape*);
	/// @brief Checks if the rectangle object contains a circle object.
	bool contains(Circle&);
	/// @brief Checks if the rectangle object contains a rectangle object.
	bool contains(Rect&);
	/// @brief Checks if the rectangle object contains a line object.
	bool contains(Line&);

	const double getHeight() const;
	const double getWidth() const;

};

#endif