#ifndef _TRANSLATE_CPP
#define _TRANSLATE_CPP

#include "Translate.h"

/**
*   @brief Translate constructor.
*
*   @param _horizontal The x-axis offset to be used.
*   @param _vertical The y-axis offset to be used.
*/

Translate::Translate(const double _horizontal, const double _vertical)
{
	horizontal = _horizontal;
	vertical = _vertical;
}

/**
*   @brief Translates a circle object.
*
*   @param circle The circle object to be translated.
*/

void Translate::processCircle(Circle& circle)
{
	circle.setX(circle.getX() + horizontal);
	circle.setY(circle.getY() + vertical);
}

/**
*   @brief Translates a rectangle object.
*
*   @param rect The rectangle object to be translated.
*/

void Translate::processRectangle(Rect& rect)
{
	rect.setX(rect.getX() + horizontal);
	rect.setY(rect.getY() + vertical);
}

/**
*   @brief Translates a line object.
*
*   @param line The line object to be translated.
*/

void Translate::processLine(Line& line)
{
	line.setX(line.getX() + horizontal);
	line.setXEnd(line.getXEnd() + horizontal);
	line.setY(line.getY() + vertical);
	line.setYEnd(line.getYEnd() + vertical);
}

#endif
