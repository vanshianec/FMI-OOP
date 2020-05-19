#ifndef _USERINPUT_CPP
#define _USERINPUT_CPP

#include <string>
#include <iostream>
#include "UserInput.h"
#include "ElementFactory.h"

void UserInput::readFormula()
{
	std::string inputParam;
	std::cin >> inputParam;

	if (inputParam.find("/") == 0)
	{
		std::string elementType = inputParam.substr(1);
		parameters.push_back(ElementFactory::createElement(elementType, 1));
		Element* element = ElementFactory::createElement(elementType, 2);
		if (elementType == "Philosopher's stone" || elementType == "Earth"
			|| elementType == "Fire" || elementType == "Water" || elementType == "Air")
		{
			result.push_back(element);
		}
		else
		{
			for (Element* el : element->baseElements())
			{
				result.push_back(el);
			}
		}
	}
	else
	{
		parameters.push_back(ElementFactory::createElement(inputParam, 1));
		std::string _operator;
		std::cin >> _operator;
		while (_operator != "=")
		{
			std::cin >> inputParam;
			parameters.push_back(ElementFactory::createElement(inputParam, 1));
			std::cin >> _operator;
		}

		std::getline(std::cin, inputParam);
		/* substr(1) to remove the whitespace */
		result.push_back(ElementFactory::createElement(inputParam.substr(1), 1));
	}
}

const std::vector<Element*>& UserInput::getParameters() const
{
	return parameters;
}
const std::vector<Element*>& UserInput::getResult() const
{
	return result;
}

#endif