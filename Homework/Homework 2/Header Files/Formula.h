#ifndef _FORMULA_H
#define _FORMULA_H

#include <vector>
#include "Element.h"

class Formula
{
private:
	std::vector<Element*> parameters;
	std::vector<Element*> result;
	std::string type;
	bool used;

protected:
	Formula(const std::vector<Element*>& _parameters, const std::vector<Element*>& _result, const std::string& _type);
		
public:
	const  std::vector<Element*>& getResult() const;
	const  std::vector<Element*>& getParameters() const;
	const std::string& getType() const;

	bool isUsed() const;
	void setUsed(bool _used);
	virtual bool isValid() const = 0;
	~Formula();
};

#endif