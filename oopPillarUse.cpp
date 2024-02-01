#include <iostream>
#include <string>

/**
 * * This is Abstraction
 * nothing method is pure virtual method,
 * this class is now an abstract class
 * means creating an object of this class will cause error
 * to utilize this class, create a child class of this class
 *
 * ```cpp
 * Person person1("Jaipal", 18);
 * ```
 * this throws an error as an abstract class
 * object is cannot be created
 */
class Person
{
  /**
   * * This is Encapsulation
   * private keyword is used,
   * every method and variable until
   * public or protected keyword will become
   * a private member of class until end of class
   *
   * ```cpp
   * std::cout << person1.name << std::endl;
   * person1.age= 19;
   * ```
   * both throws error as private members of class are cannot be accessed outside class directly
   * use getters and setters instead
   */
private:
  std::string name;
  float age;
  bool isAlive;
  bool isHungry;

public:
  /**
   * @param name Name of person
   * @param age Age of person
   */
  Person(std::string name, float age)
  {
    this->name = name;
    this->age = age;
    this->isAlive = true;
    this->isHungry = true;
  }
  bool getIsHungry()
  {
    return this->isHungry;
  }
  std::string eat()
  {
    this->isHungry = false;
    return this->name + " has eaten food";
  }
  void setIsHungry()
  {
    this->isHungry = true;
  }
  void setName(std::string newName)
  {
    char confirm;
    std::cout << "Are you sure you want to change your name [Yn]: ";
    std::cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
      if (this->name == newName)
      {
        std::cout << "Cannot change name, please chose a new name" << std::endl;
      }
      else
      {
        this->name = newName;
      }
    }
    else
    {
    }
  }
  std::string getName()
  {
    return this->name;
  }
  float getAge()
  {
    return this->age;
  }
  void setAge(float newAge)
  {
    this->age = newAge;
  }
  bool getIsAlive()
  {
    return this->isAlive;
  }
  void setIsAlive(bool aliveStatus)
  {
    if (aliveStatus == false)
    {
      std::std::cout << this->name << " is dead" << std::std::endl;
    }
    else
    {
    }
    this->isAlive = aliveStatus;
  }
  /**
   * To make Person class an abstract class,
   * we have to create atleast 1 pure virtual method
   * so I create 1 pure virtual method named nothing which actually does nothing
   * and is just used to make Person class an abstract class
   * `virtual void nothing() =0;`
   */
};
/**
 * When a class inherites other class,
 * it get all default features of parent class
 * you can even customize the methods and
 * add your own new variables and method and  constructor parameter
 * * This is Inheritance
 *
 * ```cpp
 *    Programmer jai("Jai", 21, 50000);
 * ```
 * If you are inheriting an abstract class,
 * don't forget to do function defination of virtual methods, which were set =0; in abstract class
 */
class Programmer : public Person
{
private:
  int salary;

public:
  Programmer(std::string name, float age, int salary1)
      : Person(name, age)
  {
    this->salary = salary1;
  }
  int getSalary()
  {
    return this->salary;
  }
  void setSalary(int newSalary)
  {
    this->salary = salary;
  }
  void nothing() {}
};
class Manager : public Person
{
private:
  int salary;

public:
  Manager(std::string name, float age, int salary1)
      : Person(name, age)
  {
    this->salary = salary1;
  }
  int getSalary()
  {
    return this->salary;
  }
  void nothing() {}
};
/**
 * Multiple classes can inherit a single class
 * Programmer and Manager both inherits a single Person class
 * it can be used by creating a Person pointer or
 * initiaing a variable with Person type
 * * This is Polymorphism
 *
 *:
 * ```cpp
 *    // With person pointer:
 *    Person* person1;
 *    person = new Programmer("Jaipal", 50000);
 *    person::getName();
 * ```
 * I will use another method of polymorphism in below method
 */
void OOPPillarUse()
{
  std::string name;
  std::cout << "Hello, enter your name: ";
  std::cin >> name;

  float age;
  std::cout << "Enter your age: ";
  std::cin >> age;

  int salary;
  std::cout << "Enter salary: ";
  std::cin >> salary;

  int choice1;
  std::cout << "Choose one: \n1. Programmer\n2. Manager\n3. Enter value: ";
  std::cin >> choice1;
  if (choice1 == 1 || choice1 == 2)
  {
    Person *person;
    if (choice1 == 1)
    {
      person = new Programmer(name, age, salary);
    }
    else
    {
      person = new Manager(name, age, salary);
    }
    std::cout << "" << std::endl;
    std::cout << "Current data" << std::endl;
    std::cout << "Name: " << person->getName() << std::endl;
    std::cout << "Age: " << person->getAge() << std::endl;
    std::cout << "Is Person alive?: " << person->getIsAlive() << std::endl;
    std::cout << "Is person hungry: " << person->getIsHungry() << std::endl
              << std::endl;

    while (true)
    {
      std::cout << "Options: " << std::endl;
      std::cout << "1. Change name" << std::endl;
      std::cout << "2. Change age" << std::endl;
      std::cout << "3. Get hungry" << std::endl;
      std::cout << "4. Eat food" << std::endl;
      std::cout << "5. Get current data" << std::endl;
      std::cout << "6. Die and exit" << std::endl;
      std::cout << "7. Exit or quit" << std::endl;
      std::cout << "Enter your choice: ";
      int choice;
      std::cin >> choice;
      std::cout << "" << std::endl;
      if (choice == 1)
      {
        std::string newName;
        std::cout << "Enter your new name: ";
        std::cin >> newName;
        person->setName(newName);
      }
      else if (choice == 2)
      {
        float newAge;
        std::cout << "Enter new age: ";
        std::cin >> newAge;
        person->setAge(newAge);
      }
      else if (choice == 3)
      {
        person->setIsHungry();
        if (person->getIsHungry())
        {
          std::cout << person->getName() << " is hungry" << std::endl;
        }
        else
        {
          std::cout << person->getName() << " is not hungry" << std::endl;
        }
      }
      else if (choice == 4)
      {
        std::cout << person->eat() << std::endl;
      }
      else if (choice == 5)
      {
        std::cout << "Current data: " << std::endl;
        std::cout << "Name: " << person->getName() << std::endl;
        std::cout << "Age: " << person->getAge() << std::endl;
        if (person->getIsHungry())
        {
          std::cout << person->getName() << " is hungry" << std::endl;
        }
        else
        {
          std::cout << person->getName() << " is not hungry" << std::endl;
        }
        if (person->getIsAlive())
        {
          std::cout << person->getName() << " is alive" << std::endl;
        }
        else
        {
          std::cout << person->getName() << " is dead" << std::endl;
        }
      }
      else if (choice == 6)
      {
        person->setIsAlive(false);
        std::cout << "Quiting process" << std::endl;
        free(person);
        break;
      }
      else if (choice == 7)
      {
        std::cout << "Quiting process" << std::endl;
        free(person);
        break;
      }
      else
      {
      }
      std::cout << "" << std::endl;
    }
  }
  else
  {
    std::cout << "Invalid input, please do it again" << std::endl
              << std::endl;
    OOPPillarUse();
    /* Use recursion on wrong input
     * Polymorphism on 1 or 2
     */
  }
}

int main()
{
  Person person("Jaipal", 19);
  std::cout << "Welcome to OOP Pillar Use" << std::endl;
  std::cout << "Current data" << std::endl;
  std::cout << person.getName() << std::endl;
  // OOPPillarUse();
  return 0;
}
