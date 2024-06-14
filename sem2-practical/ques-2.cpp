#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
	int roll;
	int fees;

public:
	void display() {
		cout << roll << ", " << name << ", " << fees;
	}
	void scan() {
		cout << "Name: "; cin >> name;
		cout << "Roll: "; cin >> roll;
		cout << "Fees: "; cin >> fees;
	}
};
int main() {
	Student stud[10];
	for (int i = 0; i < 10; i++) {
		stud[i].scan();
		cout << "\n";
	}
	for (int i = 0; i < 10; i++) {
		stud[i].display();
	}
	return 0;
}

/*
Output:
(I won't share names, roll and fees)
Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

Name:
Roll:
Fees:

104, Jaipal, 900
...(all 9 others)

*/