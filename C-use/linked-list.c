#ifndef LinkedList_H
#define LinkedList_H

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct __Node {
	int value;
	struct __Node *next;
} Node;

typedef struct __LinkedList {
	Node *arr;
	int len;
	int isCircular;
} LinkedList;

LinkedList createLL(int first) {
	Node *arr = malloc(sizeof(Node));
	arr[0].value = first;
	arr[0].next = NULL;
	LinkedList ll = { .arr = arr, .len = 1 };
	return ll;
}
void delete(LinkedList *ll) {
	ll->arr = NULL;
	free(ll->arr);
	ll->len = 0;
}
void addNode(LinkedList *ll, int new) {
	ll->len++;
	ll->arr = realloc(ll->arr, sizeof(Node) * ll->len);
	Node newNode = {.value = new, .next = ll->isCircular ? &ll->arr[0]: NULL};
	ll->arr[ll->len-1] = newNode;
	ll->arr[ll->len-2].next = &newNode;
}

void printLL(LinkedList ll) {
	for (int i = 0; i < ll.len - 1; i++) {
		printf("%d -> ", ll.arr[i].value);
	}
	printf("%d -> ", ll.arr[ll.len-1].value);
	ll.isCircular ? printf("%d\n", ll.arr[0].value) : printf("NULL\n");
}

int main(int argc, char *argv[]) {
	LinkedList ll = createLL(5);
	addNode(&ll, 7);
	printLL(ll);
	delete(&ll);
        return 0;
}

#endif /* ifndef LinkedList_H */
