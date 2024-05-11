#include <iostream>
#include <string>
using namespace std;

class Copy {
	string name;
	int age;

public:
	Copy(string name, int age) : name(name), age(age) {}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};
int main() {
	Copy b("John", 25);
	Copy b2 = b;
	b2.display();
	return 0;
}
/*
Output:
Name: John
Age: 25
*/
