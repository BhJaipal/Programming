#include <stdio.h>

int main() {
  /*
  What is loop? 
  Loop means doing something over and over again 
  There are three types of loops:
    for loop
    while loop
    do while loop
  */

  /*
    for loop, it works like a counter like 
    1, 2, 3   8, 7, 6, 5 
    2, 4, 6, 8    -2, -3, -4

    Syntax: 
    for (variable_type variable_name= value; condition; increment/decrement) 
    {
      body;
    }
    usually variable type is integer
  */
  // i++ means after each iteration, 1 is added to i 
  for (int i= 0; i< 5; i++) {
    printf("i: %d\n", i);
  }
  // i is not accessible outputside for loop body
  printf("%d", i); // it cause error
  /*
    output:
    i: 0
    i: 1
    i: 2
    i: 3
    i: 4
    when i will become 5, 
    condition will become false and loop will end
  */

  /*
    while loop
    it run code until program is false 
    use it carefully or you might create an infinite loop 
    which could crash your code editor 
    Syntax: 
    while (condition) { body }
  */
  int num= 10;
  while (num > 0) {
    printf("%d  ", num);
    num--; // it decreases value if num by 1
  }
  /*
    output
    10  9  8  7  6  5  4  3  2  1 
  */
  /*
    do while loop 
    it works like while loop but 
    while loop checks condition first then run body 
    but do while loop on first time runs body then works like a normal while loop 

    Syntax: 
    do {
      body;
    } while (condition)
  */
  int num2= 10;
  do {
    printf("%d  ", num2);
    num2--;
  } while (num2 > 0)
  /*
    output:
    10  9  8  7  6  5  4  3  2  1
  */
  
  return 0;
}
