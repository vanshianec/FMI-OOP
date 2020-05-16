#ifndef _BOOK_CPP
#define _BOOK_CPP

#include "Book.h"

void Book::addFormula(Formula* formula)
{
	if (formula != nullptr)
	{
		formulas.push_back(formula);
	}
}

#endif