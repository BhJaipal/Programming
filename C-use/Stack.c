#include <stdio.h>
#include <stdlib.h>

typedef int Node;
typedef struct Stack {
    Node Array[5];
    int length;
}

Stack createStack(Node list[5]) {
	Stack arr;
	for (int i= 0; i< 5; i++) {
		arr.Array[i] = list[i];
	}
	arr.length= 5;
	return arr;
}

void push(Stack *arr, Node elem) {
    Stack arr2= *arr;
	arr->Array= realloc(arr->Array, sizeof(elem) * (arr2.length + 1));
	arr->length++;
	arr->Array[arr->length -1]= elem;
}
