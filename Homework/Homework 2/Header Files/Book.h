#ifndef _BOOK_H
#define _BOOK_H

#include <vector>
#include "BaseFormula.h"

class Book
{
private:
	std::vector<BaseFormula*> formulas;
	const std::vector<BaseFormula*> sortToAchievePhilosophersStone(BaseFormula* philosophersStoneFormula);
	BaseFormula* findEquation(Element* result);
	BaseFormula* findFormula(Element* result);
public:
	void addFormula(BaseFormula* formula);
	const std::vector<BaseFormula*> filter();
};

#endif