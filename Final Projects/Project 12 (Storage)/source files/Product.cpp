#ifndef __PRODUCT_CPP
#define __PRODUCT_CPP

#include "Product.h"
#include <iostream>

Product::Product() : quantity(0), sectionId(0), unitOfMeasurement(Unit::Kilograms) {}

Product::Product(const std::string& _name, const Date& _expirationDate, const Date& _entryDate,
	const std::string& _manufacturerName, const Unit _unitOfMeasurement,
	const size_t _quantity, const std::string& _comment)
{
	name = _name;
	expirationDate = _expirationDate;
	entryDate = _entryDate;
	manufacturerName = _manufacturerName;
	unitOfMeasurement = _unitOfMeasurement;
	quantity = _quantity;
	comment = _comment;
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		copyValues(other);
	}

	return *this;
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

const size_t Product::getQuantity() const
{
	return quantity;
}

const Date& Product::getEntryDate() const
{
	return entryDate;
}

const Date& Product::getRemoveDate() const
{
	return removeDate;
}

const std::string& Product::getManufacturerName() const
{
	return manufacturerName;
}

void Product::setSectionId(const size_t _sectionId)
{
	sectionId = _sectionId;
}

void Product::setQuantity(const size_t _quantity)
{
	quantity = _quantity;
}

void Product::setRemoveDate(const Date& _removeDate)
{
	removeDate = _removeDate;
}

void Product::reduceQuantity(const size_t amount)
{
	quantity -= amount;
}

bool Product::operator < (const Product& other) const
{
	return expirationDate > other.expirationDate;
}

bool Product::operator==(const Product& other) const
{
	return name == other.name && expirationDate == other.expirationDate
		&& entryDate == other.entryDate && manufacturerName == other.manufacturerName
		&& unitOfMeasurement == other.unitOfMeasurement && quantity == other.quantity
		&& sectionId == other.sectionId && comment == other.comment;
}

void Product::copyValues(const Product& other)
{
	name = other.name;
	expirationDate = other.expirationDate;
	entryDate = other.entryDate;
	manufacturerName = other.manufacturerName;
	unitOfMeasurement = other.unitOfMeasurement;
	quantity = other.quantity;
	sectionId = other.sectionId;
	comment = other.comment;
}


std::ostream& operator<<(std::ostream& out, const Product& p)
{
	out << p.getName() << " \"" << p.getManufacturerName() << "\" - " << p.getQuantity();
	return out;
}

#endif
