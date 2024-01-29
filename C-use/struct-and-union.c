#include <stdio.h>

/**
 On creating a variable, memory of variable will be size of largest memory using memory 
 Here age is int, so it takes 4 bytes
 Then names is Array of 20 char, so it takes 20 * 1 byte = 20 bytes
 Then address is Array of 40 char, so it takes 40 * 1 byte = 40 bytes
 
 So, the variable will takes 40 bytes of memory 
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
  size of rollNo = it is Array of 10 characters, 10 * 1 byte = 10 bytes

  So, size of variable = size of class + size of name + size of rollNo = 4 + 20 + 10 = 34 bytes
  Struct takes more memory than union because all members have their own memory
  means you can access all members at the same time
*/
struct Student {
  int class;
  char name[20];
  char rollNo[10];
};
int main() {
  char name[] = "Jaipal";
  char address[] = "Borunda, Jodhpur, Rajasthan";
  union Person person;
  person.age = 19;
  person.name = name;
  person.address = address; 
  // If we try to access more than one member,
  // first member will be used whereas other members value will be garbage value
  printf("Name: %s    \tAge: %d\n", person.name, person.age);
  return 0;
}