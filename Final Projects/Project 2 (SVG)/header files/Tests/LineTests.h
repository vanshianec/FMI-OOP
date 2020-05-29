#include "Circle.h"
#include "Rect.h"
#include "Line.h"

TEST_CASE("Line Initialization Test")
{
	Line l(2, 7, "Line", "green", 3, 10);
	CHECK(l.getX() == 2);
	CHECK(l.getY() == 7);
	CHECK(l.getType() == "Line");
	CHECK(l.getFill() == "green");
	CHECK(l.getXEnd() == 3);
	CHECK(l.getYEnd() == 10);
}
