#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue {
  int len;
  int *arr;
} queue;

queue createQueue();
#endif