#ifndef __STORAGE_H
#define __STORAGE_H

#include "Product.h"
#include "Section.h"
#include "Constants.h"
#include <string>
#include <vector>

class Storage
{
	//TODO ADDED PRODUCTS AND REMOVED PRODUCTS FUNCTION OF HIGHER LEVEL!
private:
	std::vector<Product> products;
	std::vector<Product> addedProducts;
	std::vector<Product> removedProducts;
	std::vector<Section> sections;
	size_t capacity;
	size_t size;
	void addAvailableProducts(const std::string& name, size_t& storageAmount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	void removeAvailableProducts(size_t& amount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	bool addToSectionWithSameExpirationDate(Product& product);
	bool addToSectionWithEnoughSpace(Product& product);
	bool containsSameItem(const size_t id, const std::string& productName);
	void saveAddedProducts();
	void loadAddedProducts();
	void saveRemovedProducts();
	void loadRemovedProducts();

public:
	Storage();
	void setCapacity(const size_t otherCapacity);
	void addSection(const Section& sections);
	void addProduct(Product& product);
	void removeProduct(const std::string& name, size_t amount);
	void save(const std::string& path);
	void saveProducts(const std::string& path);
	void load(const std::string& path);
	void loadProducts(const std::string& path);
	void printProducts();
	void logChanges(const Date& startDate, const Date& endDate);
	void clear();
};

#endif