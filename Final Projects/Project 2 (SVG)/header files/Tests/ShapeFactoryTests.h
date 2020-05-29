#include "ShapeFactory.h"
#include <vector>
#include <string>

TEST_CASE("Create Shape Test")
{
	std::vector<std::string> circleParams = { "0", "0", "5", "green" };
	Shape* circle = ShapeFactory::create("circle", circleParams);

	CHECK(circle->getX() == 0);
	CHECK(circle->getY() == 0);
	CHECK(circle->getType() == "circle");
	CHECK(circle->getFill() == "green");

	std::vector<std::string> rectParams = { "0", "0", "10", "20" ,"blue" };
	Shape* rect = ShapeFactory::create("rect", rectParams);

	CHECK(rect->getX() == 0);
	CHECK(rect->getY() == 0);
	CHECK(rect->getType() == "rect");
	CHECK(rect->getFill() == "blue");

	std::vector<std::string> lineParams = { "0", "0", "3", "5", "red" };
	Shape* line = ShapeFactory::create("line", lineParams);

	CHECK(line->getX() == 0);
	CHECK(line->getY() == 0);
	CHECK(line->getType() == "line");
	CHECK(line->getFill() == "red");

	Shape* unknown = ShapeFactory::create("Unknown", lineParams);

	CHECK(unknown == nullptr);

	delete circle;
	delete rect;
	delete line;
}