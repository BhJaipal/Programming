#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	string name, profession;
	int age;
public:
	virtual void input() = 0;
	virtual void display() = 0;
};
class Engineering : public Student {
public:
	void input() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		cout << "Enter profession(Mechanical, Civil, Electrical): ";
		cin >> profession;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Profession: " << profession << endl;
	}
};
class Medical : public Student {
public:
	void input() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		cout << "Enter profession(Nurse, Doctor, Dentist): ";
		cin >> profession;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Profession: " << profession << endl;
	}
};
class Science : public Student {
public:
	void input() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter age: "; cin >> age;
		cout << "Enter profession(Biologist, Chemist, Physician): ";
		cin >> profession;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Profession: " << profession << endl;
	}
};
int main() {
	Student *s[3];
	s[0] = new Engineering;
	s[0]->input(); cout << "\n";
	s[1] = new Medical;
	s[1]->input(); cout << "\n";
	s[2] = new Science;
	s[2]->input(); cout << "\n\n";
	for (int i = 0; i < 3; i++) {
		s[i]->display();
		cout << "\n";
	}
	return 0;
}
/*
Output:
Enter name: Name1
Enter age: Age1
Enter profession(Mechanical, Civil, Electrical): Electrical

Enter name: Name2
Enter age: Age2
Enter profession(Nurse, Doctor, Dentist): Dentist

Enter name: Name3
Enter age: Age3
Enter profession(Biologist, Chemist, Physician): Physician


Name: Name1
Age: Age1
Profession: Electrical

Name: Name2
Age: Age2
Profession: Dentist

Name: Name3
Age: Age3
Profession: Physician
*/
