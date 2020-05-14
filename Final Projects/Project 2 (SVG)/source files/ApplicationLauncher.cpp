#ifndef _APPLICATIONLAUNCHER_CPP
#define _APPLICATIONLAUNCHER_CPP

#include <iostream>
#include "ApplicationLauncher.h"
#include "ShapeFactory.h"
#include "Translate.h"
#include "Printer.h"
#include "Serializer.h"
#include "Deserializer.h"
#include "StringTrimmer.h"
#include "FileUtil.h"
#include "FileIOException.h"

ApplicationLauncher::ApplicationLauncher() : firstLaunch(true) {}

void ApplicationLauncher::executeCommand()
{
	if (command == "open")
	{
		openFile();
	}
	else if (!firstLaunch)
	{
		if (command == "save")
		{
			saveDataInCurrentFile();
		}
		else if (command == "saveas")
		{
			saveDataInAnotherFile();
		}
		else if (command == "close")
		{
			clearData();
		}
		else if (command == "help")
		{
			listSupportedCommands();
		}
		else if (command == "print")
		{
			printShapes();
		}
		else if (command == "create")
		{
			createShape();
		}
		else if (command == "erase")
		{
			eraseShape();
		}
		else if (command == "translate")
		{
			translateShape();
		}
		else if (command == "within")
		{
			withinSurface();
		}
		else
		{
			std::cout << "Invalid command! Type \"help\" to see supported commands\n";
		}
	}
	else
	{
		std::cout << "Type: \"open <path>\" to open a file" << std::endl;
	}
}

void ApplicationLauncher::saveDataInCurrentFile()
{
	Serializer serializer;
	try
	{
		storage.accept(&serializer);
	}
	catch (FileIOException ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ApplicationLauncher::saveDataInAnotherFile()
{
	std::string path;
	std::getline(std::cin, path);
	StringTrimmer::trim(path);
	FileUtil::path = path;
	saveDataInCurrentFile();
}

void ApplicationLauncher::clearData()
{
	std::cout << "Successfully closed " << FileUtil::fileName() << std::endl;
	firstLaunch = true;
	storage.clear();
}

void ApplicationLauncher::listSupportedCommands()
{
	std::cout << "The following commands are supported:\n";
	std::cout << "open <file> -> opens <file>\n";
	std::cout << "close -> closes currently opened file\n";
	std::cout << "save -> saves the currently opened file\n";
	std::cout << "saveas <file> -> saves the currently opened file in <file>\n";
	std::cout << "help -> prints supported commands\n";
	std::cout << "exit -> exits the program\n";
	std::cout << "create <circle> <x> <y> <radius> <fill> -> creates a circle\n";
	std::cout << "create <rectangle> <x> <y> <width> <height> <fill> -> creates a rectangle\n";
	std::cout << "create <line> <x> <y> <xEnd> <yEnd> <fill> -> creates a line\n";
	std::cout << "print -> prints all shapes\n";
	std::cout << "erase <n> -> erases the n-th shape\n";
	std::cout << "translate <n> -> translates the n-th shape\n";
	std::cout << "translate -> translates all shapes\n";
	std::cout << "within <shape> {shapeParams} -> prints all shapes inside the specified <shape>\n";
}

void ApplicationLauncher::printShapes()
{
	Printer printer;
	storage.printShapes(&printer);
}

void ApplicationLauncher::createShape()
{
	std::string type;
	std::cin >> type;
	storage.addShape(ShapeFactory::create(type), true);
}

void ApplicationLauncher::eraseShape()
{
	size_t index;
	std::cin >> index;
	storage.eraseShape(index - 1);
}

void ApplicationLauncher::translateShape()
{
	double horizontal, vertical;
	std::cin >> horizontal >> vertical;

	Translate translate(horizontal, vertical);

	std::string num;
	std::getline(std::cin, num);
	StringTrimmer::trim(num);
	if (num.empty())
	{
		storage.translate(&translate);
	}
	else
	{
		storage.translate(&translate, std::stoi(num) - 1);
	}
}

void ApplicationLauncher::withinSurface()
{
	std::string type;
	std::cin >> type;

	if (type != "circle" && type != "rectangle")
	{
		std::cout << "Invalid shape! Only circle and rectangle surfaces allowed !\n";
		return;
	}

	Printer printer;
	Shape* shape = ShapeFactory::create(type);
	storage.printAllInsideShape(shape, &printer);
	delete shape;
}

void ApplicationLauncher::openFile()
{
	if (!firstLaunch)
	{
		clearData();
	}

	std::string path;
	std::getline(std::cin, path);
	StringTrimmer::trim(path);

	FileUtil::path = path;

	if (FileUtil::isEmpty())
	{
		std::cout << "Successfully opened " << FileUtil::fileName() << std::endl;
		firstLaunch = false;
	}
	else if (FileUtil::open())
	{
		Deserializer deserializer;
		try
		{
			storage.accept(&deserializer);
			firstLaunch = false;
		}
		catch (FileIOException ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Error opening file! Check if the specified path is correct and try again.\n";
	}
}

void ApplicationLauncher::run()
{
	std::cout << "Type: \"open <path>\" to open a file" << std::endl;
	std::cin >> command;

	while (command != "exit")
	{
		executeCommand();
		std::cin >> command;
	}

	std::cout << "Exiting the program..." << std::endl;
}

#endif