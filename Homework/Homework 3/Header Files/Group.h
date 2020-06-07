#ifndef _GROUP_H
#define _GROUP_H

#include "Institution.h"

class Group : public Institution
{
private:
	size_t groupId;
	Payer* groupPayer;

public:
	Group(const std::string& _institutionName, size_t _groupId, Payer* _groupPayer = nullptr);

	bool hasMember(const Person& user) const;
	const Payer* payer() const;
	bool valid() const;
	
	size_t getGroupId() const;

};

#endif