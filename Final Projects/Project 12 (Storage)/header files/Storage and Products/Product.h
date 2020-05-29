#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include "Date.h"
#include "Visible.h"
#include "Unit.h";

/// @brief Class containing information about a product.

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
		const std::string& _manufacturerName, const std::string& _unitOfMeasurement,
		const size_t _quantity, const std::string& _comment);

	/// @brief Allows the usage of operator '=' on Product objects.
	Product& operator=(const Product& other);
	/// @brief Compares two products with operator '<' by expirataion date.
	bool operator < (const Product& other) const;
	/// @brief Compares two products with operator '==' (checks if they are equal).
	bool operator==(const Product&) const;
	/// @brief Applies modifications to this object with the help of a visitor object.
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
	void setUnitOfMeasuremnet(const std::string&);
	void setSectionId(const size_t);
	void setQuantity(const size_t);
	/// @brief Reduces the quantity of the product.
	void reduceQuantity(const size_t);

private:
	/// @brief Copies the parameters of an other product to this one.
	void copyValues(const Product& other);
};

/// @brief Outputs information about the product.
std::ostream& operator<<(std::ostream& out, const Product& product);

#endif