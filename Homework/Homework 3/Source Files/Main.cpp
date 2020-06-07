
#include <iostream>
#include "Organization.h"
#include "Payer.h"
#include "Group.h"
#include <vector>

const Institution* findMostPopularInstitution(const std::vector<Institution*>& institutions,
	const std::vector<Person>& users)
{
	/* in case no users are members to all the institutions return the first one*/
	const Institution* mostPopular = institutions[0];
	size_t count;
	size_t mostFrequent = 0;

	for (Institution* institution : institutions)
	{
		count = 0;

		for (const Person& user : users)
		{
			if (institution->hasMember(user))
			{
				count++;
			}
		}

		if (count > mostFrequent)
		{
			mostPopular = institution;
			mostFrequent = count;
		}
	}

	return mostPopular;
}

std::vector<Institution*> clearInstitutions(const std::vector<Institution*>& institutions)
{
	std::vector<Institution*> validInstitutions;

	for (Institution* institution : institutions)
	{
		if (institution->valid())
		{
			validInstitutions.push_back(institution);
		}
	}

	return validInstitutions;
}

int main()
{
	/* ---Rules--- */

	std::function<bool(size_t, size_t)> areEqualRule = [](size_t groupId, size_t insuranceId)->bool
	{
		return groupId = insuranceId;
	};

	std::function<bool(size_t, size_t)> areNotEqualRule = [](size_t groupId, size_t insuranceId)->bool
	{
		return groupId != insuranceId;
	};

	std::function<bool(size_t, size_t)> isDivisibleRule = [](size_t groupId, size_t insuranceId)->bool
	{
		return groupId % insuranceId == 0;
	};

	/* ---Payers--- */

	Payer p1("Bulstrad", areEqualRule);
	Payer p2("Alianz", areNotEqualRule);
	Payer p3("Armeets", isDivisibleRule);

	/* ---Groups--- */

	Group g1("First group", 111, &p1);
	Group g2("Second group", 222, &p2);
	Group g3("Third group", 333, &p3);
	/* group without a payer */
	Group g4("Forth group", 444);

	/* ---Organizations--- */

	std::vector<Institution*> i1{ &g1, &g2, &g3, &g4 };
	std::vector<Institution*> i2{ &g2, &g3 };
	Organization o1("First organization", i1, "Address 1");
	Organization o2("Second organization", i2, "Address 2");

	std::vector<Institution*> i3{ &o1, &o2 };
	Organization o3("Third organization", i3, "Address 3");
	/* empty organization */
	Organization o4("Forth organization", std::vector<Institution*>(), "Address 4");

	std::vector<Institution*> i4 = { &o3 };

	Organization main("Main organization", i4, "Adress 5");
	/* add a valid institution */
	main.addInstitution(&g1);
	/* allow adding invalid institution */
	main.addInstitution(&o4, false);

	/* ---Institutions ids--- */

	std::vector<Institution*> allInstitutionsInOrderOfCreation = { &g1, &g2, &g3, &g4, &o1, &o2, &o3, &o4, &main };

	std::cout << "Institutions ids check : \n";

	for (Institution* institution : allInstitutionsInOrderOfCreation)
	{
		std::cout << "Name : " << institution->getInstitutionName()
			<< ", id : " << institution->getInstitutionId() << std::endl;
	}

	std::cout << "Institutions count : " << Institution::totalCount() << std::endl;

	std::cout << std::endl;

	/* ---Institutions valid method--- */

	std::cout << "Institutions valid check : \n";

	for (Institution* institution : allInstitutionsInOrderOfCreation)
	{
		std::cout << "Name : " << institution->getInstitutionName()
			<< ", valid : " << institution->valid() << std::endl;
	}

	std::cout << std::endl;

	/* ---Institutions payers--- */

	/* Groups count in Main organization:
	g1 -> 2 (Bulstrad)
	g2 -> 2 (Alianz)
	g3 -> 2 (Armeets)
	g4 -> 1 (nullptr)
	*/

	std::cout << "Institutions payers check : \n";

	for (Institution* institution : allInstitutionsInOrderOfCreation)
	{
		const Payer* payer = institution->payer();
		std::cout << "Name : " << institution->getInstitutionName() << ", payer : ";
		if (payer != nullptr)
		{
			std::cout << institution->payer()->getPayerName();
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	/* ---Group members--- */

	std::cout << "Groups members check : \n";

	Person person1("Pesho Peshov", 111);
	Person person2("Gosho Goshov", 222);
	Person person3("Misho Mishov", 333);

	std::vector<Group*> groups = { &g1, &g2, &g3 ,&g4 };

	for (Group* group : groups)
	{
		std::cout << "Group name : " << group->getInstitutionName() << std::endl;
		std::cout << "Has member " << person1.getPersonName() << " - " << group->hasMember(person1) << std::endl;
		std::cout << "Has member " << person2.getPersonName() << " - " << group->hasMember(person2) << std::endl;
		std::cout << "Has member " << person3.getPersonName() << " - " << group->hasMember(person3) << std::endl;
	}

	std::cout << std::endl;

	/* ---Most popular institution--- */

	/* should be the Main institution */
	std::vector<Institution*> i5 = { &g2, &g3, &g4 , &main };
	std::vector<Person> users = { person1, person2, person3 };
	const Institution* mostPopular = findMostPopularInstitution(i5, users);
	std::cout << "Most popular institution : " << mostPopular->getInstitutionName() << std::endl;

	std::cout << std::endl;

	/* ---Clear institutions--- */

	/* o4 and g4 are invalid  */
	std::vector<Institution*> validAndInvalid = { &main, &o4, &g1, &g4 };
	std::vector<Institution*> valid = clearInstitutions(validAndInvalid);

	std::cout << "List with valid and invalid institutions: " << std::endl;

	for (Institution* institution : validAndInvalid)
	{
		std::cout << "Name : " << institution->getInstitutionName()
			<< ", valid : " << institution->valid() << std::endl;
	}

	std::cout << "List with valid institutions after clearing : " << std::endl;

	for (Institution* institution : valid)
	{
		std::cout << "Name : " << institution->getInstitutionName()
			<< ", valid : " << institution->valid() << std::endl;
	}

	std::cout << std::endl;

	/* ---Institutions copy--- */

	/* a new institution */
	Group institution10 = g1;
	std::cout << "Institution 10 id : " << institution10.getInstitutionId() << std::endl;
	/* should be 'Purva Grupa'*/
	std::cout << "Institution 10 name : " << institution10.getInstitutionName() << std::endl;

	/* a new institution */
	Group institution11 = g2;
	std::cout << "Institution 11 id : " << institution11.getInstitutionId() << std::endl;

	/* not a new institution */
	institution10 = g3;
	std::cout << "Institution 10 id : " << institution10.getInstitutionId() << std::endl;
	/* should be 'Purva Grupa'*/
	std::cout << "Institution 10 name : " << institution10.getInstitutionName() << std::endl;

	std::cout << "Institutions count after making two copies : " << Institution::totalCount() << std::endl;

	std::cout << std::endl;

	return 0;
}

