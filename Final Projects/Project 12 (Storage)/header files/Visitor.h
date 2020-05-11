#ifndef _VISITOR_H
#define _VISITOR_H

#include "Product.h"
#include "Storage.h"

class Visitor
{
public:
	virtual void proccesProduct(Product&) = 0;
	virtual void proccesStorage(Storage&) = 0;
};

#endif