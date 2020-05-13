#ifndef _TRANSLATE_CPP
#define _TRANSLATE_CPP

#include "Translate.h"

Translate::Translate(const double _horizontal, const double _vertical)
{
	horizontal = _horizontal;
	vertical = _vertical;
}

void Translate::processCircle(Circle& circle)
{
	circle.setX(circle.getX() + horizontal);
	circle.setY(circle.getY() + vertical);
}

void Translate::processRectangle(Rectangle& rectangle)
{
	rectangle.setX(rectangle.getX() + horizontal);
	rectangle.setY(rectangle.getY() + vertical);
}

void Translate::processLine(Line& line)
{
	line.setX(line.getX() + horizontal);
	line.setXEnd(line.getXEnd() + horizontal);
	line.setY(line.getY() + vertical);
	line.setYEnd(line.getYEnd() + vertical);
}

#endif
