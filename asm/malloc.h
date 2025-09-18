#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#include "types.h"
#include "syscall.h"

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

#endif // !MY_MALLOC_H
