#ifndef ALCHEMIST_H
#define ALCHEMIST_H

#include "Element.h"
#include "Book.h"

class Alchemist
{
private:
	Book book;
	std::vector<Element*> elements;
	bool removedElement(Element* param, std::vector<Element*>& requiredElements);
public:
	void setBook(const Book& other);

	bool canCreatePhilosophersStone();
	void addElement(Element* element);

	~Alchemist();
};

#endif