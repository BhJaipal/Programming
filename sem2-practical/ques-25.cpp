#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	int age;
	string name;
	void input() {
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};

class Student : virtual public Person {
protected:
	int roll;
	int standard;
	void input() {
		cout << "Class: ";
		cin >> standard;
		cout << "Roll No.: ";
		cin >> roll;
	}
	void display() {
		cout << "Roll: " << roll << endl;
		cout << "Class: " << standard << endl;
	}
};

class Employee : virtual public Person {
protected:
	int salary;
	string designation;
	void input() {
		Person::input();
		cout << "Salary: ";
		cin >> salary;
	}
	void display() {
		Person::display();
		cout << "Salary: " << salary << endl;
	}
};
class Manager : protected Employee, protected Student {
	int bonus;

public:
	void input() {
		Employee::input();
		Student::input();
		cout << "Enter bonus: ";
		cin >> bonus;
		designation = "Manager";
	}
	void display() {
		Employee::display();
		Student::display();
		cout << "Total salary: " << salary + bonus << endl;
	}
};

int main() {
	Manager manager;
	manager.input();
	cout << "\nDetails: \n";
	manager.display();
	return 0;
}
/*
Output:
Name: Jaipal
Age: 19
Salary: 86382
Class: 14
Roll No.: 15
Enter bonus: 72

Details:
Name: Jaipal
Age: 19
Salary: 86382
Roll: 15
Class: 14
Total salary: 86454
*/
