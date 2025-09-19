#include "c-impl.h"

char toupper(char ch) {
	if (ch >= 0x61 && ch <= 0x7a)
		return ch - 0x20;
	return ch;
}
char tolower(char ch) {
	if (ch >= 0x41 && ch <= 0x5a)
		return ch + 0x20;
	return ch;
}

size_t strlen(const char *str) {
	unsigned i = 0;
	while (str[i]) { i++; }
	return i;
}
size_t strnlen(const char *str, size_t n) {
	unsigned i = 0;
	while (i <= n && str[i]) { i++; }
	return i;
}
void strcpy(char *dest, const char *src) {
	size_t src_len = strlen(src);

	for (size_t i = 0; i <= src_len; i++) {
		dest[i] = src[i];
	}
}
void strncpy(char *dest, const char *src, size_t n) {
	size_t src_len = strlen(src);

	for (size_t i = 0; i <= (n > src_len ? src_len : n); i++) {
		dest[i] = src[i];
	}
}
char* strcat(char* dest, const char* src) {
	size_t dest_len = strlen(dest);
	size_t src_len = strlen(src);

	for (size_t i = 0; i <= src_len; i++) {
		dest[dest_len + i] = src[i];
	}
	return dest;
}

char* strncat(char* dest, const char* src, size_t n) {
	size_t dest_len = strlen(dest);
	size_t src_len = strlen(src);

	for (size_t i = 0; i <= (n > src_len ? src_len : n); i++) {
		dest[dest_len + i] = src[i];
	}
	return dest;
}
int strcmp(const char *s1, const char *s2) {
	size_t i = 0;
	while (s1[i] == s2[i]) {
		if (s1[i] == 0) return 0;
		i++;
	}
	return -1;
}
int strncmp(const char *s1, const char *s2, size_t n) {
	size_t i = 0;
	while (i < n && s1[i] == s2[i]) {
		if (s1[i] == 0) return 0;
		i++;
	}
	return -1;
}

int strcmpcase(const char *s1, const char *s2) {
	size_t i = 0;
	char c1 = toupper(s1[i]),
		c2 = toupper(s2[i]);

	while (c1 == c2) {
		if (c1 == 0) return 0;
		c1 = toupper(s1[i+1]),
		c2 = toupper(s2[i+1]);
		i++;
	}
	return -1;
}
int strncmpcase(const char *s1, const char *s2, size_t n) {
	size_t i = 0;
	char c1 = toupper(s1[i]),
		c2 = toupper(s2[i]);

	while (i < n && c1 == c2) {
		if (c1 == 0) return 0;
		c1 = toupper(s1[i+1]),
		c2 = toupper(s2[i+1]);
		i++;
	}
	return -1;
}
