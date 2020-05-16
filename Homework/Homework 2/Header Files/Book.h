#ifndef _BOOK_H
#define _BOOK_H

#include <vector>
#include "Formula.h"

class Book
{
private:
	//todo filter in the best way to achieve the creation of the Philosopher's stone
	std::vector<Formula*> formulas;
public:
	void addFormula(Formula* formula);
};

#endif