#ifndef STACK_H
#define STACK_H
#include <malloc.h>

typedef struct {
	int len;
	int *arr;
} stack;

void push(stack *s, int x);
stack createStack();
int pop(stack *s);
int peek(stack *s);
void toStringPrintStack(stack);
#endif