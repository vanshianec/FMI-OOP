#ifndef _SHAPESTORAGE_CPP
#define _SHAPESTORAGE_CPP

#include <iostream>
#include "ShapeStorage.h"

void ShapeStorage::addShape(Shape* shape)
{
	shapes.push_back(shape);
}

void ShapeStorage::printShapes(Visitor* visitor)
{
	for (Shape* shape : shapes)
	{
		shape->accept(visitor);
	}
}

void ShapeStorage::eraseShape(size_t index)
{
	if (index >= shapes.size())
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	shapes.erase(shapes.begin() + index);
}

void ShapeStorage::translate(Visitor* visitor, size_t index)
{
	if (index >= shapes.size())
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	shapes[index]->accept(visitor);
}

void ShapeStorage::translate(Visitor* visitor)
{
	for (Shape* shape : shapes)
	{
		shape->accept(visitor);
	}
}

ShapeStorage::~ShapeStorage()
{
	for (Shape* shape : shapes)
	{
		delete shape;
	}
}

#endif