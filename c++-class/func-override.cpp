#include <iostream>
#include <string>

class Employee {
public:
	float salary;
	Employee(float sal): salary(sal) {}
	void string() {
		std::cout << "Salary: " << salary << "\n";
	}
};

class Manager: public Employee {
	std::string name;
public:
	Manager(std::string na, float sal): name(na), Employee(sal) {}
	// Function overriding
	void string() {
		std::cout << "Name: " << name
			<< "\nSalary: " << salary << "\n";
	}
};

int main() {
	Manager man("Jaipal", 100);
	man.string();
	return 0;
}
