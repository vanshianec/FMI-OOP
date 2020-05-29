#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "FileIO.h"

/// @brief Class used for serializing objects.

class Serializer : public FileIO
{
public:
	/// @brief Saves all shapes in a file.
	void processShapeStorage(ShapeStorage&);
};

#endif