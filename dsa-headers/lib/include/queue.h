#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int len;
	int *arr;
} queue;

queue createQueue();
int deque(queue *);
void enque(queue *, int);
int peek(queue *);
void toStringPrintQueue(queue);
#endif