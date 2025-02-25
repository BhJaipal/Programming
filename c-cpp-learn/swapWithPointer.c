#include <stdio.h>

void swapWithThirdVar(int *, int *); /// Declaration with type only
void swapWithoutThirdVar(int *x,
                         int *y); /// Declaration with type and parameter

int main() {
  printf("Code here");
  // Code...
  return 0;
}

void swapWithThirdVar(int *x, int *y) {
  // Assume  x= 5   y= 7
  // Swapping with third variable
  int temp = *x; // temp= 5
  *x = *y;       // x = 7
  *y = temp;     // y = 5
  // So, x= 7, y= 5
}

void swapWithoutThirdVar(int *x, int *y) {
  // Assume x= 5, y= 7
  // Swapping without third variable
  *x = *x + *y; // x = 5 + 7 = 12
  // x= 12, y= 7
  *y = *x - *y; // y = 12 - 7 = 5
  // x= 12, y= 5
  *x = *x - *y; // x = 12 - 5 = 7
  // So, x= 7, y= 5
}
