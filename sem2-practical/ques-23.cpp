#include <iostream>
#include <string>
using namespace std;

class Emp {
	string name, designation;
	int E_id;
protected:
	void input() {
		cout << "Enter E_id: "; cin >> E_id;
		cout << "Enter name: "; cin >> name;
		cout << "Enter designation: "; cin >> designation;
	}
	void display() { cout << "Name: " << name << "\tDesignation: " << designation << "\tE_id: " << E_id << endl; }
};
class Employee : public Emp {
	int basic, da, hra, pf;
public:
	void input() {
		Emp::input();
		cout << "Enter basic, DA, HRA, PF: ";
		cin >> basic >> da >> hra >> pf;
	}
	void calculate() {
		Emp::display();
		cout << "Net Pay: " << basic + da + hra - pf << endl;
	}
};
int main() {
	Employee e[3];
	for (int i = 0; i < 3; i++) {
		e[i].input();
		cout << "\n";
	}
	cout << "\nEmployee Details:\n";
	for (int i = 0; i < 3; i++) {
		e[i].calculate();
		cout << "\n";
	}
	return 0;
}
/*
Output:
Enter E_id: 52
Enter name: Name1
Enter designation: Programmer
Enter basic, DA, HRA, PF: 6326 72 32 92

Enter E_id: 38
Enter name: Name2
Enter designation: Manager
Enter basic, DA, HRA, PF: 6532 32 13 43

Enter E_id: 77
Enter name: Name3
Enter designation: HR
Enter basic, DA, HRA, PF: 9455 53 62 74


Employee Details:
Name: Name1    Designation: Programmer  E_id: 52
Net Pay: 6338

Name: Name2    Designation: Manager     E_id: 38
Net Pay: 6534

Name: Name3    Designation: HR          E_id: 77
Net Pay: 9496
*/
