#include "Circle.h"
#include "Rect.h"
#include "Line.h"

TEST_CASE("Circle Initialization Test")
{
	Circle c(2, 7, "Circle", "green", 55.2);
	CHECK(c.getX() == 2);
	CHECK(c.getY() == 7);
	CHECK(c.getType() == "Circle");
	CHECK(c.getFill() == "green");
	CHECK(c.getRadius() == 55.2);
}

TEST_CASE("Circle Contains Tests")
{
	Circle c(0, 0, "Circle", "green", 5);
	CHECK(c.contains(c) == true);

	Circle c1(0, 0, "Circe", "red", 3);
	Circle c2(0, 0, "Circe", "red", 10);
	CHECK(c.contains(c1) == true);
	CHECK(c.contains(c2) == false);

	Rect r1(0, 0, "Rect", "blue", 2, 2);
	Rect r2(0, 0, "Rect", "red", 10, 10);
	CHECK(c.contains(r1) == true);
	CHECK(c.contains(r2) == false);

	Line l1(0, 0, "Line", "blue", 1, 1);
	Line l2(0, 0, "Line", "red", 6, 6);
	CHECK(c.contains(l1) == true);
	CHECK(c.contains(l2) == false);
	
}
