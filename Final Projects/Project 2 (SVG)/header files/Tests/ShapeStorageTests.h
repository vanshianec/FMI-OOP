#include "ShapeStorage.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "Translate.h"

TEST_CASE("Add Shape Tests")
{
	ShapeStorage s;
	Shape* circle = new Circle(0, 0, "circle", "green", 9);
	Shape* rect = new Rect(0, 0, "rect", "red", 10, 20);
	Shape* line = new Line(0, 0, "line", "blue", 5, 5);
	s.addShape(circle, false);
	s.addShape(rect, false);
	s.addShape(line, false);

	CHECK(s.getShapes().size() == 3);

	s.addShape(nullptr, false);

	CHECK(s.getShapes().size() == 3);
}

TEST_CASE("Clear Shapes Test")
{
	ShapeStorage s;
	Shape* circle = new Circle(0, 0, "circle", "green", 9);
	Shape* rect = new Rect(0, 0, "rect", "red", 10, 20);
	Shape* line = new Line(0, 0, "line", "blue", 5, 5);
	s.addShape(circle, false);
	s.addShape(rect, false);
	s.addShape(line, false);

	CHECK(s.getShapes().size() == 3);

	s.clear();

	CHECK(s.getShapes().size() == 0);
}

TEST_CASE("Erase Shapes Tests")
{
	ShapeStorage s;
	Shape* circle = new Circle(0, 0, "circle", "green", 9);
	Shape* rect = new Rect(0, 0, "rect", "red", 10, 20);
	Shape* line = new Line(0, 0, "line", "blue", 5, 5);
	s.addShape(circle, false);
	s.addShape(rect, false);
	s.addShape(line, false);

	CHECK(s.getShapes().size() == 3);

	s.eraseShape(0);

	CHECK(s.getShapes().size() == 2);

	s.eraseShape(1);

	CHECK(s.getShapes().size() == 1);

	s.eraseShape(1);

	CHECK(s.getShapes().size() == 1);

	s.eraseShape(0);

	CHECK(s.getShapes().size() == 0);
}

TEST_CASE("Erase Shapes Tests")
{
	ShapeStorage s;
	Shape* circle = new Circle(0, 0, "circle", "green", 9);
	Shape* rect = new Rect(0, 0, "rect", "red", 10, 20);
	Shape* line = new Line(0, 0, "line", "blue", 5, 5);
	s.addShape(circle, false);
	s.addShape(rect, false);
	s.addShape(line, false);

	CHECK(s.getShapes().size() == 3);

	s.eraseShape(0);

	CHECK(s.getShapes().size() == 2);

	s.eraseShape(1);

	CHECK(s.getShapes().size() == 1);

	s.eraseShape(1);

	CHECK(s.getShapes().size() == 1);

	s.eraseShape(0);

	CHECK(s.getShapes().size() == 0);
}

TEST_CASE("Translate Shapes Tests")
{
	ShapeStorage s;
	Shape* circle = new Circle(0, 0, "circle", "green", 9);
	Shape* rect = new Rect(0, 0, "rect", "red", 10, 20);
	Shape* line = new Line(0, 0, "line", "blue", 5, 5);
	s.addShape(circle, false);
	s.addShape(rect, false);
	s.addShape(line, false);

	Translate translate(10, 10);
	s.translate(&translate);

	for (Shape* shape : s.getShapes())
	{
		CHECK(shape->getX() == 10);
		CHECK(shape->getY() == 10);
	}
}