#ifndef __STORAGE_H
#define __STORAGE_H

#include "Product.h"
#include "Section.h"
#include <string>
#include <vector>

class Storage : public Visible
{

private:
	std::vector<Product> products;
	std::vector<Product> addedProducts;
	std::vector<Product> removedProducts;
	std::vector<Section> sections;
	size_t capacity;
	size_t size;

public:
	Storage();

	void accept(Visitor*);

	const std::vector<Section>& getSections() const;
	const std::vector<Product>& getProducts() const;
	const std::vector<Product>& getAddedProducts() const;
	const std::vector<Product>& getRemovedProducts() const;
	const size_t getCapacity() const;
	const size_t getSize() const;

	void setCapacity(const size_t);
	void setSize(const size_t);

	void addSection(const Section&);
	void addProduct(const Product&);
	void addAddedProduct(const Product&);
	void addRemovedProduct(const Product&);

	void addNewProduct(Product&);
	void removeProduct(const std::string& name, size_t amount);
	void printProducts();
	void logChanges(const Date& startDate, const Date& endDate);
	void clean();
	void clear();

private:
	void addAvailableProducts(const std::string& name, size_t& storageAmount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	void removeAvailableProducts(size_t& amount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	bool addToSectionWithSameExpirationDate(Product&);
	bool addToSectionWithEnoughSpace(Product&);
	bool containsSameItem(const size_t id, const std::string& productName);
	void printProductsInRange(const Date& startDate, const Date& endDate);
};

#endif