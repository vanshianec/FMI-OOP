#ifndef _DESERIALIZER_H
#define _DESERIALIZER_H

#include "Visitor.h"

class Deserializer : public Visitor
{
private:
	std::ifstream in;
public:
	void proccesProduct(Product&);
	void proccesStorage(Storage&);
};

void loadProducts(std::ifstream& in, Storage& storage, Deserializer* _this);
void loadAddedProducts(std::ifstream& in, Storage& storage, Deserializer* _this);
void loadRemovedProducts(std::ifstream& in, Storage& storage, Deserializer* _this);

#endif
