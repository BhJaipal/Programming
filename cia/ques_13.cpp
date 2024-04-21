#include <iostream>
#include <string>

class Employee
{
	std::string _name;
	int _e_id;
	long int _salary;

public:
	Employee(std::string name, int id, long int salary) : _name(name), _e_id(id), _salary(salary) {}
	void display()
	{
		std::cout << "Name: " << _name << "\nEmployee ID:" << _e_id << "\nSalary: " << _salary << "\n";
	}
};
class Manager : public Employee
{
protected:
	std::string type;

public:
	Manager(std::string name, int id, long int salary, std::string manager_type) : type(manager_type), Employee(name, id, salary)
	{
	}
	void display()
	{
		std::cout << "Manager type: " << type << "\n";
	}
};
class Engineer : public Employee
{
protected:
	std::string degree;

public:
	Engineer(std::string name, int id, long int salary, std::string _degree) : degree(_degree), Employee(name, id, salary) {}
	void display()
	{
		Employee::display();
		std::cout << "Profession: " << degree << "\n";
	}
};
class TeamLead : private Engineer, private Manager
{
public:
	TeamLead(std::string name, int id, long int salary) : Engineer(name, id, salary, "Software dev"), Manager(name, id, salary, "Project manager") {}
	void display()
	{
		Engineer::display();
		Manager::display();
	}
};

int main()
{
	TeamLead lead("jaipal", 1, 10000);
	lead.display();
	return 0;
}
