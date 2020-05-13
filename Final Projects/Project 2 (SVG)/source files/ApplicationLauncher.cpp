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

ApplicationLauncher::ApplicationLauncher() : firstLaunch(true) {}

void ApplicationLauncher::executeCommand()
{
	if (!firstLaunch)
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
	}
	else if (command == "open")
	{
		openFile();
	}
	else
	{
		std::cout << "Type: \"open <path>\" to open a file" << std::endl;
	}
}

void ApplicationLauncher::saveDataInCurrentFile()
{

}

void ApplicationLauncher::saveDataInAnotherFile()
{

}

void ApplicationLauncher::clearData()
{

}

void ApplicationLauncher::listSupportedCommands()
{
	std::cout << "TODO HELP COMMANDS";
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
	//todo try catch block
	storage.addShape(ShapeFactory::create(type));
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

	firstLaunch = false;
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
}

#endif