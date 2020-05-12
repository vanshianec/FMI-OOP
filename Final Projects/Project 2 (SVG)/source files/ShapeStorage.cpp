#ifndef _SHAPESTORAGE_CPP
#define _SHAPESTORAGE_CPP

#include <iostream>
#include "ShapeStorage.h"

void ShapeStorage::addShape(Shape* shape)
{
	if (shape != nullptr)
	{
		shapes.push_back(shape);
	}
}

void ShapeStorage::printShapes(Visitor* visitor)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		std::cout << i << ". ";
		shapes[i]->accept(visitor);
		std::cout << std::endl;
	}
}

void ShapeStorage::eraseShape(int index)
{
	if (index < 0 || index >= shapes.size())
	{
		std::cout << "There is no figure number " << index << "!" << std::endl;
		return;
	}

	shapes.erase(shapes.begin() + index);
}

void ShapeStorage::translate(Visitor* visitor, int index)
{
	if (index < 0 || index >= shapes.size())
	{
		std::cout << "There is no figure number " << index << "!" << std::endl;
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