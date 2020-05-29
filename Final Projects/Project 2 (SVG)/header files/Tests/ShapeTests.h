#include "Circle.h"
#include "Rect.h"
#include "Line.h"

TEST_CASE("Shape Initialization Test")
{
	Shape* circle = new Circle(0, 0, "circle", "green", 5);
	Shape* rect = new Rect(0, 0, "rect", "red", 9, 10);
	Shape* line = new Line(0, 0, "line", "blue", 3, 5);

	CHECK(circle->getX() == 0);
	CHECK(circle->getY() == 0);
	CHECK(circle->getType() == "circle");
	CHECK(circle->getFill() == "green");

	CHECK(rect->getX() == 0);
	CHECK(rect->getY() == 0);
	CHECK(rect->getType() == "rect");
	CHECK(rect->getFill() == "red");

	CHECK(line->getX() == 0);
	CHECK(line->getY() == 0);
	CHECK(line->getType() == "line");
	CHECK(line->getFill() == "blue");

	delete circle;
	delete rect;
	delete line;
}

TEST_CASE("Shape Is Inside Tests")
{
	Shape* circle = new Circle(0, 0, "circle", "red", 8);
	Shape* circle1 = new Circle(0, 0, "circle", "green", 5);
	Shape* circle2 = new Circle(0, 0, "circle", "green", 10);
	Shape* rect = new Rect(0, 0, "circle", "green", 4, 8);
	Shape* rect1 = new Rect(0, 0, "circle", "green", 3, 5);
	Shape* rect2 = new Rect(0, 0, "circle", "green", 9, 10);
	Shape* line = new Line(0, 0, "circle", "green", 3, 5);

	CHECK(line->isInside(circle1) == false);
	CHECK(line->isInside(circle2) == true);
	
	CHECK(circle->isInside(circle1) == false);
	CHECK(circle->isInside(circle2) == true);

	CHECK(rect->isInside(rect1) == false);
	CHECK(rect->isInside(rect2) == true);

	delete circle;
	delete circle1;
	delete circle2;
	delete rect;
	delete rect1;
	delete rect2;
	delete line;
}
