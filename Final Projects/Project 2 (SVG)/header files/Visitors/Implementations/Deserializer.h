#ifndef _DESERIALIZER_H
#define _DESERIALIZER_H

#include "FileIO.h"

class Deserializer : public FileIO
{
public:
	void proccesShapeStorage(ShapeStorage&);
};

#endif