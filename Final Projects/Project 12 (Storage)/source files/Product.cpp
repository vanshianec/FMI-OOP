#ifndef __PRODUCT_CPP
#define __PRODUCT_CPP

#include "Product.h"
#include <iostream>

Product::Product() : availableQuantity(0) {}

Product::Product(const std::string& _name, const Date& _expirationDate, const Date& _entryDate,
	const std::string& _manufacturerName, const Unit _unitOfMeasurement,
	const size_t _availableQuantity, const std::string& _comment)
{
	name = _name;
	expirationDate = _expirationDate;
	entryDate = _entryDate;
	manufacturerName = _manufacturerName;
	unitOfMeasurement = _unitOfMeasurement;
	availableQuantity = _availableQuantity;
	comment = _comment;
}

const std::string& Product::getName() const
{
	return name;
}

const size_t Product::getSectionId() const
{
	return sectionId;
}

const Date& Product::getExpirationDate() const
{
	return expirationDate;
}

const size_t Product::getAvailableQuantity() const
{
	return availableQuantity;
}

void Product::setSectionId(const size_t _sectionId)
{
	sectionId = _sectionId;
}

bool Product::operator < (const Product& other) const
{
	return expirationDate > other.expirationDate;
}

#endif
