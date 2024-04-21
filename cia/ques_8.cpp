#include <iostream>
#include <string>

class Student
{
	std::string name;
	int roll_no;
	float marks;
	static int _count;

public:
	Student(std::string name, int roll_no, float marks) : name(name), roll_no(roll_no), marks(marks)
	{
		_count++;
	}
	~Student()
	{
		_count--;
	}
	static int count()
	{
		return _count;
	}
	void nothing()
	{
		std::cout << "nothing" << std::endl;
	}
};
int Student::_count;
int main(int argc, char const *argv[])
{
	Student s1("s1", 1, 100), s2("s2", 2, 200), s3("s3", 3, 300);
	std::cout << "Number of students: " << Student::count() << std::endl;
	return 0;
}
