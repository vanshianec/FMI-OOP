
#include <iostream>
#include <string>

#include "Gold.h"
#include "Stone.h"
#include "Energy.h"
#include "Spirit.h"

#include "Alchemist.h"
#include "ElementFactory.h"
#include "FormulaFactory.h"

void readInitialElements(Alchemist& alchemist)
{
	size_t initialQuantities = 0;
	std::cout << "Enter initial quantities count: " << std::endl;
	std::cin >> initialQuantities;
	std::cout << "Enter " << initialQuantities
		<< " initial quantities in the format <elementCount> <elementType>\n";

	size_t elementAmount;
	std::string elementType;

	while (initialQuantities > 0)
	{
		std::cin >> elementAmount >> elementType;
		alchemist.addElement(ElementFactory::createElement(elementType, elementAmount));
		initialQuantities--;
	}
}

void readFormulas(Alchemist& alchemist)
{
	Book book;
	size_t initialQuantities = 0;
	std::cout << "Enter the number of formulas you want to add: " << std::endl;
	std::cin >> initialQuantities;

	std::string formula;
	while (initialQuantities > 0)
	{
		std::cin >> formula;
		book.addFormula(FormulaFactory::createFormula(formula));
		initialQuantities--;
	}

	alchemist.setBook(book);
}


int main()
{
	//Alchemist alchemist;
	//readInitialElements(alchemist);
	//readFormulas(alchemist);

	Element* el = new Gold(5);
	std::cout << el->getType() << std::endl;
	std::cout << el->getAmount() << std::endl;

	//std::cout << el->getType() << std::endl;

}



