#ifndef _FILEIO_H
#define _FILEIO_H

#include "ShapeStorage.h"

class FileIO
{
public:
	virtual void proccesShapeStorage(ShapeStorage&) = 0;
};

#endif