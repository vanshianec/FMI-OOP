#ifndef _STONE_CPP
#define _STONE_CPP

#include "Stone.h"

Stone::Stone(const size_t _amount)
	: Fire(0), Water(0), PhilosophersStone(0), Element(_amount, "Stone") {}

#endif