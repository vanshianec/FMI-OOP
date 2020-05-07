#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include "Date.h"

enum class Unit
{
	Liters, Kilograms
};

class Product
{
private:
	std::string name;
	Date expirationDate;
	Date entryDate;
	Date removeDate;
	std::string manufacturerName;
	Unit unitOfMeasurement;
	size_t quantity;
	size_t sectionId;
	std::string comment;

public:
	Product();
	Product(const std::string& _name, const Date& _expirationDate, const Date& _entryDate,
		const std::string& _manufacturerName, const Unit _unitOfMeasurement,
		const size_t _quantity, const std::string& _comment);

	Product& operator=(const Product& other);
	bool operator < (const Product& other) const;
	const std::string& getName() const;
	const size_t getSectionId() const;
	const Date& getExpirationDate() const;
	const Date& getEntryDate() const;
	const Date& getRemoveDate() const;
	const size_t getQuantity() const;
	const std::string& getManufacturerName() const;
	void setSectionId(const size_t _sectionId);
	void setQuantity(const size_t _quantity);
	void setRemoveDate(const Date& _removeDate);
	void reduceQuantity(const size_t amount);
	bool operator==(const Product& other) const;

private:
	void copyValues(const Product& other);
};

std::ostream& operator<<(std::ostream& out, const Product& product);

#endif