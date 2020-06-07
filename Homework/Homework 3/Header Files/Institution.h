#ifndef _INSTITUTION_H
#define _INSTITUTION_H

#include <string>
#include "Payer.h"
#include "Person.h"

class Institution
{
private:
	size_t institutionId;
	static size_t ID;
	std::string institutionName;

protected:
	Institution(const std::string& _institutionName);

public:
	Institution(const Institution& other);
	Institution& operator=(const Institution& other);

	virtual bool hasMember(const Person& user) const = 0;
	virtual const Payer* payer() const = 0;
	virtual bool valid() const = 0;
	static size_t totalCount();

	size_t getInstitutionId() const;
	const std::string& getInstitutionName() const;

	virtual ~Institution();
};

#endif