#ifndef _ENERGY_CPP
#define _ENERGY_CPP

#include "Energy.h"

Energy::Energy(const size_t _amount)
	: Water(0), Air(0), PhilosophersStone(0), Element(_amount, "Energy") {}

#endif