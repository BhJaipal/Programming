#include "../include/linkedlist.h"
#include <malloc.h>
#include <stdio.h>

// singly linked list
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
void add(linkedlist *l, int data, unsigned int index) {
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

int removeNode(linkedlist *l, unsigned int index) {
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
// Double linked list
void addDoubleNode(doubleLinkedlist *l, int data, unsigned int index) {
	if (l->len <= index) {
		l->arr = realloc(l->arr, sizeof(l->arr[0]) * (++l->len));
		doubleNode node;
		node.data = data;
		l->arr[l->len - 1] = node;
	} else {
		l->arr = realloc(l->arr, sizeof(l->arr[0]) * (++l->len));
		for (int i = index; i < l->len - 1; i++) { l->arr[i + 1] = l->arr[i]; }
		doubleNode node;
		node.data = data;
		l->arr[index] = node;
	}
	// setting up next and prev
	for (int i = 1; i < l->len - 1; i++) {
		l->arr[i].prev = &l->arr[i - 1].data;
		l->arr[i].next = &l->arr[i + 1].data;
	}
	l->arr[0].next = &l->arr[1].data;
	l->arr[0].prev = &l->arr[l->len - 1].data;
	l->arr[l->len - 1].next = &l->arr[0].data;
	l->arr[l->len - 1].prev = &l->arr[l->len - 2].data;
	printf("%d %d %d\n", l->arr[l->len - 1].data, *l->arr[l->len - 1].next,
		   *l->arr[l->len - 1].prev);
}

int removeDoubleNode(doubleLinkedlist *l, unsigned int index) {
	if (l->len > 0) {
		if (l->len > index) {
			if (l->len - 1 == index) {
				int last = l->arr[--l->len].data;
				l->arr[l->len].data = 0;
				l->arr = realloc(l->arr, sizeof(l->arr[0]) * (l->len));
				l->arr[l->len].next = 0;
				// setting up next and prev
				for (int i = 1; i < l->len - 1; i++) {
					l->arr[i].prev = &l->arr[i - 1].data;
					l->arr[i].next = &l->arr[i + 1].data;
				}
				l->arr[0].next = &l->arr[1].data;
				l->arr[0].prev = &l->arr[l->len - 1].data;
				l->arr[l->len - 1].next = &l->arr[0].data;
				l->arr[l->len - 1].prev = &l->arr[l->len - 2].data;
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
				// setting up next and prev
				for (int i = 1; i < l->len - 1; i++) {
					l->arr[i].prev = &l->arr[i - 1].data;
					l->arr[i].next = &l->arr[i + 1].data;
				}
				l->arr[0].next = &l->arr[1].data;
				l->arr[0].prev = &l->arr[l->len - 1].data;
				l->arr[l->len - 1].next = &l->arr[0].data;
				l->arr[l->len - 1].prev = &l->arr[l->len - 2].data;
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
void toStringDoubleLinkedlist(doubleLinkedlist l) {
	if (l.len == 0) {
		printf("[]");
	} else {
		printf("[\n");
		for (int i = 0; i < l.len - 1; i++) {
			printf("\t{ data: %d, next node data: %d, prev node data: %d }, \n",
				   l.arr[i].data, *l.arr[i].next, *l.arr[i].prev);
		}
		printf("\t{ data: %d, next node data: %d, prev node data: %d }\n",
			   l.arr[l.len - 1].data, *l.arr[l.len - 1].next,
			   *l.arr[l.len - 1].prev);
		printf("]");
	}
}

doubleLinkedlist createDoubleLinkedlist(int first) {
	doubleLinkedlist l;
	doubleNode n1;
	n1.data = first;
	n1.next = 0;
	n1.prev = 0;
	l.arr = malloc(sizeof(n1));
	l.arr[0] = n1;
	l.len = 1;
	return l;
}