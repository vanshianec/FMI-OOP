#ifndef _ENERGY_H
#define _ENERGY_H

#include "Water.h"
#include "Air.h"

class Energy : public Water, public Air
{
public:
	Energy(const size_t _amount);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
	bool reactsWith(Element* other);
};

#endif