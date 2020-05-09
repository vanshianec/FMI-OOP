#include <iostream>
#include <string>
#include <vector>

class Employee
{
private:
	std::string name;
	size_t experience;
public:
	Employee(const std::string& _name, const size_t _experience)
	{
		name = _name;
		experience = _experience;
	}

	const std::string& getName()
	{
		return name;
	}

	const size_t getExperience()
	{
		return experience;
	}
};

class Programmer : public Employee
{
private:
	bool knowsCSharp;
	bool knowsCpp;
public:
	Programmer(const std::string& _name, const size_t _experience, bool _knowsCSharp, bool _knowsCpp) : Employee(_name, _experience)
	{
		knowsCSharp = _knowsCSharp;
		knowsCpp = _knowsCpp;
	}
};

class Manager : public Employee
{
private:
	size_t peopleInCharge;
public:
	Manager(const std::string& _name, const size_t _experience, const size_t _peopleInCharge) : Employee(_name, _experience)
	{
		peopleInCharge = _peopleInCharge;
	}
};

int main()
{
	std::vector<Employee*> employees = { new Manager("Gosho", 49, 5),
										new Manager("Tosho", 34, 4),
										new Programmer("Misho", 12, true, false),
										new Programmer("Pesho", 7, false, false) };

	for (Employee* employee : employees)
	{
		std::cout << employee->getName() << std::endl;
	}

	return 0;
}