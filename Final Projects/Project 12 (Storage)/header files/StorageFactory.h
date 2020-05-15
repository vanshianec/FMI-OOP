#ifndef _STORAGEFACTORY_H
#define _STORAGEFACTORY_H

#include "Storage.h"

class StorageFactory 
{
public:
	static Storage createStorage();
};

#endif