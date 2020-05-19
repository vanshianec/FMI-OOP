#ifndef _FIRE_H
#define _FIRE_H

#include "PhilosophersStone.h"

class Fire : public virtual PhilosophersStone
{
public:
	Fire(const size_t _amount);
	bool reactsWith(Element* other);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
};

#endif
