#ifndef _DESERIALIZER_H
#define _DESERIALIZER_H

#include "FileIO.h"

/// @brief Class used for deserializing objects.

class Deserializer : public FileIO
{
public:
	/// @brief Loads all shapes from a file.
	void processShapeStorage(ShapeStorage&);
};

#endif