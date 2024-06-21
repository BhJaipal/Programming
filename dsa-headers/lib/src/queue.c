#include "../include/queue.h"
#include <malloc.h>
#include <stdio.h>

queue createQueue() {
	queue q;
	q.arr = malloc(sizeof(int));
	q.len = 0;
	return q;
}
void enque(queue *q, int x) {
	q->arr = realloc(q->arr, sizeof(int) * (++q->len));
	q->arr[q->len - 1] = x;
}
int peek(queue *q) {
	if (q->len > 1) {
		return q->arr[q->len - 1];
	} else {
		printf("Queue is empty\n");
		return -1;
	}
}
int deque(queue *q) {
	if (q->len > 1) {
		int first = q->arr[0];
		for (int i = 0; i < q->len - 1; i++) { q->arr[i] = q->arr[i + 1]; }
		q->arr[--q->len] = 0;
		q->arr = realloc(q->arr, sizeof(int) * q->len);
		return first;
	} else {
		printf("Queue is empty\n");
		return -1;
	}
}
void toStringPrintQueue(queue q) {
	printf("[ ");
	for (int i = 0; i < q.len - 1; i++) { printf("%d, ", q.arr[i]); }
	if (q.len > 0) printf("%d ", q.arr[q.len - 1]);
	printf("]");
}