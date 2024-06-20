#include "stack.h"
#include <malloc.h>

void push(stack *s, int x) {
  s->arr = realloc(s->arr, sizeof(int) * (s->len + 1));
  s->arr[s->len] = x;
  s->len++;
}
stack createStack() {
  stack s;
  s.len = 0;
  s.arr = malloc(sizeof(int) * s.len);
  return s;
}
int pop(stack *s) {
  if (s->len > 0) {

    s->len--;
    int last = s->arr[s->len];
    s->arr[s->len] = 0;
    s->arr = realloc(s->arr, sizeof(int) * (s->len));
    return last;
  } else {
    printf("STack is empty\n");
    return -1;
  }
}
int peek(stack *s) {
  if (s->len > 0) {

    return s->arr[s->len - 1];
  } else {
    printf("Stack is empty\n");
    return -1;
  }
}