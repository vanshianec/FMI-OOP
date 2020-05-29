#include "Circle.h"
#include "Rect.h"
#include "Line.h"

TEST_CASE("Rect Initialization Test")
{
	Rect r(2, 7, "Rect", "green", 2, 10);
	CHECK(r.getX() == 2);
	CHECK(r.getY() == 7);
	CHECK(r.getType() == "Rect");
	CHECK(r.getFill() == "green");
	CHECK(r.getWidth() == 2);
	CHECK(r.getHeight() == 10);
}

TEST_CASE("Rect Contains Tests")
{
	Rect r(0, 0, "Rect", "green", 5, 5);
	CHECK(r.contains(r) == true);

	Rect r1(0, 0, "Rect", "blue", 2, 2);
	Rect r2(0, 0, "Rect", "red", 10, 10);
	CHECK(r.contains(r1) == true);
	CHECK(r.contains(r2) == false);

	Circle c1(2, 2, "Circe", "red", 1);
	Circle c2(0, 0, "Circe", "red", 10);
	CHECK(r.contains(c1) == true);
	CHECK(r.contains(c2) == false);

	Line l1(0, 0, "Line", "blue", 1, 1);
	Line l2(0, 0, "Line", "red", 6, 6);
	CHECK(r.contains(l1) == true);
	CHECK(r.contains(l2) == false);

}
