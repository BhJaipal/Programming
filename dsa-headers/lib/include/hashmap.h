#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct {
	int key;
	char *val;
} pair;

typedef struct {
	int len;
	pair *arr;
} hashmap;

hashmap createHashmap(int firstKey, char *firstVal);
void toStringHashmap(hashmap m);
void replaceValue(hashmap *h, int key, char *val);
void pushPair(hashmap *h, int key, char *val);
void pushPairIfNotExists(hashmap *h, int key, char *val);
int *keys(hashmap *h);
int containsKey(hashmap *h, int k);
int containsValue(hashmap *h, char *val);
pair removePair(hashmap *h, int key);
char *get(hashmap *h, int k);

#endif