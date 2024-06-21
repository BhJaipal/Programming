#include "../include/linkedlist.h"
#include <malloc.h>
#include <stdio.h>

void add(linkedlist *l, int data, int index) {
	if (l->len <= index) {
		l->arr = realloc(l->arr, sizeof(l->arr[0]) * (++l->len));
		singlyNode node;
		node.data = data;
		node.next = 0;
		l->arr[l->len - 1] = node;
		l->arr[l->len - 2].next = &l->arr[l->len - 1].data;
	} else {
		l->arr = realloc(l->arr, sizeof(l->arr[0]) * (++l->len));
		for (int i = index; i < l->len - 1; i++) { l->arr[i + 1] = l->arr[i]; }
		singlyNode node;
		node.data = data;
		node.next = &l->arr[index + 1].data;
		l->arr[index] = node;
	}
}
int removeNode(linkedlist *l, int index) {
	if (l->len > 0) {
		if (l->len > index) {
			if (l->len - 1 == index) {
				int last = l->arr[--l->len].data;
				l->arr[l->len].data = 0;
				l->arr = realloc(l->arr, sizeof(l->arr[0]) * (l->len));
				l->arr[l->len].next = 0;
				for (int i = 0; i < l->len - 1; i++) {
					l->arr[i].next = &l->arr[i + 1].data;
				}

				return last;
			} else {
				int iData = l->arr[index].data;
				for (int i = index; i < l->len - 1; i++) {
					l->arr[i] = l->arr[i + 1];
					if (i != 0) l->arr[i - 1].next = &l->arr[i].data;
				}
				l->arr[--l->len].data = 0;
				l->arr[l->len - 2].next = 0;
				l->arr = realloc(l->arr, sizeof(l->arr[0]) * (l->len));
				for (int i = 0; i < l->len - 1; i++) {
					l->arr[i].next = &l->arr[i + 1].data;
				}
				return iData;
			}
		} else {
			printf("Index out of range\n");
			return -1;
		}

	} else {
		printf("Linked list is empty\n");
		return -1;
	}
}
void toStringLinkedlist(linkedlist l) {
	if (l.len == 0) {
		printf("[]");
	} else {
		printf("[\n");
		for (int i = 0; i < l.len - 1; i++) {
			printf("\t{ data: %d, next node: %p, next node data: %d }, \n",
				   l.arr[i].data, l.arr[i].next, *l.arr[i].next);
		}

		printf("\t{ data: %d, next node: %p, next node data: %d }\n",
			   l.arr[l.len - 1].data, l.arr[l.len].next, 0);
		printf("]");
	}
}
linkedlist createLinkedlist(int first) {
	linkedlist l;
	singlyNode n1;
	n1.data = first;
	n1.next = 0;
	l.arr = malloc(sizeof(n1));
	l.arr[0] = n1;
	l.len = 1;
	return l;
}