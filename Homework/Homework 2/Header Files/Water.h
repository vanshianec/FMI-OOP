#ifndef _WATER_H
#define _WATER_H

#include "PhilosophersStone.h"

class Water : public virtual PhilosophersStone
{
public:
	Water(const size_t _amount);
	bool reactsWith(Element* other);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
};

#endif