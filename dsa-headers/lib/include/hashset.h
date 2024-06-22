#ifndef HASHSET_H
#define HASHSET_H

typedef struct {
	int *arr;
	int len;
} hashset;

void pushHashset(hashset *s, int x);
hashset createHashset();
int popHashset(hashset *s, int i);
void toStringHashset(hashset);

#endif