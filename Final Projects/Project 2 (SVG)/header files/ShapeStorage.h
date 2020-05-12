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
	void eraseShape(size_t index);
	void translate(Visitor* visitor, size_t index);
	void translate(Visitor*);

	~ShapeStorage();
};

#endif