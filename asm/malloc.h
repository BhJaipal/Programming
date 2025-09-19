#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#include "types.h"
#include "syscall.h"

extern void* malloc(size_t size);
extern void* realloc(void *ptr, size_t size);
extern void free(void *ptr);

void memcpy(uint8 *dest, const uint8 *src, size_t n);
/*  @brief Use this if you want to create your own heap allocator */
extern void* heap_new(PageProtection prot, MapProps flags, int fd);
/* @brief malloc that can be used with your custom heap */
extern void* heap_malloc(void *heap, size_t size);
/* @brief realloc that can be used with your custom heap */
extern void* heap_realloc(void *heap, void *ptr, size_t size);
/* @brief free that can be used with your custom heap */
extern void heap_free(void *heap, void *ptr);
/* @brief Destroy the heap */
extern void heap_destroy(void* heap);

#endif // !MY_MALLOC_H
