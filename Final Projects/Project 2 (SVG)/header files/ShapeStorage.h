#ifndef _SHAPESTORAGE_H
#define _SHAPESTORAGE_H

#include <vector>
#include "Shape.h"

class ShapeStorage
{
private:
	std::vector<Shape*> shapes;

public:
	void addShape(Shape*);
	void printShapes(Visitor*);
	void eraseShape(int index);
	void translate(Visitor* visitor, int index);
	void translate(Visitor*);

	~ShapeStorage();
};

#endif