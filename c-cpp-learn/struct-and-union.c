#include <stdio.h>

/**
 On creating a variable, memory of variable will be size of largest memory using memory 
 Here age is int, so it takes 4 bytes
 Then names is Array of 20 char, so it takes 20 * 1 byte = 20 bytes
 Then address is Array of 40 char, so it takes 40 * 1 byte = 40 bytes
 
 So, the variable will takes 40 bytes of memory 
 How to declare a union:
 ```c
   union union_name variable_name;
 ```
*/
union Person {
  int age;
  char name[20];
  char address[40];
};

/*
 On creating a variable, memory of variable will be sum of size of all members
  size of class = it is int, so 4 bytes
  size of name = it is Array of 20 characters, so 20 * 1 byte = 20 bytes
  size of rollNo = it is Array of 10 characters, 11 * 1 byte = 11 bytes

  So, size of variable = size of class + size of name + size of rollNo = 4 + 20 + 11 = 35 bytes
  Struct (Structure) takes more memory than union because all members have their own memory
  means you can access all members at the same time
  How to declare a struct variable:
  ```c
    struct struct_name variable_name;
  ```
*/
struct Student {
  int class;
  char name[20];
  char rollNo[11];
};

int main() {
  char name[] = "Jaipal Bhanwariya";
  char address[] = "Borunda, Jodhpur, Rajasthan";
  union Person person;
  person.age = 19;
  person.name = name;
  person.address = address; 
  // If we try to access more than one member,
  // first member will be used whereas other members value will be garbage value
  printf("Name: %s    Age: %d\n", person.name, person.age);
  // Name: Jaipal Bhanwariya    Age: 375264 (Any garbage value)

  char rollNo[] = "23IMS*****";
  struct Student stud;
  stud.class = 13;
  stud.name = name;
  stud.rollNo = rollNo;
  // All members accessible at same time
  printf("Name: %s,  Class: %d,  Roll No: %s\n", stud.name, stud.class, stud.rollNo);
  // Name: Jaipal Bhanwariya    Class: 13    Roll No: 23IMS*****
  return 0;
}