#ifndef _FILEIO_H
#define _FILEIO_H

#include "ShapeStorage.h"

/// @brief Abstract visitor class allowing file input and output processes.

class FileIO
{
public:
	///@brief Reads or Writes the specified ShapeStorage object to a file.
	virtual void processShapeStorage(ShapeStorage&) = 0;
};

#endif