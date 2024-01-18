#include <stdio.h>

/**
  & is used to return memory address of a variable
  * is used to get value at a given memory address

  There is code snippet below
  You can only see it highlighted with a code editor with Doc comments extension
  or plugin
  ```c
    int main() {
      int var = 5;
      printf("%d\n", *(&var));
      // return value at memory address of var
      // aka value of var
      return 0;
    }
  ```
*/

void sum2withPointer(int *var) {
  // As we pass &num as parameter, value of var is address of num, not value of
  // num
  printf("Address of actual variable: %p: \n", var);
  *var = *var + 2;
}
void sum2withoutPointer(int var) {
  printf("Address of duplicate: %p: \n", &var);
  var = var + 2;
}

int main() {
  int num = 5;
  printf("Number: %d\n", num);
  printf("Address with %%p: %p\t\tAddress with %%d: %ld\n\n", &num, &num);
  sum2withoutPointer(num);
  printf("After calling without pointer function, var= %d\nBecause num sends a "
         "copy, not itself\n\n",
         num);
  sum2withPointer(&num);
  printf("After calling function with memory address, %d\nBecause num sends "
         "its memory address, change canbe done in its actual value not copy\n",
         num);
  return 0;
}

// I recommend to run it once and see the output
// To understand what this whole pasta I wrote actually means
// On compiling, you will get a warning, avoid it and continue executing
// Sample run by Me:
/*
Number: 5
Address with %p: 0x7ffc8a35e414		Address with %d: 140722627273748

Address of duplicate: 0x7ffc8a35e3fc:
After calling without pointer function, var= 5
Because num sends a copy, not itself

Address of actual variable: 0x7ffc8a35e414:
After calling function with memory address, 7
Because num sends its memory address, change canbe done in its actual value not
copy
 */
