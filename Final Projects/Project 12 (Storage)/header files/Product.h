#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include "Date.h"
#include "Visible.h"

//TODO EXTRACT TO HEADER FILE
enum class Unit
{
	Liters, Kilograms
};

class Product : public Visible
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
	bool operator==(const Product&) const;

	void accept(Visitor*);

	const std::string& getName() const;
	const std::string& getManufacturerName() const;
	const Date& getExpirationDate() const;
	const Date& getEntryDate() const;
	const Date& getRemoveDate() const;
	const Unit getUnitOfMeasurement() const;
	const size_t getQuantity() const;
	const size_t getSectionId() const;
	const std::string& getComment() const;

	void setName(const std::string&);
	void setManufacturerName(const std::string&);
	void setComment(const std::string&);
	void setExpirationDate(const Date&);
	void setEntryDate(const Date&);
	void setRemoveDate(const Date&);
	void setUnitOfMeasuremnet(const Unit&);
	void setSectionId(const size_t);
	void setQuantity(const size_t);
	void reduceQuantity(const size_t);

private:
	void copyValues(const Product& other);
};

std::ostream& operator<<(std::ostream& out, const Product& product);

#endif