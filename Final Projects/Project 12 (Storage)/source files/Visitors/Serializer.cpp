#ifndef _SERIALIZER_CPP
#define _SERIALIZER_CPP

#include "Serializer.h"
#include "FileUtil.h"

/**
*   @brief Saves the product inside a file.
*
*   @param product A product object used to represent information about a product.
*/

void Serializer::proccesProduct(Product& p)
{
	size_t len = p.getName().length();
	out.write((char*)&len, sizeof(len));
	out.write(p.getName().c_str(), len);
	out.write((char*)&p.getExpirationDate(), sizeof(Date));
	out.write((char*)&p.getEntryDate(), sizeof(Date));
	out.write((char*)&p.getRemoveDate(), sizeof(Date));
	len = p.getManufacturerName().length();
	out.write((char*)&len, sizeof(len));
	out.write(p.getManufacturerName().c_str(), len);
	Unit unit = p.getUnitOfMeasurement();
	out.write((char*)&unit, sizeof(Unit));
	size_t quantity = p.getQuantity();
	size_t sectionId = p.getSectionId();
	out.write((char*)&quantity, sizeof(quantity));
	out.write((char*)&sectionId, sizeof(sectionId));
	len = p.getComment().length();
	out.write((char*)&len, sizeof(len));
	out.write(p.getComment().c_str(), len);
}

/**
*   @brief Saves all the information about the storage inside a file.
*
*   @param storage A storage object containing the information about the products.
*/

void Serializer::proccesStorage(Storage& storage)
{
	saveProducts(storage, out, this);
	saveAddedProducts(storage, out, this);
	saveRemovedProducts(storage, out, this);
}

/**
*   @brief Saves all of the current products inside the storage.
*
*   @param storage A storage object containing the information about the products.
*
*   @param out File output stream which will save the information about the products inside a file.
*
*   @param _this A serializer object used to serialize each product object individualy.
*/

void saveProducts(const Storage& storage, std::ofstream& out, Serializer* _this)
{
	out.open(FileUtil::path, std::ios::binary);

	std::vector<Section> sections = storage.getSections();
	size_t count = sections.size();
	size_t capacity = storage.getCapacity();
	size_t size = storage.getSize();

	out.write((char*)&capacity, sizeof(capacity));
	out.write((char*)&size, sizeof(size));
	out.write((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		out.write((char*)&sections[i], sizeof(Section));
	}

	std::vector<Product> products = storage.getProducts();
	count = products.size();
	out.write((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		products[i].accept(_this);
	}

	out.close();
}

/**
*   @brief Saves all of the newly added products in the storage.
*
*   @param storage A storage object containing the information about the products.
*
*   @param out File output stream which will save the information about the products inside a file.
*
*   @param _this A serializer object used to serialize each product object individualy.
*/

void saveAddedProducts(const Storage& storage, std::ofstream& out, Serializer* _this)
{
	out.open("added.bin", std::ios::binary);

	std::vector<Product> addedProducts = storage.getAddedProducts();
	size_t len = addedProducts.size();
	out.write((char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++)
	{
		addedProducts[i].accept(_this);
	}

	out.close();
}

/**
*   @brief Saves all of the removed products from the storage.
*
*   @param storage A storage object containing the information about the products.
*
*   @param out File output stream which will save the information about the products inside a file.
*
*   @param _this A serializer object used to serialize each product object individualy.
*/

void saveRemovedProducts(const Storage& storage, std::ofstream& out, Serializer* _this)
{
	out.open("removed.bin", std::ios::binary);

	std::vector<Product> removedProducts = storage.getRemovedProducts();
	size_t len = removedProducts.size();
	out.write((char*)&len, sizeof(len));

	for (size_t i = 0; i < len; i++)
	{
		removedProducts[i].accept(_this);
	}

	out.close();
}


#endif