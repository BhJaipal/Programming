#ifndef MY_STRING_H
#define MY_STRING_H

#include "types.h"

char toupper(char ch);
char tolower(char ch);

size_t strlen(const char *str);
size_t strnlen(const char *str, size_t n);
void strcpy(char *dest, const char *src);
void strncpy(char *dest, const char *src, size_t n);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
int strcmpcase(const char *s1, const char *s2);
int strncmpcase(const char *s1, const char *s2, size_t n);

#endif // !MY_STRING_H
