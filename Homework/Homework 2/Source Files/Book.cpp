#ifndef _BOOK_CPP
#define _BOOK_CPP

#include "Book.h"
#include "Formula.h"

void Book::addFormula(Formula* formula)
{
	/* check if there are valid elements in the formula and that they can make a reaction */
	if (formula != nullptr && formula->isValid())
	{
		formulas.push_back(formula);
	}
	else if (formula != nullptr)
	{
		delete formula;
	}
}

Formula* Book::findFormula(Element* result)
{
	for (size_t i = 0; i < formulas.size(); i++)
	{
		Formula* formula = formulas[i];
		if (formula->getType() == "Formula")
		{
			std::vector<Element*> newResult = formula->getResult();
			for (size_t j = 0; j < newResult.size(); j++)
			{
				if (newResult[j]->getType() == result->getType())
				{
					return formula;
				}
			}
		}
	}

	return nullptr;
}

Formula* Book::findEquation(Element* result)
{
	std::vector<Element*> formulaResult;

	for (Formula* formula : formulas)
	{
		formulaResult = formula->getResult();
		if (formula->getType() == "Equation" && formulaResult[0]->getType() == result->getType())
		{
			return formula;
		}
	}

	return nullptr;
}

const std::vector<Formula*> Book::filter()
{
	std::vector<Formula*> noPhilosopherStone;

	for (Formula* f : formulas)
	{
		std::vector<Element*> formulaResult = f->getResult();
		for (Element* el : formulaResult)
		{
			if (el->getType() == "Philosopher's Stone")
			{
				return sortToAchievePhilosophersStone(f);
			}
		}
	}

	return noPhilosopherStone;
}

const std::vector<Formula*> Book::sortToAchievePhilosophersStone(Formula* philosophersStoneFormula)
{
	std::vector<Element*> params = philosophersStoneFormula->getParameters();
	std::vector<Formula*> formulasForPhilosophersStone;
	formulasForPhilosophersStone.insert(formulasForPhilosophersStone.begin(), philosophersStoneFormula);

	while (params.size() > 0)
	{
		Element* nextParam = params[0];
		params.erase(params.begin());
		if (!nextParam->isBaseElement())
		{
			/* Find an equation which can give us the required element */
			Formula* f = findEquation(nextParam);

			/* If there is no such equation */
			if (f == nullptr)
			{
				/* Find a formula which can give us the required element */
				f = findFormula(nextParam);
			}

			/* If you cannot find a formula then we can't craft the stone */
			if (f == nullptr)
			{
				return std::vector<Formula*>();
			}

			if ((f->getType() == "Formula" && !f->isUsed()) || f->getType() == "Equation")
			{
				std::vector<Element*> nextFormulaParams = f->getParameters();
				for (int i = nextFormulaParams.size() - 1; i >= 0; i--)
				{
					params.insert(params.begin(), nextFormulaParams[i]);
				}

				formulasForPhilosophersStone.insert(formulasForPhilosophersStone.begin(), f);
				if (f->getType() == "Formula")
				{
					f->setUsed(true);
				}
			}
			else if (f->getType() == "Formula")
			{
				f->setUsed(false);
			}
		}
	}

	return formulasForPhilosophersStone;
}

#endif