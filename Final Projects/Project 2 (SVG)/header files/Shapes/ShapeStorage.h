#ifndef _SHAPESTORAGE_H
#define _SHAPESTORAGE_H

#include <vector>
#include "Shape.h"
#include "Serializable.h"

///@brief Class used for storing shape objects.

class ShapeStorage : public Serializable
{
private:
	std::vector<Shape*> shapes;

public:
	///  @brief Executes a file input / ouput operation on the current object.
	void accept(FileIO* visitor);
	///  @brief Adds a shape object to the storage.
	void addShape(Shape*, bool shouldPrint);
	///  @brief Prints all shapes in the storage.
	void printShapes(Visitor*);
	///  @brief Erase a shape from the specified index.
	void eraseShape(int index);
	///  @brief Translates the n-th shape.
	void translate(Visitor* visitor, int index);
	///  @brief Translates all shapes.
	void translate(Visitor*);
	///  @brief Prints all shapes inside a shape.
	void printAllInsideShape(Shape* shape, Visitor* printer);
	///  @brief Deletes all dynamically alocated shapes from the storage.
	void clear();

	const std::vector<Shape*>& getShapes() const;

	/// @brief Removes all shapes from the storage.
	~ShapeStorage();
};

#endif