#ifndef _PRODUCTFACTORY_H
#define _PRODUCTFACTORY_H

#include "Product.h"

/// @brief Class used to create product objects.

class ProductFactory
{
public:
	/// @brief Creates and returns a product object.
	const static Product createProduct(const std::vector<std::string>& params);
};

#endif