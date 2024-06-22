#include "../include/hashset.h"
#include <malloc.h>
#include <stdio.h>

void pushHashset(hashset *s, int x) {
	for (int i = 0; i < s->len; i++) {
		if (s->arr[i] == x) { return; }
	}
	s->arr = realloc(s->arr, sizeof(int) * (++s->len));
	s->arr[s->len - 1] = x;
}
hashset createHashset() {
	hashset s;
	s.len = 0;
	s.arr = malloc(sizeof(int) * s.len);
	return s;
}
int popHashset(hashset *s, int i) {
	if (s->len > 0) {
		if (i >= s->len) {
			printf("Index out of range\n");
			return -1;
		}
		s->len--;
		int last = s->arr[i];
		if (i != s->len - 1) {
			for (int j = i; j < s->len - 1; j++) { s->arr[i] = s->arr[i + 1]; }
		}
		s->arr[s->len] = 0;
		s->arr = realloc(s->arr, sizeof(int) * (s->len));
		return last;
	} else {
		printf("hashset is empty\n");
		return -1;
	}
}
void toStringHashset(hashset q) {
	printf("{ ");
	for (int i = 0; i < q.len - 1; i++) { printf("%d, ", q.arr[i]); }
	if (q.len > 0) printf("%d ", q.arr[q.len - 1]);
	printf("}");
}