#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _singleNode {
	int data;
	int *next;
} singlyNode;

typedef struct _linkedlist {
	singlyNode *arr;
	int len;
} linkedlist;

int removeNode(linkedlist *, int);
linkedlist createLinkedlist(int);
void add(linkedlist *, int, int);
void toStringLinkedlist(linkedlist);

#endif