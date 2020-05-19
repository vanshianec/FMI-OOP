#ifndef _EARTH_H
#define _EARTH_H

#include "PhilosophersStone.h"

class Earth : public virtual PhilosophersStone
{
public:
	Earth(const size_t _amount);
	bool reactsWith(Element* other);
	const std::vector<Element*> composingElements() const;
	bool isBaseElement() const;
};

#endif