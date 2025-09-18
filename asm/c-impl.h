#include "syscall.h"
#include "types.h"

int rev_d(int x);
uint32 rev_u(uint32 x);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(unsigned int x);
extern unsigned read_uint();
extern void write_int(int x);
extern int read_int();

extern unsigned strlen(const char *str);

extern void print(const char *str);

extern void println(const char *str);

extern void* malloc(size_t size);
extern void free(void *ptr);

/*  @brief Use this if you want to create your own heap allocator */
extern void* heap_new(PageProtection prot, MapProps flags, int fd, size_t total_size);
/* @brief malloc that can be used with your custom heap */
extern void* heap_malloc(void *heap, size_t size);
/* @brief free that can be used with your custom heap */
extern void heap_free(void *heap, void *ptr);
/* @brief Destroy the heap */
extern void heap_destroy(void* heap);

#define null (void *)0
