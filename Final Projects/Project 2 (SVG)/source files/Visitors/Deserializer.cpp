#ifndef _DESERIALIZER_CPP
#define _DESERIALIZER_CPP

#include <iostream>
#include "Deserializer.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "FileUtil.h"
#include "ShapeFactory.h"
#include "FileIOException.h"

void Deserializer::proccesShapeStorage(ShapeStorage& storage)
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