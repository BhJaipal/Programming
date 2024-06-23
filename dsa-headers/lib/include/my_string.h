#ifndef MY_STRING_H
#define MY_STRING_H
#include <stddef.h>
typedef struct {
	char *str;
	int len;
} string;

string initString(char *str, size_t size);
void appendStr(string *s, char *str);
int myStrlen(char *str);
void my_strcpy(char *dest, int n, char *src);
#endif