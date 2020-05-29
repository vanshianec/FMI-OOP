#ifndef _TRANSLATE_H
#define _TRANSLATE_H

#include "Visitor.h"

/// @brief Class used to translate shape objects.

class Translate : public Visitor
{
private:
	/// @brief x-axis offset for translation.
	double horizontal;
	/// @brief y-axis offset for translation.
	double vertical;

public:
	Translate(const double _vertical, const double _horizontal);

	/// @brief Translates a circle object.
	void processCircle(Circle&);
	/// @brief Translates a rectangle object.
	void processRectangle(Rect&);
	/// @brief Translates a line object.
	void processLine(Line&);
};

#endif