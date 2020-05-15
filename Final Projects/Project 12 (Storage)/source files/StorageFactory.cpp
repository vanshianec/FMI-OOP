#ifndef _STORAGEFACTORY_CPP
#define _STORAGEFACTORY_CPP

#include <sstream>
#include <iostream>
#include "StorageFactory.h"
#include "StringTrimmer.h"
#include "ConsoleReader.h"

Storage StorageFactory::createStorage()
{
	Storage storage;

	std::cin.ignore();

	std::vector<std::string> params = ConsoleReader::readParams(' ');

	size_t sectionsCount = std::stoi(params[0]);
	size_t sectionsCapacity = std::stoi(params[1]);
	size_t storageCapacity = sectionsCount * sectionsCapacity;
	for (size_t i = 0; i < sectionsCount; i++)
	{
		Section section(sectionsCapacity);
		storage.addSection(section);
	}

	storage.setCapacity(storageCapacity);

	std::cout << "Storage successfully created!" << std::endl;

	return storage;
}

#endif