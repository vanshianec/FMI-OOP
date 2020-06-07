#ifndef _GROUP_CPP
#define _GROUP_CPP

#include "Group.h"

Group::Group(const std::string& _institutionName, size_t _groupId, Payer* _groupPayer)
	: Institution(_institutionName)
{
	groupId = _groupId;
	groupPayer = _groupPayer;

	if (groupPayer != nullptr)
	{
		groupPayer->incrementAssociatedGroups();
	}
}

const Payer* Group::payer() const
{
	return groupPayer;
}

bool Group::valid() const
{
	return groupPayer != nullptr;
}

bool Group::hasMember(const Person& user) const
{
	if (valid())
	{
		return groupPayer->invokePayerMemberRule(groupId, user.getInsuranceId());
	}

	return false;
}

size_t Group::getGroupId() const
{
	return groupId;
}


#endif