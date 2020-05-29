#ifndef _SERIALIZER_CPP
#define _SERIALIZER_CPP

#include <iostream>
#include "Serializer.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "FileUtil.h"
#include "ShapeFactory.h"
#include "FileIOException.h"

/**
*   @brief Saves all shapes in a file.
*
*   @param storage  Storage object containing all available shapes which will be saved in the file.
*
*	@warning Throws FileIOException if the specified file is not an XML file.
*/

void Serializer::processShapeStorage(ShapeStorage& storage)
{
	pugi::xml_document doc;
	pugi::xml_node declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";
	declarationNode.append_attribute("standalone") = "no";

	pugi::xml_node comment = doc.append_child(pugi::node_comment);
	comment.set_value("DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"");

	pugi::xml_node svg = doc.append_child("svg");

	for (Shape* shape : storage.getShapes())
	{
		pugi::xml_node nodeChild = svg.append_child(shape->getType().c_str());
		nodeChild = ShapeFactory::createNode(shape, nodeChild);
	}

	if (!doc.save_file(FileUtil::path.c_str()))
	{
		throw FileIOException("Error saving file " + FileUtil::fileName());
	}

	std::cout << "Successfully saved " << FileUtil::fileName() << std::endl;
}

#endif