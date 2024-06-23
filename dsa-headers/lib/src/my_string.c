#include "../include/my_string.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

string initString(char *str, size_t size) {
	string s;
	s.len = myStrlen(str);
	s.str = malloc(size);
	my_strcpy(s.str, s.len, str);
	s.str = realloc(s.str, sizeof(char) * myStrlen(s.str) + 1);
	return s;
}
void appendStr(string *s, char *str) {
	int lenStr = myStrlen(str);
	s->len = sizeof(s->str) + lenStr + 1;
	s->str = realloc(s->str, (s->len) * sizeof(char));

	int stLen = myStrlen(s->str);
	for (int i = 0; i < lenStr; i++) {
		if (i != lenStr + s->len - 1 && s->str[i + s->len] == '\0')
			s->str[i + stLen] = str[i];
	}
	s->str = realloc(s->str, (stLen) * sizeof(char));
}
int myStrlen(char *str) {
	int i = 0;
	while (1) {
		if (str[i] == '\0') { break; }
		i++;
	}
	return i;
}
void my_strcpy(char *dest, int n, char *src) {
	for (int i = 0; i < n; i++) { dest[i] = src[i]; }
	dest[n] = '\0';
}
