#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string _name;
    int _age;
    bool _isAlive;

public:
    /**
     * @brief Construct a new Person object
     *
     * @param name Name of person
     * @param age Age of person
     * @throw string Cannot create an object of abstract class
     */
    Person(string name, int age)
    {
        _name = name;
        _age = age;
        _isAlive = true;
    }
    virtual void eat() = 0;
    bool getLife() { return isAlive; }
    void setLife(bool status) { isAlive = status; }
};

#if false
// This block won't run
Person person("Jaipal", 18);
// this throws an error as an abstract class
#endif

/**
 * @brief A Student class { @link #Person }
 */
class Student : public Person
{
private:
    string dept;
    int rollNo;

public:
    /**
     * @brief Construct a new Student object
     * @param name Name of Student
     * @param age Age of student
     * @param dept Department of student
     * @param rollNo Roll number of student
     */
    Student(string name, int age, string dept, int rollNo) : Person(name, age)
    {
        this->dept = dept;
        this->rollNo = rollNo;
    }
    ~Student()
    {
        setLife(false);
        cout << "Student died" << endl;
    }
    void display()
    {
        cout << "Name: " << _name << endl;
        cout << "Age: " << _age << endl;
        cout << "Department: " << dept << endl;
        cout << "Roll No: " << rollNo << endl;
    }
    void eat()
    {
        cout << "Student is eating" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Student stud("Jaipal", 18, "CSE", 1);
    stud.display();
    stud.eat();
    return 0;
}
