#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string>

class Element
{
private:
	size_t amount;
	std::string type;
protected:
	Element(const size_t _amount, const std::string& _type);
	//virtual bool reactsWith(Element* other) = 0;
public:
	const std::string& getType() const;
	const size_t getAmount() const;
};

#endif