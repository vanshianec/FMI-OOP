#ifndef __DATE_CPP
#define __DATE_CPP

#include<iostream>
#include<fstream>

#include "ApplicationLauncher.h"

//todo see without class init
ApplicationLauncher::ApplicationLauncher() : file(), storage(), firstLaunch(true), command(), path() {}

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
	storage.save(path);
}

void ApplicationLauncher::saveDataInAnotherFile()
{
	std::getline(std::cin, path);
	//TODO IMPORTANT !!! CREATE STATIC TRIM CLASS AND PATH VALIDATOR
	trim(path);
	storage.save(path);
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
	//TODO!!! ADD PRODUCT FACTORY AND VALIDATION AND FIX DATE CLASS VALIDATION!!!
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
	Date entryDate("2020-05-30");
	//std::cout << "Enter unit of measurement (L/KG): \n";
	std::cout << "Enter product quantity : \n";
	std::cin >> availableQuantity;

	Product product(name, expirationDate, entryDate, manufacturerName, Unit::Kilograms,
		availableQuantity, comment);
	storage.addProduct(product);
}

void ApplicationLauncher::removeProduct()
{
	//TODO!!! ADD PRODUCT FACTORY AND VALIDATION AND FIX DATE CLASS VALIDATION!!!
	std::string name;
	size_t amount;

	std::cin.ignore();
	std::cin >> amount;
	std::getline(std::cin, name);

	storage.removeProduct(name, amount);
}

void ApplicationLauncher::logStorageChanges()
{
	char startDateFormat[11], endDateFormat[11];
	std::cin >> startDateFormat, endDateFormat;
	Date startDate(startDateFormat);
	Date endDate(endDateFormat);

	storage.logChanges(startDate, endDate);
}

void ApplicationLauncher::createNewStorage()
{
	//TODO!!! ADD STORAGE FACTORY

	std::cout << "Selected file is empty. A new storage will be created.\n";
	size_t sectionsCount, sectionCapacity, storageCapacity = 0;
	std::cout << "Enter storage sections count: \n";
	std::cin >> sectionsCount;
	for (size_t i = 0; i < sectionsCount; i++)
	{
		std::cout << "Enter section capacity: \n";
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
	std::getline(std::cin, path);
	trim(path);

	if (file.isEmpty(path))
	{
		createNewStorage();
		storage.save(path);
		firstLaunch = false;
	}
	else if (file.open(path))
	{
		storage.load(path);
		std::cout << "Storage successfully opened!\n";
		firstLaunch = false;
	}
	else
	{
		std::cout << FILE_ERROR_MESSAGE;
	}
}

std::string& ltrim(std::string& str, const std::string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str)
{
	const std::string chars = "\t\n\v\f\r ";
	return ltrim(rtrim(str, chars), chars);
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