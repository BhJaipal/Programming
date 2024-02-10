#include <iostream>
#include <string>

class Person
{
protected:
    std::string _name;
    int _age;
    bool _isAlive;

public:
    /**
     * @brief Construct a new Person object
     *
     * @param name Name of person
     * @param age Age of person
     * @throw std::string Cannot create an object of abstract class
     */
    Person(std::string name, int age)
    {
        this->_name = name;
        this->_age = age;
        this->_isAlive = true;
    }
    virtual void eat() = 0;
    bool getLife() { return this->_isAlive; }
    void setLife(bool status) { this->_isAlive = status; }
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
    std::string dept;
    int rollNo;

public:
    /**
     * @brief Construct a new Student object
     * @param name Name of Student
     * @param age Age of student
     * @param dept Department of student
     * @param rollNo Roll number of student
     */
    Student(std::string name, int age, std::string dept, int rollNo) : Person(name, age)
    {
        this->dept = dept;
        this->rollNo = rollNo;
    }
    ~Student()
    {
        this->setLife(false);
        std::cout << "Student died" << std::endl;
    }
    void display()
    {
        std::cout << "Name: " << this->_name << std::endl;
        std::cout << "Age: " << this->_age << std::endl;
        std::cout << "Department: " << this->dept << std::endl;
        std::cout << "Roll No: " << this->rollNo << std::endl;
    }
    void eat()
    {
        std::cout << "Student is eating" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Student stud("Jaipal", 18, "CSE", 1);
    stud.display();
    stud.eat();
    return 0;
}
