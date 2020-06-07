#ifndef _PAYER_H
#define _PAYER_H

#include <string>
#include <functional>

class Payer
{
private:
	std::string payerName;
	std::function<bool(size_t, size_t)>payerMemberRule;
	size_t associatedGroupsCount;
public:
	Payer(const std::string& _payerName, const std::function<bool(size_t, size_t)>& _payerMemberRule);
	bool operator==(const Payer& other) const;
	bool invokePayerMemberRule(size_t groupId, size_t insuranceId) const;
	size_t getAssociatedGroups() const;
	void incrementAssociatedGroups();

	const std::string& getPayerName() const;
};

#endif