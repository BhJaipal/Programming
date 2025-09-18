#ifndef C_IMPL
#define C_IMPL

#include "syscall.h"
#include "types.h"
#include "string.h"
#include "malloc.h"

int rev_d(int x);
uint32 rev_u(uint32 x);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(unsigned int x);
extern unsigned read_uint();
extern void write_int(int x);
extern int read_int();

extern void print(const char *str);

extern void println(const char *str);

#define null (void *)0

#endif // !C_IMPL
