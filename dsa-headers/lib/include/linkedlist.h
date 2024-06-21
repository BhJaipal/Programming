#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _singleNode {
	int data;
	int *next;
} singlyNode;
typedef struct _doubleNode {
	int data;
	int *prev;
	int *next;
} doubleNode;

typedef struct _linkedlist {
	singlyNode *arr;
	int len;
} linkedlist;
typedef struct _doubleLinkedlist {
	doubleNode *arr;
	int len;
} doubleLinkedlist;

int removeNode(linkedlist *, int);
linkedlist createLinkedlist(int);
void add(linkedlist *, int, int);
void toStringLinkedlist(linkedlist);

int removeDoubleNode(doubleLinkedlist *, int);
doubleLinkedlist createDoubleLinkedlist(int);
void addDoubleNode(doubleLinkedlist *, int, int);
void toStringDoubleLinkedlist(doubleLinkedlist);

#endif