#ifndef _PHILOSOPHERSSTONE_H
#define _PHILOSOPHERSSTONE_H

#include "Element.h"

class PhilosophersStone : public virtual Element
{

public:
	PhilosophersStone(const size_t _amount);
	bool reactsWith(Element* other);
	const std::vector<Element*> baseElements() const;
	bool isBaseElement() const;
protected:
	bool composedReactsWith(Element* _this, Element* other);
	bool baseReactsWith(Element* _this, Element* other);
private:
	void clearData(std::vector<Element*>& data) const;
};

#endif