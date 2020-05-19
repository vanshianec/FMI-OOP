#ifndef _USERINPUT_H
#define _USERINPUT_H

#include <vector>
#include "Element.h"

class UserInput
{
private:
	std::vector<Element*> parameters;
	std::vector<Element*> result;

public:
	void readFormula();

	const std::vector<Element*>& getParameters() const;
	const std::vector<Element*>& getResult() const;
};

#endif