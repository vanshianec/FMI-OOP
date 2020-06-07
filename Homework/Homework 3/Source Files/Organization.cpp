#ifndef _ORGANIZATION_CPP
#define _ORGANIZATION_CPP

#include "Organization.h"

Organization::Organization(const std::string& _institutionName, const std::vector<Institution*>& _institutionsList,
	const std::string& _organizationAddress) : Institution(_institutionName)
{
	institutionsList = _institutionsList;
	organizationAddress = _organizationAddress;
}

bool Organization::hasMember(const Person& user) const
{
	for (Institution* institution : institutionsList)
	{
		if (institution->hasMember(user))
		{
			return true;
		}
	}

	return false;
}

const Payer* Organization::payer() const
{
	const Payer* organizationPayer = nullptr;
	const Payer* currentPayer = nullptr;
	size_t mostAssociatedGroups = 0;

	for (Institution* institution : institutionsList)
	{
		currentPayer = institution->payer();

		if (currentPayer != nullptr && currentPayer->getAssociatedGroups() > mostAssociatedGroups)
		{
			organizationPayer = currentPayer;
			mostAssociatedGroups = organizationPayer->getAssociatedGroups();
		}
	}

	return organizationPayer;
}

bool Organization::valid() const
{
	for (Institution* institution : institutionsList)
	{
		return institution->valid();
	}

	return false;
}

void Organization::addInstitution(Institution* institution, bool shouldBeChecked)
{
	if (!shouldBeChecked || (institution->valid() && this->payer() == institution->payer()))
	{
		institutionsList.push_back(institution);
	}
}

bool Organization::operator==(Organization* otherOrganization) const
{
	return this->payer() == otherOrganization->payer();
}

#endif