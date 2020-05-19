#ifndef _AIR_H
#define _AIR_H

#include "PhilosophersStone.h"

class Air : public virtual PhilosophersStone
{
public:
	Air(const size_t _amount);
	bool reactsWith(Element* other);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
};

#endif