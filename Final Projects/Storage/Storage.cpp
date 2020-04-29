#ifndef __STORAGE_CPP
#define __STORAGE_CPP

#include "Storage.h"

bool Storage::addDataToStorage(const std::string& data)
{
	return ((isSection(data) && addSection(data)) || (isProduct(data) && addProduct(data)));
}

bool Storage::isSection(const std::string& section) const
{
	//<section.../>
	return (section.find("<section") == 0) && (section.find("/>") != std::string::npos);
}

bool Storage::isProduct(const std::string& product) const
{
	//<product.../>
	return (product.find("<product") == 0) && (product.find("/>") != std::string::npos);
}

bool Storage::addSection(const std::string& section)
{
	//example section : <section id="25" capacity="1444"/>
	std::string id = getValue(section, VALUE_ID);
	std::string capacity = getValue(section, VALUE_CAPACITY);
	Section section;
	return section.create(id, capacity);
}

bool Storage::addProduct(const std::string& product)
{
	/*
	example product :
	<product name="kiselo mlqko" expirationDate="2000-05-06" entryDate="1999-12-31"
	manufacturerName="Vereya" unitOfMeasurement="1kg" availableQuantity="43"
	section="13" comment="v dobro sustoqnie"/>
	*/
	std::string name = getValue(product, VALUE_NAME);
	std::string expirationDate = getValue(product, VALUE_EXPIRATION_DATE);
	std::string entryDate = getValue(product, VALUE_ENTRY_DATE);
	std::string manufacturerName = getValue(product, VALUE_MANUFACTURER_NAME);
	std::string unitOfMeasurement = getValue(product, VALUE_UNIT_OF_MEASUREMENT);
	std::string availableQuantity = getValue(product, VALUE_AVAILABLE_QUANTITY);
	std::string section = getValue(product, VALUE_SECTION);
	std::string comment = getValue(product, VALUE_COMMENT);

	Product product;
	return product.create(name, expirationDate, entryDate, manufacturerName,
		unitOfMeasurement, availableQuantity, section, comment);
}

std::string Storage::getValue(const std::string& data, const std::string& target) const
{
	//example : <product name="pesho"/> we want to return {pesho}>
	size_t startIndex = data.find(target);
	if (startIndex != std::string::npos)
	{
		startIndex = startIndex + target.length() + 1;
		size_t endIndex = data.find("\"", startIndex);
		if (endIndex != std::string::npos)
		{
			return data.substr(startIndex, endIndex);
		}
	}
	return "";
}

void Storage::initStorage(const std::string& storageData)
{
	size_t startIndex = 0;
	size_t endIndex = storageData.find('\n', startIndex);
	bool isAdded = true;
	while (isAdded && endIndex != std::string::npos)
	{
		isAdded = addDataToStorage(storageData.substr(startIndex, endIndex));
		startIndex = endIndex + 1;
		endIndex = storageData.find('\n', startIndex);
	}
}

std::string Storage::getDataInTextFormat() const
{
	//todo
	return "";
}

#endif