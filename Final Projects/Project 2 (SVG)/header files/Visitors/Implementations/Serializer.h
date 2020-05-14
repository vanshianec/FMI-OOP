#ifndef _SERIALIZER_H
#define _SERIALIZER_H

#include "FileIO.h"

class Serializer : public FileIO
{
public:
	void proccesShapeStorage(ShapeStorage&);
};

#endif