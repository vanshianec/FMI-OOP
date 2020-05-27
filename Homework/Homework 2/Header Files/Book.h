#ifndef _BOOK_H
#define _BOOK_H

#include <vector>
#include "Formula.h"

class Book
{
private:
	std::vector<Formula*> formulas;
	const std::vector<Formula*> sortToAchievePhilosophersStone(Formula* philosophersStoneFormula);
	Formula* findEquation(Element* result);
	Formula* findFormula(Element* result);
public:
	void addFormula(Formula* formula);
	const std::vector<Formula*> filter();
};

#endif