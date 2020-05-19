#ifndef _SPIRIT_H
#define _SPIRIT_H

#include "Air.h"

class Spirit : public Air
{
public:
	Spirit(const size_t _amount);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
	bool reactsWith(Element* other);
};

#endif