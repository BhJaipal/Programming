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
		}
	}
	pair p;
	p.key = key;
	p.val = malloc(sizeof(val));
	strcpy(p.val, val);
	h->arr = realloc(h->arr, sizeof(h->arr[0]) * (h->len + 1));
	h->arr[h->len++] = p;
}
void pushPairIfNotExists(hashmap *h, int key, char *val) {
	if (!containsKey(h, key)) {
		pair p;
		p.key = key;
		p.val = malloc(sizeof(val));
		strcpy(p.val, val);
		h->arr = realloc(h->arr, sizeof(h->arr) + sizeof(p));
		h->arr[h->len++] = p;
	}
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
int containsValue(hashmap *h, char *val) {
	for (int i = 0; i < h->len; i++) {
		if (strcmp(h->arr[i].val, val)) return 1;
	}
	return 0;
}
void replaceValue(hashmap *h, int key, char *val) {
	for (int i = 0; i < h->len; i++) {
		if (key == h->arr[i].key) {
			h->arr[i].val = "";
			h->arr[i].val = realloc(h->arr[i].val, sizeof(val));
			strcpy(h->arr[i].val, val);
		}
	}
}
pair removePair(hashmap *h, int key) {
	for (int i = 0; i < h->len; i++) {
		if (h->arr[i].key == key) {
			pair p = h->arr[i];
			size_t arrSize = sizeof(h->arr[0]) * (h->len - 1);
			if (i == h->len - 1) {
				h->arr = realloc(h->arr, arrSize);
				h->len--;
			} else {
				for (int j = i; j < h->len - 1; j++) {
					h->arr[j].key = h->arr[j + 1].key;
					h->arr[j].val = h->arr[j + 1].val;
				}
				h->arr = realloc(h->arr, arrSize);
				h->len--;
			}
			return p;
		}
	}
	pair p;
	p.key = key;
	p.val = "";
	return p;
}
char *get(hashmap *h, int k) {
	for (int i = 0; i < h->len; i++) { return h->arr[i].val; }
	return "";
}
