#ifndef _GOLD_H
#define _GOLD_H

#include "Metal.h"

class Gold : public Metal
{
public:
	Gold(const size_t _amount);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
	bool reactsWith(Element* other);
};

#endif