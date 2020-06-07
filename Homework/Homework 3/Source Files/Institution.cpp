#ifndef _INSTITUTION_CPP
#define _INSTUTITION_CPP

#include "Institution.h"

/* set the global id which keeps the count of the institutions */
size_t Institution::ID = 0;

Institution::Institution(const std::string& _institutionName) : institutionName(_institutionName)
{
	/* set a unique id for the current institution and increase the total institutions count */
	institutionId = ++ID;
}

/* create a copy which has a unique id*/
Institution::Institution(const Institution& other)
{
	institutionId = ++ID;
	institutionName = other.institutionName;
}

/* set only the name since we don't want two different institutions with the same id*/
Institution& Institution::operator=(const Institution& other)
{
	if (this != &other)
	{
		institutionName = other.institutionName;
	}

	return *this;
}

size_t Institution::totalCount()
{
	return ID;
}

size_t Institution::getInstitutionId() const
{
	return institutionId;
}

const std::string& Institution::getInstitutionName() const
{
	return institutionName;
}

Institution::~Institution()
{

}

#endif