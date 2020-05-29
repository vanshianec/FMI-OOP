#ifndef _DESERIALIZER_H
#define _DESERIALIZER_H

#include "Visitor.h"

/// Class used to deserialize objects.

class Deserializer : public Visitor
{
private:
	/// @brief Input stream object which will load the data from a file.
	std::ifstream in;
public:
	/// @brief Loads a product from a file.
	void proccesProduct(Product&);
	/// @brief Loads all the information about the storage from a file.
	void proccesStorage(Storage&);
};

/// @brief Loads all of the available products from the file.
void loadProducts(std::ifstream& in, Storage& storage, Deserializer* _this);
/// @brief Loads all of the products products added lately to the storage from the file.
void loadAddedProducts(std::ifstream& in, Storage& storage, Deserializer* _this);
/// @brief Loads all of the products removed from the storage from the file.
void loadRemovedProducts(std::ifstream& in, Storage& storage, Deserializer* _this);

#endif
