#include <iostream>
#include <string>
using namespace std;

class Student
{
	string name;
	int roll;
	int fees;

public:
	void display()
	{
		cout << roll << ", " << name << ", " << fees;
	}
	void scan()
	{
		cout << "Name: ";
		cin >> name;
		cout << "Roll: ";
		cin >> roll;
		cout << "Fees: ";
		cin >> fees;
	}
};
int main()
{
	Student stud;
	stud.scan();
	stud.display();
	return 0;
}
