#include "queue.h"
#include <malloc.h>
#include <stdio.h>

queue createQueue() {
  queue q;
  q.arr = malloc(sizeof(int));
  q.len = 0;
  return q;
}