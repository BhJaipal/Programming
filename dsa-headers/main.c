#include "stack.h"
#include <stdio.h>

int main() {
  stack s = createStack();
  push(&s, 7);
  push(&s, 6);
  printf("Poped: %d\n", pop(&s));
  push(&s, 5);
  printf("Stack: ");
  for (int i = 0; i < s.len; i++) { printf("%d  ", s.arr[i]); }
  printf("\n");

  return 0;
}
