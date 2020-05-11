#ifndef __STORAGE_CPP
#define __STORAGE_CPP

#include "Storage.h"
#include "Visitor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Storage::Storage() : size(0), capacity(0) {}

void Storage::accept(Visitor* visitor)
{
	visitor->proccesStorage(*this);
}

const std::vector<Section>& Storage::getSections() const
{
	return sections;
}

const std::vector<Product>& Storage::getProducts() const
{
	return products;
}

const std::vector<Product>& Storage::getAddedProducts() const
{
	return addedProducts;
}

const std::vector<Product>& Storage::getRemovedProducts() const
{
	return removedProducts;
}

const size_t Storage::getCapacity() const
{
	return capacity;
}

const size_t Storage::getSize() const
{
	return size;
}

void Storage::setCapacity(const size_t otherCapacity)
{
	capacity = otherCapacity;
}

void Storage::setSize(const size_t otherSize)
{
	size = otherSize;
}

void Storage::addSection(const Section& section)
{
	sections.push_back(section);
}

void Storage::addProduct(const Product& product)
{
	products.push_back(product);
}

void Storage::addAddedProduct(const Product& product)
{
	addedProducts.push_back(product);
}

void Storage::addRemovedProduct(const Product& product)
{
	removedProducts.push_back(product);
}

void Storage::addNewProduct(Product& product)
{
	if (product.getQuantity() + size > capacity)
	{
		std::cout << "There is no space left in the storage for this product!\n";
		return;
	}

	bool added = addToSectionWithSameExpirationDate(product);

	if (!added)
	{
		added = addToSectionWithEnoughSpace(product);
	}

	if (added)
	{
		addedProducts.push_back(product);
		products.push_back(product);
	}
	else
	{
		std::cout << "There is no space in the sections for this product!\n";
	}
}

void Storage::removeProduct(const std::string& name, size_t amount)
{
	//todo refactor this mess
	std::vector<Product> availableProducts;
	std::vector<size_t> indices;
	size_t storageAmount = 0;

	addAvailableProducts(name, storageAmount, availableProducts, indices);

	if (storageAmount == 0)
	{
		std::cout << "No product with such name exists in the storage\n";
		return;
	}

	if (amount > storageAmount)
	{
		//todo print current products;
		return;
	}

	removeAvailableProducts(amount, availableProducts, indices);
}

void Storage::removeAvailableProducts(size_t& amount, std::vector<Product>& availableProducts, std::vector<size_t>& indices)
{
	std::sort(availableProducts.begin(), availableProducts.end());

	size_t i = 0, removedCount = 0;
	Product removedProduct;
	while (i < availableProducts.size() && amount > 0)
	{
		size_t amountToBeRemoved = std::min(amount, availableProducts[i].getQuantity());
		for (size_t j = 0; j < indices.size(); j++)
		{
			size_t index = indices[j];
			if (availableProducts[i] == products[index])
			{
				removedProduct = products[index];
				removedProduct.setQuantity(amountToBeRemoved);
				removedProduct.setRemoveDate(CURRENT_DATE.c_str());
				removedProducts.push_back(removedProduct);
				products[index].reduceQuantity(amountToBeRemoved);
				if (products[index].getQuantity() == 0)
				{
					products.erase(products.begin() + index - removedCount);
					removedCount++;
				}
				break;
			}
		}

		amount -= amountToBeRemoved;
		i++;
	}
}

void Storage::addAvailableProducts(const std::string& name, size_t& storageAmount, std::vector<Product>& availableProducts, std::vector<size_t>& indices)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].getName() == name)
		{
			storageAmount += products[i].getQuantity();
			availableProducts.push_back(products[i]);
			indices.push_back(i);
		}
	}
}

bool Storage::addToSectionWithEnoughSpace(Product& product)
{
	for (size_t i = 0; i < sections.size(); i++)
	{
		if (sections[i].getItemsCount() + product.getQuantity() <= sections[i].getCapacity()
			&& !containsSameItem(i, product.getName()))
		{
			sections[i].addItemsCount(product.getQuantity());
			size += product.getQuantity();
			product.setSectionId(i);
			return true;
		}
	}

	return false;
}

bool Storage::containsSameItem(const size_t id, const std::string& productName)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].getName() == productName && products[i].getSectionId() == id)
		{
			return true;
		}
	}

	return false;
}

bool Storage::addToSectionWithSameExpirationDate(Product& product)
{
	Product p;
	Section s;
	size_t productQuantity = product.getQuantity();

	for (size_t i = 0; i < products.size(); i++)
	{
		p = products[i];
		s = sections[p.getSectionId()];
		if (p.getName() == product.getName()
			&& p.getExpirationDate() == product.getExpirationDate()
			&& s.getItemsCount() + productQuantity <= s.getCapacity())
		{
			sections[p.getSectionId()].addItemsCount(productQuantity);
			size += productQuantity;
			product.setSectionId(p.getSectionId());
			return true;
		}
	}

	return false;
}

void Storage::printProducts()
{
	std::vector<Product> duplicates = products;
	size_t duplicatesCount, totalQuantity;

	for (size_t i = 0; i < duplicates.size(); i++)
	{
		duplicatesCount = 0;
		totalQuantity = duplicates[i].getQuantity();
		std::cout << duplicates[i].getName();
		for (size_t j = i + 1; j < duplicates.size(); j++)
		{
			if (duplicates[j].getName() == duplicates[i].getName())
			{
				totalQuantity += duplicates[j].getQuantity();
				duplicates.erase(duplicates.begin() + j);
				duplicatesCount++;
				j--;
			}
		}

		std::cout << " - " << totalQuantity << std::endl;
	}
}

void Storage::logChanges(const Date& startDate, const Date& endDate)
{
	std::sort(addedProducts.begin(), addedProducts.end(),
		[](const Product& lhs, const Product& rhs)
		{
			return lhs.getEntryDate() < rhs.getEntryDate();
		});

	std::sort(removedProducts.begin(), removedProducts.end(),
		[](const Product& lhs, const Product& rhs)
		{
			return lhs.getRemoveDate() < rhs.getRemoveDate();
		});

	printProductsInRange(startDate, endDate);
}

void Storage::printProductsInRange(const Date& startDate, const Date& endDate)
{
	std::cout << "Products added in storage between " << startDate << " and " << endDate << " :\n";

	//TODO TRY FOR EACH CYCLE

	Product p;
	for (size_t i = 0; i < addedProducts.size(); i++)
	{
		p = addedProducts[i];
		if (p.getEntryDate() >= startDate && p.getEntryDate() <= endDate)
		{
			std::cout << p << ", " << p.getEntryDate() << std::endl;
		}
	}

	std::cout << "Products removed from storage between " << startDate << " and " << endDate << " :\n";

	for (size_t i = 0; i < removedProducts.size(); i++)
	{
		p = removedProducts[i];
		if (p.getRemoveDate() >= startDate && p.getRemoveDate() <= endDate)
		{
			std::cout << p << ", " << p.getRemoveDate() << std::endl;
		}
	}
}

void Storage::clean()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].getExpirationDate() <= CURRENT_DATE.c_str())
		{
			std::cout << "Cleaned product : " << products[i] << std::endl;
			products[i].setRemoveDate(CURRENT_DATE.c_str());
			removedProducts.push_back(products[i]);
			products.erase(products.begin() + i);
			i--;
		}
	}
}

void Storage::clear()
{
	sections.clear();
	products.clear();
	addedProducts.clear();
	removedProducts.clear();
	capacity = 0;
	size = 0;
}

#endif