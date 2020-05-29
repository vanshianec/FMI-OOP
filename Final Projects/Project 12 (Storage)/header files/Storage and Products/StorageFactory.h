#ifndef _STORAGEFACTORY_H
#define _STORAGEFACTORY_H

#include "Storage.h"

/// @brief Class that creates storage objects.

class StorageFactory 
{
public:
	/// @brief Creates and returns a storage object.
	static Storage createStorage(const std::vector<std::string>& params);
};

#endif