#ifndef __STORAGE_CPP
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
	if (product.getAvailableQuantity() + size > capacity)
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
		//todo add to added items file
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
	size_t storageAmount = 0;
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].getName() == name)
		{
			storageAmount += products[i].getAvailableQuantity();
			availableProducts.push_back(products[i]);
		}
	}

	if (storageAmount == 0)
	{
		std::cout << "No product with such name exists in the storage\n";
		return;
	}

	std::sort(availableProducts.begin(), availableProducts.end());

	size_t i = 0;
	Product product;
	while (i > 0 && amount > 0)
	{
		product = availableProducts[i];
		size_t amountToBeRemoved = std::min(amount, product.getAvailableQuantity());
		//todo add to removed binary file

		amount -= amountToBeRemoved;
		i++;
	}



}

bool Storage::addToSectionWithEnoughSpace(Product& product)
{
	for (size_t i = 0; i < sections.size(); i++)
	{
		if (sections[i].getItemsCount() + product.getAvailableQuantity() <= sections[i].getCapacity()
			&& !containsSameItem(i, product.getName()))
		{
			sections[i].addItemsCount(product.getAvailableQuantity());
			size += product.getAvailableQuantity();
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
	size_t productQuantity = product.getAvailableQuantity();

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

void Storage::load(const std::string& path)
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

void Storage::printProducts()
{
	std::vector<Product> duplicates = products;
	size_t duplicatesCount, totalQuantity;

	for (size_t i = 0; i < duplicates.size(); i++)
	{
		duplicatesCount = 0;
		totalQuantity = duplicates[i].getAvailableQuantity();
		std::cout << duplicates[i].getName();
		for (size_t j = i + 1; j < duplicates.size(); j++)
		{
			if (duplicates[j].getName() == duplicates[i].getName())
			{
				totalQuantity += duplicates[j].getAvailableQuantity();
				duplicates.erase(duplicates.begin() + j);
				duplicatesCount++;
				j--;
			}
		}

		std::cout << " - " << totalQuantity << std::endl;
		i -= duplicatesCount;
	}
}

void Storage::clear()
{
	sections.clear();
	products.clear();
	capacity = 0;
	size = 0;
}

#endif