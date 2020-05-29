#ifndef _PRODUCTFACTORY_CPP
#define _PRODUCTFACTORY_CPP

#include <sstream>
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include "ProductFactory.h"
#include "StringTrimmer.h"
#include "ConsoleReader.h"
#include "DateTime.h"

/**
*   @brief Creates and returns a product object.
*
*	@param params The parameters to be passed to the object to be created.
*/

const Product ProductFactory::createProduct(const std::vector<std::string>& params)
{
	std::string name = params[0];
	std::string manufacturerName = params[1];
	size_t availableQuantity = std::stoi(params[2]);
	std::string unitOfMeasurement = params[3];
	Date expirationDate = Date(params[4].c_str());
	std::string comment = params[5];
	char dateFormat[11];
	DateTime::currentDateISO8601(dateFormat);
	Date entryDate = Date(dateFormat);

	Product product(name, expirationDate, entryDate, manufacturerName, unitOfMeasurement,
		availableQuantity, comment);

	return product;
}

#endif