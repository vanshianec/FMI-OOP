#ifndef __STORAGE_H
#define __STORAGE_H

#include "Product.h"
#include "Section.h"
#include <string>
#include <vector>

/// @brief Class used for keeping information about products and sections.

class Storage : public Visible
{

private:
	/// @brief List of all products inside the storage.
	std::vector<Product> products;
	/// @brief List of all products which were added later in the storage.
	std::vector<Product> addedProducts;
	/// @brief List of all products removed from the storage.
	std::vector<Product> removedProducts;
	/// @brief List of all sections inside the storage.
	std::vector<Section> sections;
	/// @brief The total capacity of the storage.
	size_t capacity;
	/// @brief The amount of current products in the storage.
	size_t size;

public:
	Storage();

	const std::vector<Section>& getSections() const;
	const std::vector<Product>& getProducts() const;
	const std::vector<Product>& getAddedProducts() const;
	const std::vector<Product>& getRemovedProducts() const;
	const size_t getCapacity() const;
	const size_t getSize() const;
	void setCapacity(const size_t);
	void setSize(const size_t);

	/// @brief Applies modifications to this object with the help of a visitor object.
	void accept(Visitor*);
	/// @brief Adds a section object to the storage.
	void addSection(const Section&);
	/// @brief Adds a product object to the storage.
	void addProduct(const Product&);
	/// @brief Adds a product to an added products list which keeps track of products which weren't initaliy inside the storage.
	void addAddedProduct(const Product&);
	/// @brief Adds a product to a removed products list which keeps track of products which are removed from the storage.
	void addRemovedProduct(const Product&);
	/// @brief Adds a new product to the storage which wasn't initialy inside the storage.
	void addNewProduct(Product&);
	/// @brief Removes a product from the storage by a given name and amount.
	void removeProduct(const std::string& name, size_t amount);
	/// @brief Prints all product types in the storage.
	void printProducts();
	/// @brief Prints all changes inside the storage between two dates.
	void logChanges(const Date& startDate, const Date& endDate);
	/// @brief Removes all products from the storage which are about to expire or are already expired.
	void clean();
	/// @brief Clears all the data which the storage object contains.
	void clear();

private:
	/// @brief Adds all products available in the storage by the given product name in a product list.
	void addAvailableProducts(const std::string& name, size_t& storageAmount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	/// @brief Removes all products from the storage which are contained in the availableProducts list.
	void removeAvailableProducts(size_t& amount, std::vector<Product>& availableProducts, std::vector<size_t>& indices);
	/// @brief Adds a product to a section which contains the same product type with the same expiration date.
	bool addToSectionWithSameExpirationDate(Product&);
	/// @brief Adds a product to a section which has enough space for it and does not contain a product of the same type.
	bool addToSectionWithEnoughSpace(Product&);
	/// @brief Checks if a section already contains the given product.
	bool containsSameItem(const size_t id, const std::string& productName);
	/// @brief Prints all products which were added or removed from the storage between two given dates.
	void printProductsInRange(const Date& startDate, const Date& endDate);
};

#endif