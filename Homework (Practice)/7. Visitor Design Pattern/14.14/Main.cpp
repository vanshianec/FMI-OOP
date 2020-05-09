#include <iostream>
#include <cstring>

#include "Splitter.h"

int main()
{
	Visitor* splitter = new Splitter();

	Shape* circle = new Circle(0, 0, "circle1", 10);
	Shape* circle2 = new Circle(0, 0, "circle2", 1);
	Shape* circle3 = new Circle(1, 1, "circle3", 5);
	Shape* rect = new Rectangle(0, 0, "rect1", 10, 10);
	Shape* rect2 = new Rectangle(10, 10, "rect2", 20, 30);

	Group* group2 = new Group(0, 0, "group2");
	group2->addShape(circle3);

	Group* group = new Group(100, 100, "group1");

	group->addShape(circle2);
	group->addShape(rect2);
	group->addShape(group2);

	circle->accept(splitter);
	group->accept(splitter);
	rect->accept(splitter);

	splitter->getCircles();
	splitter->getRectangles();

	delete circle;
	delete rect;
	delete group;

	return 0;
}