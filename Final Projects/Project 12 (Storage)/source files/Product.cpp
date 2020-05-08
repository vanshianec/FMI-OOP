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

void Product::save(std::ofstream& out)
{
	size_t len = name.length();
	out.write((char*)&len, sizeof(len));
	out.write(name.c_str(), len);
	out.write((char*)&expirationDate, sizeof(Date));
	out.write((char*)&entryDate, sizeof(Date));
	out.write((char*)&removeDate, sizeof(Date));
	len = manufacturerName.length();
	out.write((char*)&len, sizeof(len));
	out.write(manufacturerName.c_str(), len);
	out.write((char*)&unitOfMeasurement, sizeof(Unit));
	out.write((char*)&quantity, sizeof(quantity));
	out.write((char*)&sectionId, sizeof(sectionId));
	len = comment.length();
	out.write((char*)&len, sizeof(len));
	out.write(comment.c_str(), len);
}
void Product::load(std::ifstream& in)
{
	size_t len;
	in.read((char*)&len, sizeof(len));
	name.resize(len);
	in.read(&name[0], len);
	in.read((char*)&expirationDate, sizeof(Date));
	in.read((char*)&entryDate, sizeof(Date));
	in.read((char*)&removeDate, sizeof(Date));
	in.read((char*)&len, sizeof(len));
	manufacturerName.resize(len);
	in.read(&manufacturerName[0], len);
	in.read((char*)&unitOfMeasurement, sizeof(Unit));
	in.read((char*)&quantity, sizeof(quantity));
	in.read((char*)&sectionId, sizeof(sectionId));
	in.read((char*)&len, sizeof(len));
	comment.resize(len);
	in.read(&comment[0], len);
}

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


std::ostream& operator<<(std::ostream& out, const Product& p)
{
	out << p.getName() << " \"" << p.getManufacturerName() << "\" - " << p.getQuantity();
	return out;
}

#endif
