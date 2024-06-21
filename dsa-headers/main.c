#include "lib/include/linkedlist.h"
#include "lib/include/stack.h"
#include <stdio.h>

int main() {
	stack s = createStack();
	push(&s, 7);
	push(&s, 6);
	printf("Poped: %d\n", pop(&s));
	push(&s, 5);
	printf("Stack: ");
	toStringPrintStack(s);
	printf("\n");

	doubleLinkedlist l = createDoubleLinkedlist(9);
	addDoubleNode(&l, 5, l.len);
	addDoubleNode(&l, 7, l.len);
	// printf("\nRemoved node: %d\n\n", removeDoubleNode(&l, 1));

	printf("Linked List: \n");
	toStringDoubleLinkedlist(l);
	printf("\n");
	return 0;
}
