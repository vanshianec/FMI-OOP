#ifndef _SHAPESTORAGE_CPP
#define _SHAPESTORAGE_CPP

#include <iostream>
#include "ShapeStorage.h"
#include "FileIO.h"

/**
*   @brief Executes a file input/ouput operation on the current object.
*
*	@param visitor The visitor class which is either a serializer or deserializer.
*/

void ShapeStorage::accept(FileIO* visitor)
{
	visitor->processShapeStorage(*this);
}

/**
*   @brief Adds a shape object to the storage.
*
*	@param shape The shape to be added.
*	@param shouldPrint Decides wheter or not a message should be printed when a shape is added.
*
*	@note If an invalid shape is passed, it will be ignored.
*/


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

/**
*   @brief Prints all shapes in the storage.
*
*	@param printer A visitor class derrived by a printer class which prints shapes.
*/

void ShapeStorage::printShapes(Visitor* printer)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		std::cout << i + 1 << ". ";
		shapes[i]->accept(printer);
		std::cout << std::endl;
	}
}

/**
*   @brief Erase a shape from the specified index.
*
*	@param index The position of the shape in the storage.
*
*   @note If an invalid index is passed the user will be notified about his mistake.
*/

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

/**
*   @brief Translates the n-th shape.
*
*	@param translate A visitor class derived by a translate class which translates shapes.
*	@param index The position of the shape in the storage to be translated.
*
*   @note If an invalid index is passed the user will be notified about his mistake.
*/

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

/**
*   @brief Translates all shapes.
*
*	@param translate A visitor class derived by a translate class which translates shapes.
*
*/

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

/**
*   @brief Prints all shapes inside a shape.
*
*	@param other The shape surface containing all shapes to be printed.
*	@param printer A visitor class derrived by a printer class which prints shapes.
*/

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

/**
*   @brief Deletes all dynamically alocated shapes from the storage.
*
*/

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

/**
*   @brief Removes all shapes from the storage.
*
*/

ShapeStorage::~ShapeStorage()
{
	clear();
}

#endif