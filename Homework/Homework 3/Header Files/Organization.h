#ifndef _ORGANIZATION_H
#define _ORGANIZATION_H

#include "Institution.h"
#include <vector>

class Organization : public Institution
{
private:
	std::vector<Institution*> institutionsList;
	std::string organizationAddress;

public:
	Organization(const std::string& _institutionName, const std::vector<Institution*>& _institutionsList, const std::string& _organizationAddress);

	bool hasMember(const Person& user) const;
	const Payer* payer() const;
	bool valid() const;
	void addInstitution(Institution* institution, bool shouldBeChecked = true);
	bool operator==(Organization* otherOrganization) const;
};

#endif