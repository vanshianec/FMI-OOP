#ifndef _STORAGEFACTORY_CPP
#define _STORAGEFACTORY_CPP

#include <sstream>
#include <iostream>
#include "StorageFactory.h"
#include "StringTrimmer.h"
#include "ConsoleReader.h"

/**
*   @brief Creates and returns a storage object.
*
*   @return Returns a storage object.
*/

Storage StorageFactory::createStorage(const std::vector<std::string>& params)
{
	Storage storage;

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