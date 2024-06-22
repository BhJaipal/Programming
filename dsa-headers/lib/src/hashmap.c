#include "../include/hashmap.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

hashmap createHashmap(int firstKey, char *firstVal) {
	hashmap map;
	pair p;
	p.key = firstKey;
	p.val = malloc(sizeof(firstVal));
	strcpy(p.val, firstVal);
	map.arr = malloc(sizeof(p));
	map.arr[0] = p;
	map.len = 1;
	return map;
}
void toStringHashmap(hashmap m) {
	printf("{ ");
	for (int i = 0; i < m.len - 1; i++) {
		printf("%d=>%s, ", m.arr[i].key, m.arr[i].val);
	}
	printf("%d=>%s ", m.arr[m.len - 1].key, m.arr[m.len - 1].val);
	printf("}");
}
void pushPair(hashmap *h, int key, char *val) {
	for (int i = 0; i < h->len; i++) {
		if (h->arr[i].key == key) {
			h->arr[i].val = realloc(h->arr[i].val, sizeof(val));
			strcpy(h->arr[i].val, val);
			return;
		}
	}
	pair p;
	p.key = key;
	p.val = malloc(sizeof(val));
	strcpy(p.val, val);
	h->arr = realloc(h->arr, sizeof(h->arr) + sizeof(p));
	h->arr[h->len++] = p;
}

int *keys(hashmap *h) {
	int *kys = malloc(h->len * sizeof(int));
	for (int i = 0; i < h->len; i++) { kys[i] = h->arr[i].key; }
	return kys;
}
int containsKey(hashmap *h, int k) {
	int *kys = keys(h);
	for (int i = 0; i < h->len; i++) {
		if (k == kys[i]) { return 1; }
	}
	return 0;
}
