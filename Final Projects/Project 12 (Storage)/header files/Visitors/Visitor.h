#ifndef _VISITOR_H
#define _VISITOR_H

#include "Product.h"
#include "Storage.h"

/// @brief Abstract class using the visitor design pattern to process product and storage objects.

class Visitor
{
public:
	virtual void proccesProduct(Product&) = 0;
	virtual void proccesStorage(Storage&) = 0;
};

#endif