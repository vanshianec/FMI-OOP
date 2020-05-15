#ifndef __DATE_CPP
#define __DATE_CPP

#include<iostream>
#include<fstream>

#include "ApplicationLauncher.h"
#include "FileUtil.h"
#include "StringTrimmer.h"
#include "Serializer.h"
#include "Deserializer.h"
#include "ProductFactory.h"
#include "StorageFactory.h"
#include "InvalidParameterException.h"

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
			printAvailableProducts();
		}
		else if (command == "add")
		{
			addProduct();
		}
		else if (command == "remove")
		{
			removeProduct();
		}
		else if (command == "log")
		{
			logStorageChanges();
		}
		else if (command == "clean")
		{
			cleanStorage();
		}
		else if (command == "create")
		{
			createNewStorage();
		}
		else
		{
			std::cout << "Invalid command! Type \"help\" to see supported commands" << std::endl;
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
	storage.accept(&serializer);
	std::cout << "Successfully saved " << FileUtil::fileName() << std::endl;
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
	storage.clear();
	std::cout << "Successfuly closed " << FileUtil::fileName() << std::endl;
	firstLaunch = true;
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
	std::cout << "print -> prints available products\n";
	std::cout << "add <name>, <manufacturer>, <quantity>, <kg> or <l>, <expirationDate>, <comment> -> adds a product to to storage\n";
	std::cout << "remove <amount> <productName> -> removes <amount> specified products\n";
	std::cout << "log <from> <to> -> logs products added and removed from the storage between <from> and <to> dates\n";
	std::cout << "clean -> removes all expired products or products which are about to expire\n";
}

void ApplicationLauncher::printAvailableProducts()
{
	storage.printProducts();
}

void ApplicationLauncher::addProduct()
{
	try
	{
		Product product = ProductFactory::createProduct();
		storage.addNewProduct(product);
	}
	catch (InvalidParameterException ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ApplicationLauncher::removeProduct()
{
	std::string name;
	size_t amount;

	std::cin.ignore();
	std::cin >> amount;
	std::getline(std::cin, name);
	StringTrimmer::trim(name);

	storage.removeProduct(name, amount);
}

void ApplicationLauncher::logStorageChanges()
{
	char startDateFormat[11], endDateFormat[11];
	std::cin >> startDateFormat >> endDateFormat;
	try
	{
		Date startDate(startDateFormat);
		Date endDate(endDateFormat);
		storage.logChanges(startDate, endDate);
	}
	catch (InvalidParameterException ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ApplicationLauncher::cleanStorage()
{
	storage.clean();
}

void ApplicationLauncher::createNewStorage()
{
	storage = StorageFactory::createStorage();
	Serializer serializer;
	storage.accept(&serializer);
	firstLaunch = false;
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
		firstLaunch = false;
		std::cout << "Selected file is empty!";
		std::cout << " Type \"create <sectionsCount> <sectionCapacity>\" to create storage sections\n";
	}
	else if (FileUtil::open())
	{
		std::cout << "Successfully opened " << FileUtil::fileName() << std::endl;
		Deserializer deserializer;
		storage.accept(&deserializer);
		firstLaunch = false;
	}
	else
	{
		std::cout << "Error opening file! Check if the specified path is correct and try again.\n";
	}
}

void ApplicationLauncher::run()
{
	std::cout << "Type: \"open <path>\" to open a file" << std::endl;;
	std::cin >> command;

	while (command != "exit")
	{
		executeCommand();
		std::cin >> command;
	}

	std::cout << "Exiting the program..." << std::endl;
}

#endif