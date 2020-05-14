#ifndef _SHAPESTORAGE_H
#define _SHAPESTORAGE_H

#include <vector>
#include "Shape.h"
#include "Serializable.h"

class ShapeStorage : public Serializable
{
private:
	std::vector<Shape*> shapes;

public:
	void accept(FileIO* visitor);

	void addShape(Shape*, bool shouldPrint);
	void printShapes(Visitor*);
	void eraseShape(int index);
	void translate(Visitor* visitor, int index);
	void translate(Visitor*);
	void printAllInsideShape(Shape* shape, Visitor* printer);
	void clear();

	const std::vector<Shape*>& getShapes() const;

	~ShapeStorage();
};

#endif