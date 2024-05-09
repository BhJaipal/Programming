#include <iostream>
using namespace std;

class Student
{
	int roll;
	static int _count;

public:
	Student(int _roll) : roll(_roll) { _count++; }
	~Student() { _count--; }
	static int count() { return _count; }
};
int Student::_count = 0;

int main() {
	Student s1(4), s2(5), s3(2);
	cout << "No. of students: " << Student::count() << endl;
	return 0;
}
