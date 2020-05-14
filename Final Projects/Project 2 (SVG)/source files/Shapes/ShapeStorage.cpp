#ifndef _SHAPESTORAGE_CPP
#define _SHAPESTORAGE_CPP

#include <iostream>
#include "ShapeStorage.h"
#include "FileIO.h"

void ShapeStorage::accept(FileIO* visitor)
{
	visitor->proccesShapeStorage(*this);
}

void ShapeStorage::addShape(Shape* shape, bool shouldPrint)
{
	if (shape != nullptr)
	{
		shapes.push_back(shape);
	}

	if (shouldPrint && shape != nullptr)
	{
		std::cout << "Successfully created " << shape->getType() << " (" << shapes.size() << ")\n";
	}
}

void ShapeStorage::printShapes(Visitor* printer)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		std::cout << i + 1 << ". ";
		shapes[i]->accept(printer);
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

	Shape* shape = shapes[index];
	shapes.erase(shapes.begin() + index);
	std::cout << "Erased a " << shape->getType() << " (" << index + 1 << ")" << std::endl;
}

void ShapeStorage::translate(Visitor* translate, int index)
{
	if (index < 0 || index >= shapes.size())
	{
		std::cout << "There is no figure number " << index + 1 << "!" << std::endl;
		return;
	}

	shapes[index]->accept(translate);
	std::cout << "Translated figure : " << shapes[index]->getType() << " (" << index + 1 << ")" << std::endl;
}

void ShapeStorage::translate(Visitor* translate)
{
	if (shapes.size() == 0)
	{
		std::cout << "No figures to translate!" << std::endl;
		return;
	}

	for (Shape* shape : shapes)
	{
		shape->accept(translate);
	}

	std::cout << "Translated all figures" << std::endl;
}

void ShapeStorage::printAllInsideShape(Shape* other, Visitor* printer)
{
	size_t count = 1;

	for (size_t i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->isInside(other))
		{
			std::cout << count << ". ";
			shapes[i]->accept(printer);
			std::cout << std::endl;
			count++;
		}
	}

	if (count == 1)
	{
		std::cout << "No figures are located within ";
		other->accept(printer);
		std::cout << std::endl;
	}
}

void ShapeStorage::clear()
{
	for (Shape* shape : shapes)
	{
		delete shape;
	}

	shapes.clear();
}

const std::vector<Shape*>& ShapeStorage::getShapes() const
{
	return shapes;
}

ShapeStorage::~ShapeStorage()
{
	clear();
}

#endif