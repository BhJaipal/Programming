#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct _pair {
	int key;
	char *val;
} pair;

typedef struct _hashmap {
	int len;
	pair *arr;
} hashmap;

hashmap createHashmap(int firstKey, char *firstVal);
void toStringHashmap(hashmap m);
void pushPair(hashmap *h, int key, char *val);
int *keys(hashmap *h);
int containsKey(hashmap *h, int k);

#endif