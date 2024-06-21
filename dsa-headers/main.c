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

	linkedlist l = createLinkedlist(9);
	add(&l, 5, l.len);
	add(&l, 7, l.len);
	printf("\nRemoved node: %d\n\n", removeNode(&l, 1));

	printf("Linked List: \n");
	toStringLinkedlist(l);
	printf("\n");
	return 0;
}
