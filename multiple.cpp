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

class Student {
	string degree;
	string school;

public:
	void set() {
		cout << "Enter school: ";
		cin >> school;
		cout << "Enter degree: ";
		cin >> degree;
	}
	void show() {
		cout << "Student:\n\tSchool: " << school;
		cout << "\n\tDegree: " << degree << endl;
	}
};
class Scientist : public Employee, public Student {
	// publications
	int pubs;

public:
	void set() {
		Employee::set();
		Student::set();
		cout << "Enter no. of publications: ";
		cin >> pubs;
	}
	void show() {
		cout << "Scientist:\n\tPublications: " << pubs << endl;
		Employee::show();
		Student::show();
	}
};
int main() {
	Scientist sci;
	sci.set();
	cout << endl;
	sci.show();
	return 0;
}
