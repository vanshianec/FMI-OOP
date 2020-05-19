
#include <iostream>
#include <string>

#include "Gold.h"
#include "Stone.h"
#include "Energy.h"
#include "Spirit.h"

#include "Alchemist.h"
#include "ElementFactory.h"
#include "UserInput.h"
#include "FormulaFactory.h"

void readInitialElements(Alchemist& alchemist)
{
	size_t initialQuantities = 0;
	std::cout << "Enter initial quantities count: " << std::endl;
	std::cin >> initialQuantities;

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

	while (initialQuantities > 0)
	{
		UserInput input;
		input.readFormula();
		book.addFormula(FormulaFactory::createFormula(input.getParameters(), input.getResult()));
		initialQuantities--;
	}

	alchemist.setBook(book);
}


int main()
{
	/*
		-----:Example input:-----

		4
		3 Earth
		4 Fire
		1 Water
		10 Air
		9
		Air + Air = Spirit
		Metal + Stone = Gold
		Fire + Earth = Metal
		Fire + Water + Earth = Gold
		Water + Earth = Stone
		Spirit + Air = Energy
		Gold + Spirit + Earth = Philosopher's Stone
		/Fire
		Energy + Earth = Stone

	*/

	/* TODO!!! IMPORTANT!!! DELETE DYNAMMIC MEMORY AND FILTER FOR BASE ELEMNET IN ALCHEMIST CLASS*/

	Alchemist alchemist;
	readInitialElements(alchemist);
	readFormulas(alchemist);

	std::cout << "Can create Philosopher's Stone :" << std::endl;
	std::cout << (alchemist.canCreatePhilosophersStone() == 1 ? "Yes" : "No") << std::endl;
}



