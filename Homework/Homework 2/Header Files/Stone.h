#ifndef _STONE_H
#define _STONE_H

#include "Fire.h"
#include "Water.h"

class Stone : public Fire, public Water
{
public:
	Stone(const size_t _amount);
};

#endif