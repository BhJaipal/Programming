#include <climits>
#include <iostream>
using namespace std;

class Employee {
	string name;
	double salary;

public:
	void set() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter salary: ";
		cin >> salary;
	}
	void show() {
		cout << "Employee:\n\tName: " << name;
		cout << "\n\tSalary: " << salary << endl;
	}
};

class Manager : public Employee {
	string type;

public:
	void set() {
		Employee::set();
		cout << "Enter manager type: ";
		cin >> type;
	}
	void show() {
		cout << "Manager:\n\tDesignation: " << type << endl;
		Employee::show();
	}
};

class Labourer : public Employee {};
class Foreman : public Labourer {
	string quotes;

public:
	void set() {
		Labourer::set();
		cout << "Enter quote: ";
		cin.ignore(INT_MAX, '\n');
		getline(cin, quotes);
	}
	void show() {
		cout << "Foreman:\n\tQuote: " << quotes << endl;
		Labourer::show();
	}
};
int main() {
	Manager m;
	m.set();
	cout << endl;
	m.show();
	cout << endl;

	Foreman sci;
	sci.set();
	cout << endl;
	sci.show();
	return 0;
}
