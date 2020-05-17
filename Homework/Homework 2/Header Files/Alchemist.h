#ifndef ALCHEMIST_H
#define ALCHEMIST_H

#include "Element.h"
#include "Book.h"

class Alchemist
{
private:
	Book book;
	std::vector<Element*> elements;
public:
	void setBook(const Book& other);

	//bool canCreatePhilosophersStone() const;
	void addElement(Element* element);
};

#endif