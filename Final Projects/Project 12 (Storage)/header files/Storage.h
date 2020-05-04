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
	size_t totalCapacity;
public:
	void setCapacity(const size_t otherCapacity);
	void addSection(const Section& sections);
	void save(const std::string& path);
	void load(const std::string& path);
	void printProducts();
	void clear();
};

#endif