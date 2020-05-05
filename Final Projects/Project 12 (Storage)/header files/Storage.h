#ifndef __STORAGE_H
#define __STORAGE_H

#include "Product.h"
#include "Section.h"
#include "Constants.h"
#include <string>
#include <vector>

class Storage
{

private:
	std::vector<Product> products;
	std::vector<Section> sections;
	size_t capacity;
	size_t size;
public:
	Storage();
	void setCapacity(const size_t otherCapacity);
	void addSection(const Section& sections);
	void addProduct(Product& product);
	void removeProduct(const std::string& name, size_t amount);
	bool addToSectionWithSameExpirationDate(Product& product);
	bool addToSectionWithEnoughSpace(Product& product);
	bool containsSameItem(const size_t id, const std::string& productName);
	void save(const std::string& path);
	void load(const std::string& path);
	void printProducts();
	void clear();
};

#endif