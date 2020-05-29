#ifndef _DESERIALIZER_CPP
#define _DESERIALIZER_CPP

#include "Deserializer.h"
#include "FileUtil.h"

/**
*   @brief Loads a product from a file.
*
*   @param product A product object to be loaded from the file.
*/

void Deserializer::proccesProduct(Product& product)
{
	std::string name, manufacturerName, comment;
	Date expirationDate, entryDate, removeDate;
	Unit unitOfMeasurement;
	size_t len, quantity, sectionId;
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

	product.setName(name);
	product.setManufacturerName(manufacturerName);
	product.setComment(comment);
	product.setExpirationDate(expirationDate);
	product.setEntryDate(entryDate);
	product.setRemoveDate(removeDate);
	if (unitOfMeasurement == Unit::Kilograms)
	{
		product.setUnitOfMeasuremnet("kg");
	}
	else
	{
		product.setUnitOfMeasuremnet("l");
	}
	product.setQuantity(quantity);
	product.setSectionId(sectionId);
}

/**
*   @brief Loads all the information about the storage from a file.
*
*   @param storage A storage object which will be loaded from the file.
*/

void Deserializer::proccesStorage(Storage& storage)
{
	loadProducts(in, storage, this);
	loadAddedProducts(in, storage, this);
	loadRemovedProducts(in, storage, this);
}

/**
*   @brief Loads all of the available products from the file.
*
*   @param in File input stream which will load the information about the products from a file.
*
*   @param storage A storage object to be loaded from the file.
*
*   @param _this A deserializer object used to deserialize each product object individualy.
*/

void loadProducts(std::ifstream& in, Storage& storage, Deserializer* _this)
{
	in.open(FileUtil::path, std::ios::binary);
	size_t count, capacity, size;
	Section s;
	Product p;

	in.read((char*)&capacity, sizeof(capacity));
	in.read((char*)&size, sizeof(size));
	in.read((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		in.read((char*)&s, sizeof(Section));
		storage.addSection(s);
	}

	in.read((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		p.accept(_this);
		storage.addProduct(p);
	}

	storage.setCapacity(capacity);
	storage.setSize(size);

	in.close();
}

/**
*   @brief Loads all of the products products added lately to the storage from the file.
*
*   @param in File input stream which will load the information about the products from a file.
*
*   @param storage A storage object to be loaded from the file.
*
*   @param _this A deserializer object used to deserialize each product object individualy.
*/

void loadAddedProducts(std::ifstream& in, Storage& storage, Deserializer* _this)
{
	in.open("added.bin", std::ios::binary);
	size_t len;
	Product p;
	in.read((char*)&len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		p.accept(_this);
		storage.addAddedProduct(p);
	}

	in.close();
}

/**
*   @brief Loads all of the products removed from the storage from the file.
*
*   @param in File input stream which will load the information about the products from a file.
*
*   @param storage A storage object to be loaded from the file.
*
*   @param _this A deserializer object used to deserialize each product object individualy.
*/

void loadRemovedProducts(std::ifstream& in, Storage& storage, Deserializer* _this)
{
	in.open("removed.bin", std::ios::binary);
	size_t len;
	Product p;
	in.read((char*)&len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		p.accept(_this);
		storage.addRemovedProduct(p);
	}

	in.close();
}

#endif