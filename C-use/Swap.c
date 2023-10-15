#include <stdio.h>

int main() {
  int a= 3;
  int b= 2;
  printf("Before swapping\n");
  printf("a: %d    b: %d\n", a, b");
  /*
    prints
    Before Swapping 
    a: 3    b: 2
  */

  int temp= a; 
  // creates a temporary variable temp= 3
  a= b; // sets a = 2 because b= 2
  b= temp; // sets b= 3 because temp= 3

  printf("After Swapping\n");
  printf("a: %d    b: %d", a, b);
  /*
    prints
    After swapping 
    a: 2    b: 3 
  */
  return 0;
}
