#ifndef _PERSON_H
#define _PERSON_H

#include <string>

class Person
{
private:
	std::string personName;
	size_t insuranceId;
public:
	Person(const std::string& _personName, size_t _insuranceId);

	const std::string& getPersonName() const;
	size_t getInsuranceId() const;
};

#endif