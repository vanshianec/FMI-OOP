#ifndef _PRODUCTFACTORY_H
#define _PRODUCTFACTORY_H

#include "Product.h"

class ProductFactory
{
public:
	const static Product createProduct();
};

#endif