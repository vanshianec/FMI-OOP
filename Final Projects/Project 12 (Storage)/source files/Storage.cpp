﻿#ifndef __STORAGE_CPP
#define __STORAGE_CPP

#include "Storage.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Storage::Storage() : size(0), capacity(0) {}

void Storage::setCapacity(const size_t otherCapacity)
{
	capacity = otherCapacity;
}

void Storage::addSection(const Section& section)
{
	sections.push_back(section);
}

void Storage::addProduct(Product& product)
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

	size_t i = 0;
	Product removedProduct;
	while (i > 0 && amount > 0)
	{
		size_t amountToBeRemoved = std::min(amount, availableProducts[i].getQuantity());
		for (size_t j = 0; j < indices.size(); j++)
		{
			size_t index = indices[j];
			if (products[index] == availableProducts[i])
			{
				removedProduct = products[index];
				removedProduct.setQuantity(amountToBeRemoved);
				removedProducts.push_back(removedProduct);
				products[index].reduceQuantity(amountToBeRemoved);
				if (products[index].getQuantity() == 0)
				{
					products.erase(products.begin() + index);
				}
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

void Storage::save(const std::string& path)
{
	saveProducts(path);
	saveAddedProducts();
	saveRemovedProducts();
}

void Storage::saveProducts(const std::string& path)
{
	std::ofstream out(path, std::ios::binary);
	size_t count = sections.size();

	out.write((char*)&capacity, sizeof(capacity));
	out.write((char*)&size, sizeof(size));
	out.write((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		out.write((char*)&sections[i], sizeof(Section));
	}

	count = products.size();
	out.write((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		out.write((char*)&products[i], sizeof(Product));
	}

	out.close();
}

void Storage::saveAddedProducts()
{
	std::ofstream out("addedProducts.dat", std::ios::binary, std::ios::app);

	size_t len = addedProducts.size();
	out.write((char*)&len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		out.write((char*)&addedProducts[i], sizeof(Product));
	}

	out.close();
}

void Storage::saveRemovedProducts()
{
	std::ofstream out("removedProducts.dat", std::ios::binary, std::ios::app);

	size_t len = removedProducts.size();
	out.write((char*)&len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		out.write((char*)&removedProducts[i], sizeof(Product));
	}

	out.close();
}

void Storage::load(const std::string& path)
{
	loadProducts(path);
}

void Storage::loadProducts(const std::string& path)
{
	std::ifstream in(path, std::ios::binary);
	size_t count;
	Section s;
	Product p;

	in.read((char*)&capacity, sizeof(capacity));
	in.read((char*)&size, sizeof(size));
	in.read((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		in.read((char*)&s, sizeof(Section));
		sections.push_back(s);
	}

	in.read((char*)&count, sizeof(count));
	for (size_t i = 0; i < count; i++)
	{
		in.read((char*)&p, sizeof(Product));
		products.push_back(p);
	}

	in.close();
}

void Storage::loadAddedProducts()
{
	std::ifstream in("addedProducts.dat", std::ios::binary);
	size_t len;
	Product p;
	in.read((char*)len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		in.read((char*)&p, sizeof(Product));
		addedProducts.push_back(p);
	}

	in.close();
}

void Storage::loadRemovedProducts()
{
	std::ifstream in("removedProducts.dat", std::ios::binary);
	size_t len;
	Product p;
	in.read((char*)len, sizeof(len));
	for (size_t i = 0; i < len; i++)
	{
		in.read((char*)&p, sizeof(Product));
		removedProducts.push_back(p);
	}

	in.close();
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
		i -= duplicatesCount;
	}
}

void Storage::logChanges(const Date& startDate, const Date& endDate)
{
	loadAddedProducts();
	std::cout << "Products added in storage between " << startDate << " and " << endDate << std::endl;
	printAddedProductsInRange(startDate, endDate);
	loadRemovedProducts(); 
	std::cout << "Products removed from storage between " << startDate << " and " << endDate << std::endl;
	printRemovedProductsInRange(startDate, endDate);
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