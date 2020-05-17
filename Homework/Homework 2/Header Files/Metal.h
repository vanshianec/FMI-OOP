#ifndef _METAL_H
#define _METAL_H

#include "Earth.h"
#include "Fire.h"

class Metal : public Earth, public Fire
{
public:
	Metal(const size_t _amount);
};

#endif