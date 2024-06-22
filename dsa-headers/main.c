#include "lib/include/hashmap.h"
#include "lib/include/linkedlist.h"
#include "lib/include/stack.h"
#include <stdio.h>

int main() {
	// stack
	// stack s = createStack();
	// push(&s, 7);
	// push(&s, 6);
	// printf("Poped: %d\n", pop(&s));
	// push(&s, 5);
	// printf("Stack: ");
	// toStringPrintStack(s);
	// printf("\n");

	// double linked list
	// doubleLinkedlist l = createDoubleLinkedlist(9);
	// addDoubleNode(&l, 5, l.len);
	// addDoubleNode(&l, 7, l.len);
	// printf("\nRemoved node: %d\n\n", removeDoubleNode(&l, 1));

	// printf("Linked List: \n");
	// toStringDoubleLinkedlist(l);
	// printf("\n");

	// hashmap
	hashmap h = createHashmap(7, "Jaipal");
	pushPair(&h, 5, "Hema");
	pushPair(&h, 9, "Vikram");
	removePair(&h, 5);
	toStringHashmap(h);
	printf("\n");
	return 0;
}
