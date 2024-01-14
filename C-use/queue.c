#include <stdio.h>
#include <stdlib.h>
#define SENTINAL -1

typedef struct Queue {
  int *arr;
  int length;
} Queue;

Queue createQueue(int *arr, int len) {
  Queue out;
  out.length = len;
  out.arr = malloc(sizeof(int) * out.length);
  for (int i = 0; i < out.length; i++) {
    out.arr[i] = arr[i];
  }
  return out;
}

void enque(Queue *, int);
int deque(Queue *);
int peek(Queue que) { return que.arr[0]; }
void printQueue(Queue que) {
  for (int i = 0; i < que.length; i++) {
    printf("%d ", que.arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {4, 3, 7, 6};
  Queue que = createQueue(arr, sizeof(arr) / sizeof(int));
  printf("Queue: ");
  printQueue(que);
  enque(&que, 9);
  printf("After adding, Queue: ");
  printQueue(que);
  printf("Last: %d\n", que.arr[que.length - 1]);
  return EXIT_SUCCESS;
}

void enque(Queue *arr, int elem) {
  Queue arr2 = *arr;
  arr->arr = realloc(arr->arr, sizeof(int) * (arr2.length + 1));
  arr->arr[arr2.length] = elem;
  arr->length++;
}

int deque(Queue *que) {
  Queue arr2 = *que;
  int last = arr2.arr[0];
  for (int i = 0; i < que->length - 2; i++) {
    que->arr[i]= que->arr[i + 1];
  }
  que->length--;
  que->arr = realloc(que->arr, sizeof(int) * (que->length));
  return last;
}
