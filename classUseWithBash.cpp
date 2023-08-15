#include <iostream>
#include <string>
using namespace std;

class Person{
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
    return "Person has eaten food";
  }
  void setIsHungry() {
    this->isHungry= true;
  }
  void setName(string newName) {
    char confirm;
    cout << "Are you sure you want to change your name [Yn]: ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
      this->name= newName;
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
};
void PersonDynamicUse() {
  string name;
  cout << "Hello, enter your name: ";
  cin >> name;
  float age;
  cout << "Enter your age: ";
  cin >> age;
  Person person(name, age);
  cout << "" << endl;
  cout << "Current data" << endl;
  cout << "Name: " << person.getName() << endl;
  cout << "Age: " << person.getAge() << endl;
  cout << "Is Person alive?: " << person.getIsAlive() << endl;
  cout << "Is person hungry: " << person.getIsHungry() << endl << endl;

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
      person.setName(newName);
    } else if (choice == 2) {
      float newAge;
      cout << "Enter new age: ";
      cin >> newAge;
      person.setAge(newAge);
    } else if (choice == 3) {
      person.setIsHungry();
      if (person.getIsHungry()) {
        cout << person.getName() << " is hungry" << endl;
      } else {
        cout << person.getName() << " is not hungry" << endl;
      }
    } else if (choice == 4) {
      cout << person.eat() << endl;
    } else if (choice == 5) {
      cout << "Current data: " << endl;
      cout << "Name: " << person.getName() << endl;
      cout << "Age: " << person.getAge() << endl;
      if (person.getIsHungry()) {
        cout << person.getName() << " is hungry" << endl;
      } else {
        cout << person.getName() << " is not hungry" << endl;
      }
      if (person.getIsAlive()) {
        cout << person.getName() << " is alive" << endl;
      } else {
        cout << person.getName() << " is dead" << endl;
      }
    } else if (choice == 6) {
      person.setIsAlive(false);
      cout << "Quiting process" << endl;
      break;
    } else if (choice == 7) {
      cout << "Quiting process" << endl;
      break;
    } else {}
    cout << "" << endl;
  }
}

int main() {
  PersonDynamicUse();
  return 0;
}
