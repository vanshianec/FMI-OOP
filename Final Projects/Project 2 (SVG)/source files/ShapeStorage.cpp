#ifndef _SHAPESTORAGE_CPP
#define _SHAPESTORAGE_CPP

#include <iostream>
#include "ShapeStorage.h"

void ShapeStorage::addShape(Shape* shape)
{
	shapes.push_back(shape);
	std::cout << "Successfully created " << shape->getType() << " (" << shapes.size() << ")\n";
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
	//todo create custom exception
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
	//todo create custom exception
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

void ShapeStorage::saveShapes(Visitor* serializer)
{
	for (Shape* shape : shapes)
	{
		shape->accept(serializer);
	}
}

void ShapeStorage::loadShapes(Visitor* deserializer)
{

}

ShapeStorage::~ShapeStorage()
{
	for (Shape* shape : shapes)
	{
		delete shape;
	}
}

#endif