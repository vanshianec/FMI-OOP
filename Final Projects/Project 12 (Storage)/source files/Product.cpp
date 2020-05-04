#ifndef __PRODUCT_CPP
#define __PRODUCT_CPP

#include "Product.h"
#include <iostream>

Product::Product() : availableQuantity(0), unitOfMeasurement(0) {}

const std::string& Product::getName() const
{
	return name;
}

const size_t Product::getAvailableQuantity() const
{
	return availableQuantity;
}

#endif
