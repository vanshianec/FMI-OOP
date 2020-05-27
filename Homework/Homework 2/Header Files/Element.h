#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string>
#include <vector>

class Element
{
private:
	size_t amount;
	std::string type;
protected:
	Element(const size_t _amount, const std::string& _type);
public:
	const std::string& getType() const;
	const size_t getAmount() const;
	void setAmount(const size_t _amount);

	virtual bool reactsWith(Element* other) = 0;
	virtual const std::vector<Element*> baseElements() const = 0;
	virtual bool isBaseElement() const = 0;
	virtual ~Element();
};

#endif