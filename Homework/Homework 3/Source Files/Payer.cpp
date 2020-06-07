#ifndef _PAYER_CPP
#define _PAYER_CPP

#include "Payer.h"

Payer::Payer(const std::string& _payerName, const std::function<bool(size_t, size_t)>& _payerMemberRule)
{
	payerName = _payerName;
	payerMemberRule = _payerMemberRule;
}

bool Payer::invokePayerMemberRule(size_t groupId, size_t insuranceId) const
{
	return payerMemberRule(groupId, insuranceId);
}

size_t Payer::getAssociatedGroups() const
{
	return associatedGroupsCount;
}

void Payer::incrementAssociatedGroups()
{
	associatedGroupsCount++;
}

const std::string& Payer::getPayerName() const
{
	return payerName;
}

bool Payer::operator==(const Payer& other) const
{
	return payerName == other.payerName;
}

#endif