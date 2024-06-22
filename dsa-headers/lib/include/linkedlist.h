#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
	int data;
	int *next;
} singlyNode;
typedef struct {
	int data;
	int *prev;
	int *next;
} doubleNode;

typedef struct {
	singlyNode *arr;
	int len;
} linkedlist;
typedef struct {
	doubleNode *arr;
	int len;
} doubleLinkedlist;

int removeNode(linkedlist *, unsigned int);
linkedlist createLinkedlist(int);
void add(linkedlist *, int, unsigned int);
void toStringLinkedlist(linkedlist);

int removeDoubleNode(doubleLinkedlist *, unsigned int);
doubleLinkedlist createDoubleLinkedlist(int);
void addDoubleNode(doubleLinkedlist *, int, unsigned int);
void toStringDoubleLinkedlist(doubleLinkedlist);

#endif