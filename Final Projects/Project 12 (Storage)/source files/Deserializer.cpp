#ifndef _DESERIALIZER_CPP
#define _DESERIALIZER_CPP

#include "Deserializer.h"
#include "FileUtil.h"

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

void Deserializer::proccesStorage(Storage& storage)
{
	loadProducts(in, storage, this);
	loadAddedProducts(in, storage, this);
	loadRemovedProducts(in, storage, this);
}

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