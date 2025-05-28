#include <iostream>

/*
 * Multi level inheritance
 *    A
 *    |-> B
 *        |-> C
 */
class Employee {
public:
	int salary;
};

class Labourer: public Employee {
};

class Foreman : public Labourer {
public:
	std::string quote;
	Foreman(std::string quo, int sal) {
		quote = quo;
		salary = sal;
	}
	void show() {
		std::cout << "Quote: " << quote
			<< "\nSalary: " << salary << "\n";
	}
};
int main (int argc, char *argv[]) {
	Foreman c("Keep on coding", 1000);
	c.show();
	return 0;
}
