#ifndef __PRODUCT_CPP
#define __PRODUCT_CPP

#include "Product.h"
#include "Visitor.h"
#include <iostream>
#include "InvalidParameterException.h"

Product::Product() : quantity(0), sectionId(0), unitOfMeasurement(Unit::Kilograms) {}

Product::Product(const std::string& _name, const Date& _expirationDate, const Date& _entryDate,
	const std::string& _manufacturerName, const std::string& _unitOfMeasurement,
	const size_t _quantity, const std::string& _comment)
{
	setName(_name);
	setExpirationDate(_expirationDate);
	setEntryDate(_entryDate);
	setManufacturerName(_manufacturerName);
	setUnitOfMeasuremnet(_unitOfMeasurement);
	setQuantity(_quantity);
	setComment(_comment);
}

/**
*   @brief Allows the usage of operator '=' on Product objects.
*
*/

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		copyValues(other);
	}

	return *this;
}

/**
*   @brief Applies modifications to this object with the help of a visitor object.
*
*	@param visitor A visitor object which will modify the current object.
*/

void Product::accept(Visitor* visitor)
{
	visitor->proccesProduct(*this);
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

const std::string& Product::getComment() const
{
	return comment;
}

const Unit Product::getUnitOfMeasurement() const
{
	return unitOfMeasurement;
}

/**
*   @brief Sets the name of the product.
*
*	@param _name The name which will be set to the product.
*
*	@warning Throws InvalidParameterException if the size of the name is less than 2.
*/

void Product::setName(const std::string& _name)
{
	if (_name.size() < 2)
	{
		throw InvalidParameterException("Invalid product name! Product name should be at least 2 symbols long");
	}

	name = _name;
}

/**
*   @brief Sets the manufacturer name of the product.
*
*	@param _manufacturerName The manufacturer name which will be set to the product.
*
*	@warning Throws InvalidParameterException if the size of the manufacturer name is less than 3.
*/

void Product::setManufacturerName(const std::string& _manufacturerName)
{
	if (_manufacturerName.size() < 3)
	{
		throw InvalidParameterException("Invalid manufacturer name! Manufacturer name should be at least 3 symbols long");
	}

	manufacturerName = _manufacturerName;
}

void Product::setComment(const std::string& _comment)
{
	comment = _comment;
}

void Product::setExpirationDate(const Date& _expirationDate)
{
	expirationDate = _expirationDate;
}

void Product::setEntryDate(const Date& _entryDate)
{
	entryDate = _entryDate;
}

/**
*   @brief Sets the unit of measurement of the product.
*
*	@param _unitOfMeasurement The unit of measurement which will be set to the product.
*
*	@warning Throws InvalidParameterException if invalid unit is passed.
*/

void Product::setUnitOfMeasuremnet(const std::string& _unitOfMeasurement)
{
	if (_unitOfMeasurement == "kg")
	{
		unitOfMeasurement = Unit::Kilograms;
	}
	else if (_unitOfMeasurement == "l")
	{
		unitOfMeasurement = Unit::Liters;
	}
	else
	{
		throw InvalidParameterException("Invalid unit of measurement! Supported units are <kg> and <l>");
	}
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

/**
*   @brief Reduces the quantity of the product.
*
*	@param amount The amount of the product to be reduced.
*/

void Product::reduceQuantity(const size_t amount)
{
	quantity -= amount;
}

/**
*   @brief Compares two products with operator '<' by expirataion date.
*
*	@param other The other product to be compared with the current product.
*/

bool Product::operator < (const Product& other) const
{
	return expirationDate < other.expirationDate;
}

/**
*   @brief Compares two products with operator '==' (checks if they are equal).
*
*	@param other The other product to be compared with the current product.
*/

bool Product::operator==(const Product& other) const
{
	return name == other.name && expirationDate == other.expirationDate
		&& entryDate == other.entryDate && manufacturerName == other.manufacturerName
		&& unitOfMeasurement == other.unitOfMeasurement && quantity == other.quantity
		&& sectionId == other.sectionId && comment == other.comment;
}

/**
*   @brief Copies the parameters of an other product to this one.
*
*	@param other The other product which parameters will be copied.
*/

void Product::copyValues(const Product& other)
{
	name = other.name;
	expirationDate = other.expirationDate;
	entryDate = other.entryDate;
	removeDate = other.removeDate;
	manufacturerName = other.manufacturerName;
	unitOfMeasurement = other.unitOfMeasurement;
	quantity = other.quantity;
	sectionId = other.sectionId;
	comment = other.comment;
}

/**
*   @brief Outputs information about the product.
*
*	@param out The output stream which will take the product data.
*
*	@param p The product object which data will be used for the output.
*/

std::ostream& operator<<(std::ostream& out, const Product& p)
{
	Unit unitOfMeasurement = p.getUnitOfMeasurement();
	std::string unit;
	if (unitOfMeasurement == Unit::Kilograms)
	{
		unit = "kg";
	}
	else if (unitOfMeasurement == Unit::Liters)
	{
		unit = "l";
	}

	out << p.getName() << " \"" << p.getManufacturerName() << "\" - "
		<< p.getQuantity() << unit << " section: #" << p.getSectionId()
		<< ", expires: " << p.getExpirationDate();
	return out;
}

#endif
