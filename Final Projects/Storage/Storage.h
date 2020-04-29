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
	bool addDataToStorage(const std::string& data);
	bool isSection(const std::string& section) const;
	bool isProduct(const std::string& product) const;
	bool addSection(const std::string& section);
	bool addProduct(const std::string& product);
	std::string getValue(const std::string& data, const std::string& target) const;
public:
	void initStorage(const std::string& storageData);
	std::string getDataInTextFormat() const;
};

#endif