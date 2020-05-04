#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include "Date.h"

class Product
{
private:
	std::string name;
	Date expirationDate;
	Date entryDate;
	std::string manufacturerName;
	//TODO IMPORTANT ENUM
	size_t unitOfMeasurement;
	size_t availableQuantity;
	std::string location;
	std::string comment;

public:
	Product();
	const std::string& getName() const;
	const size_t getAvailableQuantity() const;
};

#endif