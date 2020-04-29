#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "Date.h"

class Product
{
private:
	std::string name;
	Date expirationDate;
	Date entryDate;
	std::string manufacturerName;
	//todo enum
	int unitOfMeasurement;
	int availableQuantity;
	int section;
	std::string comment;

public:
	Product();
};

#endif