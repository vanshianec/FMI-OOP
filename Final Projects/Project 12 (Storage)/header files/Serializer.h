#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "Visitor.h"

class Serializer : public Visitor
{
private:
	std::ofstream out;
public:
	void proccesProduct(Product&);
	void proccesStorage(Storage&);
};

void saveProducts(const Storage& storage, std::ofstream& out, Serializer* _this);
void saveAddedProducts(const Storage& storage, std::ofstream& out, Serializer* _this);
void saveRemovedProducts(const Storage& storage, std::ofstream& out, Serializer* _this);

#endif