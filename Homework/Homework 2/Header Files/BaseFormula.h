#ifndef _BASEFORMULA_H
#define _BASEFORMULA_H

#include <vector>
#include "Element.h"

class BaseFormula
{
private:
	std::vector<Element*> parameters;
	std::vector<Element*> result;
	std::string type;
	bool used;
protected:
	BaseFormula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result, const std::string& _type);
		
public:
	const std::vector<Element*>& getResult() const;
	const std::vector<Element*>& getParameters() const;
	const std::string& getType() const;
	bool isUsed() const;
	void setUsed(bool _used);
	virtual bool isValid() const = 0;
};

#endif