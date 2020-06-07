#ifndef _PERSON_CPP
#define _PERSON_CPP

#include "Person.h"

Person::Person(const std::string& _personName, size_t _insuranceId)
{
	personName = _personName;
	insuranceId = _insuranceId;
}

const std::string& Person::getPersonName() const
{
	return personName;
}

size_t Person::getInsuranceId() const
{
	return insuranceId;
}

#endif