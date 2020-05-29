#ifndef _DESERIALIZER_CPP
#define _DESERIALIZER_CPP

#include <iostream>
#include "Deserializer.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "FileUtil.h"
#include "ShapeFactory.h"
#include "FileIOException.h"

/**
*   @brief Loads all shapes from a file.
*
*   @param storage  Storage object to store all shapes read from the file.
*
*	@warning Throws FileIOException if the specified file is not an XML file.
*/

void Deserializer::processShapeStorage(ShapeStorage& storage)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(FileUtil::path.c_str());

	if (!result)
	{
		throw FileIOException("Error opening file " + FileUtil::fileName());
	}

	std::cout << "Successfully opened " << FileUtil::fileName() << std::endl;

	std::string type;

	for (pugi::xml_node shape : doc.child("svg"))
	{
		std::vector<std::string> params;

		type = shape.name();

		for (pugi::xml_attribute attr : shape.attributes())
		{
			params.push_back(attr.value());
		}

		Shape* s = ShapeFactory::create(type, params);
		storage.addShape(s, false);
	}
}

#endif