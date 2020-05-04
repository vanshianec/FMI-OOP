#ifndef __STORAGE_CPP
#define __STORAGE_CPP

#include "Storage.h"
#include <iostream>
#include <fstream>

void Storage::setCapacity(const size_t otherCapacity)
{
	totalCapacity = otherCapacity;
}

void Storage::addSection(const Section& section)
{
	sections.push_back(section);
}

void Storage::save(const std::string& path)
{
	std::ofstream out(path, std::ios::binary);
	size_t size = sections.size();

	out.write((char*)&totalCapacity, sizeof(totalCapacity));
	out.write((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		out.write((char*)&sections[i], sizeof(Section));
	}

	size = products.size();
	out.write((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		out.write((char*)&products[i], sizeof(Product));
	}

	out.close();
}

void Storage::load(const std::string& path)
{
	std::ifstream in(path, std::ios::binary);
	size_t size;
	Section s;
	Product p;

	in.read((char*)&totalCapacity, sizeof(totalCapacity));
	in.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
	{
		in.read((char*)&s, sizeof(Section));
		sections.push_back(s);
	}

	in.read((char*)&size, sizeof(size));
	for (size_t i = 0; i < size; i++)
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
	totalCapacity = 0;
}

#endif