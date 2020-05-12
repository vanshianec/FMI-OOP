
#include <iostream>
#include "ApplicationLauncher.h"
#include "Serializer.h"
#include "Deserializer.h"
#include "Printer.h"
#include "pugixml.hpp"

int main()
{
	/*
	ApplicationLauncher launcher;
	launcher.run();
	*/
	
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("test.svg");

	if (!result)
	{
		std::cout << "Fail";
	}
	else 
	{
		std::cout << "Success!";
	}

	for (pugi::xml_node tool : doc.child("svg"))
	{
		std::cout << tool.name() << std::endl;

	}
}

