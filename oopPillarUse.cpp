#include <iostream>
#include <string>
using namespace std;

/** 
 *  as nothing method is pure virtual method, 
 *  this class is now an abstract class 
 *  means creating an object of this class will cause error 
 *  to utilize this class, create a child class of this class 
 * * This is Abstraction
 *  @example 
 *  Person person1("Jaipal", 18); 
 *  this throws an error as an abstract class
 */ object is cannot be created
class Person{
  /**
   *  as private keyword is used, 
   *  every method and variable until 
   *  public or protected keyword will become 
   *  a private member of class until end of class 
   * * This is Encapsulation
   * @example
   * ```cpp
   *    cout << person1.name << endl;
   *    person1.age= 19;
   * ```
   * both throws error as private members of class are cannot be accessed outside class directly 
   * use getters and setters instead 
   */
private:
  string name;
  float age;
  bool isAlive;
  bool isHungry;

public:
  Person(string name, float age) {
    this->name= name;
    this->age= age;
    this->isAlive= true;
    this->isHungry= true;
  }
  bool getIsHungry() {
    return this->isHungry;
  }
  string eat() {
    this->isHungry= false;
    return this->name+ " has eaten food";
  }
  void setIsHungry() {
    this->isHungry= true;
  }
  void setName(string newName) {
    char confirm;
    cout << "Are you sure you want to change your name [Yn]: ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
      if (this->name== newName) {
        cout << "Cannot change name, please chose a new name" << endl;
      } else {
        this->name= newName;
      }
    } else {}
  }
  string getName() {
    return this->name;
  }
  float getAge() {
    return this->age;
  }
  void setAge(float newAge) {
    this->age= newAge;  
  }
  bool getIsAlive() {
    return this->isAlive;
  }
  void setIsAlive(bool aliveStatus) {
    if (aliveStatus == false) {
      cout << this->name << " is dead" << endl;
    } else {}
    this->isAlive= aliveStatus;
  }
  /**
   * To make Person class an abstract class, 
   * we have to create atleast 1 pure virtual method
   * so I create 1 pure virtual method named nothing which actually does nothing 
   * and is just used to make Person class an abstract class 
  virtual void nothing() =0;
};
   /**
    * When a class inherites other class, 
    * it get all default features of parent class 
    * you can even customize the methods and 
    * add your own new variables and method and  constructor parameter 
    * * This is Inheritance  
    * @example:
    * ```cpp 
    *    Programmer jai("Jai", 21, 50000);
    * ```
    * If you are inheriting an abstract class, 
    * don't forget to do function defination of virtual methods, which were set =0; in abstract class 
   */
class Programmer: public Person{
private:
  int salary;
public:
  Programmer(string name, float age, int salary1)
  : Person(name, age) {
    this->salary= salary1;
  }
  int getSalary() {
    return this->salary;
  }
  void setSalary(int newSalary) {
    this->salary= salary;
  }
  void nothing() {}
};
class Manager: public Person{
private:
  int salary;
public:
  Manager(string name, float age, int salary1)
  : Person(name, age) {
    this->salary= salary1;
  }
  int getSalary() {
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
 * @example: 
 * ```cpp
 *    // With person pointer:
 *    Person* person1;
 *    person = new Programmer("Jaipal", 50000);
 *    person::getName();
 * ```
 * I will use another method of polymorphism in below method 
 */
void OOPPillarUse() {
  string name;
  cout << "Hello, enter your name: ";
  cin >> name;

  float age;
  cout << "Enter your age: ";
  cin >> age;

  int salary;
  cout << "Enter salary: ";
  cin >> salary;

  int choice1;
  cout << "Choose one: \n1. Programmer\n2. Manager\n3. Enter value: ";
  cin >> choice1;
  if (choice1 == 1 || choice1 == 2) {
  Person* person;
  if (choice1 == 1) {
    person= new Programmer(name, age, salary);
  } else {
    person= new Manager(name, age, salary);
  }
  cout << "" << endl;
  cout << "Current data" << endl;
  cout << "Name: " << person->getName() << endl;
  cout << "Age: " << person->getAge() << endl;
  cout << "Is Person alive?: " << person->getIsAlive() << endl;
  cout << "Is person hungry: " << person->getIsHungry() << endl << endl;

  while (true) {
    cout << "Options: " << endl;
    cout << "1. Change name" << endl;
    cout << "2. Change age" << endl;
    cout << "3. Get hungry" << endl;
    cout << "4. Eat food" << endl;
    cout << "5. Get current data" << endl;
    cout << "6. Die and exit" << endl;
    cout << "7. Exit or quit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cout << "" << endl;
    if (choice == 1) {
      string newName;
      cout << "Enter your new name: ";
      cin >> newName;
      person->setName(newName);
    } else if (choice == 2) {
      float newAge;
      cout << "Enter new age: ";
      cin >> newAge;
      person->setAge(newAge);
    } else if (choice == 3) {
      person->setIsHungry();
      if (person->getIsHungry()) {
        cout << person->getName() << " is hungry" << endl;
      } else {
        cout << person->getName() << " is not hungry" << endl;
      }
    } else if (choice == 4) {
      cout << person->eat() << endl;
    } else if (choice == 5) {
      cout << "Current data: " << endl;
      cout << "Name: " << person->getName() << endl;
      cout << "Age: " << person->getAge() << endl;
      if (person->getIsHungry()) {
        cout << person->getName() << " is hungry" << endl;
      } else {
        cout << person->getName() << " is not hungry" << endl;
      }
      if (person->getIsAlive()) {
        cout << person->getName() << " is alive" << endl;
      } else {
        cout << person->getName() << " is dead" << endl;
      }
    } else if (choice == 6) {
      person->setIsAlive(false);
      cout << "Quiting process" << endl;
      free(person);
      break;
    } else if (choice == 7) {
      cout << "Quiting process" << endl;
        free(person);
      break;
    } else {}
    cout << "" << endl;
  }
  } else {
  cout << "Invalid input, please do it again" << endl << endl;
  OOPPillarUse();
  /* Use recursion on wrong input
   * Polymorphism on 1 or 2 
   */
  }
}

int main() {
  OOPPillarUse();
  return 0;
}
