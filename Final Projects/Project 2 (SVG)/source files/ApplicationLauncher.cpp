#ifndef _APPLICATIONLAUNCHER_CPP
#define _APPLICATIONLAUNCHER_CPP

#include <iostream>
#include "ApplicationLauncher.h"
#include "ConsoleReader.h"
#include "ShapeFactory.h"
#include "Translate.h"
#include "Printer.h"
#include "Serializer.h"
#include "Deserializer.h"
#include "StringTrimmer.h"
#include "FileUtil.h"
#include "FileIOException.h"

ApplicationLauncher::ApplicationLauncher() : firstLaunch(true) {}

/**
*   @brief Enables the user to start using the application.
*
*   @note  The application will be running until the user types "exit" in the console.
*/

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

/**
*   @brief Executes the command entered by the user.
*
*   @note  In case of an invalid command the application won't stop and the user will be notified about his mistake.
*/

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

/**
*   @brief Opens an XML file from the path specified by the user.
*
*   @note  In case the file does not exist a new file will be created.
*
*	@warning Throws FileIOException if the specified file is invalid.
*/

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

/**
*   @brief Saves the changes made by the user in the currently opened file.
*
*	@warning Throws FileIOException if saving data to the file has failed.
*/

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

/**
*   @brief Saves the changes made by the user in a new file specified by the user.
*
*	@warning Throws FileIOException if saving data to the file has failed or the newly specified file is invalid.
*/

void ApplicationLauncher::saveDataInAnotherFile()
{
	std::string path;
	std::getline(std::cin, path);
	StringTrimmer::trim(path);
	FileUtil::path = path;
	saveDataInCurrentFile();
}

/**
*   @brief Reverts all changes made by the user.
*
*	@note A new file to write on should be chosen after this command.
*/

void ApplicationLauncher::clearData()
{
	std::cout << "Successfully closed " << FileUtil::fileName() << std::endl;
	firstLaunch = true;
	storage.clear();
}

/**
*   @brief Displays all command supported by the application.
*/

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
	std::cout << "create <rect> <x> <y> <width> <height> <fill> -> creates a rectangle\n";
	std::cout << "create <line> <x> <y> <xEnd> <yEnd> <fill> -> creates a line\n";
	std::cout << "print -> prints all shapes\n";
	std::cout << "erase <n> -> erases the n-th shape\n";
	std::cout << "translate <n> -> translates the n-th shape\n";
	std::cout << "translate -> translates all shapes\n";
	std::cout << "within <shape> {shapeParams} -> prints all shapes inside the specified <shape>\n";
}

/**
*   @brief Prints all currently available shapes.
*
*	@note Also prints shapes loaded from file.
*/

void ApplicationLauncher::printShapes()
{
	Printer printer;
	storage.printShapes(&printer);
}

/**
*   @brief Creates a new shape specified by the user.
*
*	@note Invalid shapes won't stop the program but the user will be notified about his mistake.
*/

void ApplicationLauncher::createShape()
{
	std::string type;
	std::cin >> type;
	std::cin.ignore();
	std::vector<std::string> params = ConsoleReader::readParams(' ');
	Shape* shape;

	try
	{
		shape = ShapeFactory::create(type, params);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << "Invalid parameters! Type 'help' to see more info about the create command\n";
		return;
	}

	if (shape == nullptr)
	{
		std::cout << "Invalid shape! Type 'help' to see supported shapes.\n";
		return;
	}

	storage.addShape(shape, true);
}

/**
*   @brief Removes a shape specified by the user.
*
*	@note  If the shapes does not exist the user will be notified.
*/

void ApplicationLauncher::eraseShape()
{
	size_t index;
	std::cin >> index;
	storage.eraseShape(index - 1);
}

/**
*   @brief Translates all shapes or a specified shape.
*
*   @note  If the specified shape does not exist the user will be notified.
*/

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

/**
*   @brief Prints all shapes within a surface.
*
*   @warning  Only circle and rectangle surfaces are supported.
*/

void ApplicationLauncher::withinSurface()
{
	std::string type;
	std::cin >> type;

	if (type != "circle" && type != "rect")
	{
		std::cout << "Invalid shape! Only circle and rectangle surfaces allowed !\n";
		return;
	}

	std::cin.ignore();
	std::vector<std::string> params = ConsoleReader::readParams(' ');
	//add last param for shape color since its not required by the user
	params.push_back("");
	Shape* shape;
	try
	{
		shape = ShapeFactory::create(type, params);
	}
	catch (std::invalid_argument& ex)
	{
		std::cout << "Invalid parameters! Type 'help' to see more info about the within command\n";
		return;
	}

	if (shape == nullptr)
	{
		std::cout << "Invalid shape! Type 'help' to see supported shapes.\n";
		return;
	}

	Printer printer;
	storage.printAllInsideShape(shape, &printer);
	delete shape;
}

#endif