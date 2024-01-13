#include <stdio.h>
#include <stdlib.h>

typedef char string[];
typedef int Node;

typedef struct Array {
  Node *list;
  int length;
} Array;

int len(Array);
/**
 * @param list takes an array of integers
 * @returns An array struct
 */
Array createArr(int list[]) {
  Array arr;
  arr.length = 5;
  arr.list = malloc(5 * sizeof(Node));
  for (int i = 0; i < 5; i++) {
    arr.list[i] = list[i];
  }
  return arr;
}
/**
 * @param *arr Array in which element has to be added
 * @param elem Element to be added to array
 * @return Nothing
 */
void push(Array *arr, int elem) {
  Array defref = *arr;
  arr->length++;
  Node arr2[sizeof(defref) / sizeof(int)];
  for (int i = 0; i < len(defref); i++) {
    arr2[i] = defref.list[i];
  }
  arr->list = realloc(arr->list, sizeof(elem) + (sizeof(int) * len(defref)));
  arr->list[arr->length - 1] = elem;
}
int pop(Array *arr) {
  Array arr2 = *arr;
  Node last = arr2.list[len(arr2) - 1];
  arr->list[arr2.length - 1] = 0;
  arr->length--;
  arr->list = realloc(arr->list, (sizeof(int) * (len(arr2) - 1)));
  return last;
}

int len(Array arr) { return arr.length; }

int printArray(Array *arr) {
  Array arr2 = *arr;
  for (int i = 0; i < len(arr2); i++) {
    printf("%d ", arr->list[i]);
  }
  printf("\n");
  return len(arr2);
}

int main() {
  string name = "Jaipal";
  Node list[5] = {3, 5, 4, 2, 7};
  Array arr = createArr(list);
  printf("Array is: ");
  printf("Length of array: %d\n", printArray(&arr));
  printf("Poped last element: %d\n", pop(&arr));
  printf("After removing last element: ");
  printArray(&arr);
  printf("After pushing 10: ");
  push(&arr, 10);
  printf("Length of array: %d\n", printArray(&arr));
  free(arr.list);
  return 0;
}
