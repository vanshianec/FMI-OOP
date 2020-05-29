#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "Visitor.h"

/// @brief Class used to serializer objects.

class Serializer : public Visitor
{
private:
	/// @brief Output stream object which will save the data inside a file.
	std::ofstream out;
public:
	/// @brief Saves the product inside a file.
	void proccesProduct(Product&);
	/// @brief Saves all the information about the storage inside a file.
	void proccesStorage(Storage&);
};

/// @brief Saves all of the current products inside the storage.
void saveProducts(const Storage& storage, std::ofstream& out, Serializer* _this);
/// @brief Saves all of the newly added products in the storage.
void saveAddedProducts(const Storage& storage, std::ofstream& out, Serializer* _this);
/// @brief Saves all of the removed products from the storage.
void saveRemovedProducts(const Storage& storage, std::ofstream& out, Serializer* _this);

#endif