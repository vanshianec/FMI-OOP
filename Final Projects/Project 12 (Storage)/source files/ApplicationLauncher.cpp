#ifndef __DATE_CPP
#define __DATE_CPP

#include<iostream>
#include<fstream>

#include "ApplicationLauncher.h"
#include "FileUtil.h"
#include "StringTrimmer.h"

ApplicationLauncher::ApplicationLauncher(Visitor* _serializer, Visitor* _deserializer) : firstLaunch(true)

{
	serializer = _serializer;
	deserializer = _deserializer;
}

void ApplicationLauncher::executeCommand()
{
	if (!firstLaunch)
	{
		if (command == SAVE_COMMAND)
		{
			saveDataInCurrentFile();
		}
		else if (command == SAVE_AS_COMMAND)
		{
			saveDataInAnotherFile();
		}
		else if (command == CLOSE_COMMAND)
		{
			clearData();
		}
		else if (command == HELP_COMMAND)
		{
			listSupportedCommands();
		}
		else if (command == PRINT_COMMAND)
		{
			printAvailableProducts();
		}
		else if (command == ADD_COMMAND)
		{
			addProduct();
		}
		else if (command == REMOVE_COMMAND)
		{
			removeProduct();
		}
		else if (command == LOG_COMMAND)
		{
			logStorageChanges();
		}
		else if (command == CLEAN_COMMAND)
		{
			cleanStorage();
		}
	}
	else if (command == OPEN_COMMAND)
	{
		openFile();
	}
	else
	{
		std::cout << USER_ALERT_MESSAGE;
	}
}

void ApplicationLauncher::saveDataInCurrentFile()
{
	storage.accept(serializer);
}

void ApplicationLauncher::saveDataInAnotherFile()
{
	std::string path;
	std::getline(std::cin, path);
	StringTrimmer::trim(path);
	FileUtil::path = path;
	storage.accept(serializer);
}

void ApplicationLauncher::clearData()
{
	storage.clear();
	firstLaunch = true;
}

void ApplicationLauncher::listSupportedCommands()
{
	std::cout << "TODO HELP COMMANDS";
}

void ApplicationLauncher::printAvailableProducts()
{
	storage.printProducts();
}

void ApplicationLauncher::addProduct()
{
	std::string name, manufacturerName, comment, dateFormat;
	Unit unitOfMeasurement;
	size_t availableQuantity;

	std::cin.ignore();
	std::cout << "Enter product name: \n";
	std::getline(std::cin, name);
	std::cout << "Enter manufacturer name: \n";
	std::getline(std::cin, manufacturerName);
	std::cout << "Enter comment(optional) : \n";
	std::getline(std::cin, comment);
	std::cout << "Enter expiration date in format \"YYYY-MM-DD\" : \n";
	std::getline(std::cin, dateFormat);
	Date expirationDate(dateFormat.c_str());
	Date entryDate(CURRENT_DATE.c_str());
	std::cout << "Enter product quantity : \n";
	std::cin >> availableQuantity;

	Product product(name, expirationDate, entryDate, manufacturerName, Unit::Kilograms,
		availableQuantity, comment);
	storage.addNewProduct(product);
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
	Date startDate(startDateFormat);
	Date endDate(endDateFormat);

	storage.logChanges(startDate, endDate);
}

void ApplicationLauncher::cleanStorage()
{
	storage.clean();
}

void ApplicationLauncher::createNewStorage()
{
	std::cout << "Selected file is empty. Create a new storage : \n\n";
	size_t sectionsCount, sectionCapacity, storageCapacity = 0;
	std::cout << "Enter storage sections count: \n";
	std::cin >> sectionsCount;
	for (size_t i = 0; i < sectionsCount; i++)
	{
		std::cout << "Enter section " << i + 1 << " capacity: \n";
		std::cin >> sectionCapacity;
		Section section(0, sectionCapacity);
		storage.addSection(section);
		storageCapacity += sectionCapacity;
	}

	storage.setCapacity(storageCapacity);
	std::cout << "Storage successfully created!\n";
}

void ApplicationLauncher::openFile()
{
	std::string path;
	std::getline(std::cin, path);
	StringTrimmer::trim(path);

	FileUtil::path = path;

	if (FileUtil::isEmpty())
	{
		createNewStorage();
		storage.accept(serializer);
		firstLaunch = false;
	}
	else if (FileUtil::open())
	{
		storage.accept(deserializer);
		firstLaunch = false;
	}
	else
	{
		std::cout << FILE_ERROR_MESSAGE;
	}
}

void ApplicationLauncher::run()
{
	std::cout << USER_ALERT_MESSAGE;
	std::cin >> command;

	while (command != EXIT_COMMAND)
	{
		executeCommand();
		std::cin >> command;
	}
}

#endif