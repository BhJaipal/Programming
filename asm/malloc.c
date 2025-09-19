#include "malloc.h"
#include "c-impl.h"
#include "syscall.h"

typedef enum {
	HeapAlloc,
	HeapDealloc,
} HeapEvent;

typedef struct Ptr Ptr;
struct Ptr {
	Ptr *next;
	void *ptr;
	size_t size;
};
typedef struct {
	Ptr *head;
	Ptr *end;
	size_t node_size;
	PageProtection prot;
	MapProps flags;
	int fd;
} Heap;

Heap* heap_init() {
	Heap *heap = mmap(null, sizeof(Heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	heap->head = null;
	heap->node_size = sizeof(Ptr);
	return heap;
}
void heap_destroy(void *_heap) {
	if (!_heap) {
		munmap(_heap, sizeof(Heap));
		return;
	}
	Heap *heap = _heap;
	Ptr *head = heap->head;
	Ptr *prev = null;

	while (head) {
		prev = head;
		head = head->next;
		munmap(prev->ptr, prev->size);
		munmap(prev, heap->node_size);
	}
	munmap(heap, sizeof(Heap));
}
void heap_add_node(Heap *heap, void *ptr, size_t size) {
	if (!heap->head) {
		heap->head = mmap(null, heap->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		heap->head->ptr = ptr;
		heap->head->size = size;
		heap->head->next = null;
		heap->end = heap->head;
		return;
	}
	Ptr *next = mmap(null, heap->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	next->ptr = ptr;
	next->size = size;
	next->next = null;

	heap->end->next = next;
	heap->end = next;
}
void heap_delete_node(Heap *heap, void *val) {
	Ptr *head = heap->head;
	if (!head) return;
	Ptr *prev = null;

	while (head->ptr != val) {
		prev = head;
		head = head->next;
	}
	if (prev)
		prev->next = head->next;
	munmap(head->ptr, head->size);
	munmap(head, heap->node_size);
	prev->next = null;
}

Heap* heap = null;
void set_global_heap(void *_heap) {
	heap = _heap;
}
void global_heap_destroy() {
	heap_destroy(heap);
}

void heap_update(Heap *heap, HeapEvent event, void *ptr, size_t len) {
	switch (event) {
		case HeapAlloc:
			heap_add_node(heap, ptr, len);
			break;
		case HeapDealloc:
			heap_delete_node(heap, ptr);
			break;
		default:
			println("Calling 'heap_update' with other parameters is invalid");
			break;
	}
}

void memcpy(uint8 *dest, const uint8 *src, size_t n) {
	for (size_t i = 0; i < n; i++) {
		dest[i] = src[i];
	}
}

void* heap_new(PageProtection prot, MapProps flags, int fd) {
	Heap *heap = heap_init();
	heap->fd = fd;
	heap->prot = prot;
	heap->flags = flags;
	return heap;
}

void* heap_malloc(void *heap, size_t size) {
	void *ptr = mmap(0, size, ((Heap*)heap)->prot,
				  ((Heap*)heap)->flags, ((Heap*)heap)->fd, 0);
	heap_update(heap, HeapAlloc, ptr, size);
	return ptr;
}
void* malloc(size_t size) {
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	heap_update(heap, HeapAlloc, ptr, size);
	return ptr;
}
void* heap_realloc(void *heap, void *ptr, size_t size) {
	void *new_ptr = mmap(0, size, ((Heap*)heap)->prot,
				  ((Heap*)heap)->flags, ((Heap*)heap)->fd, 0);

	Ptr *head = ((Heap*)heap)->head;
	size_t len;
	while (head) {
		if (head->ptr != ptr)
			head = head->next;
		else {
			len = head->size;
			head->ptr = new_ptr;
			head->size = size;
			break;
		}
	}
	memcpy(new_ptr, ptr, len);
	munmap(ptr, len);
	return new_ptr;
}
void* realloc(void *ptr, size_t size) {
	void *new_ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	Ptr *head = ((Heap*)heap)->head;
	size_t len;
	while (head) {
		if (head->ptr != ptr)
			head = head->next;
		else {
			len = head->size;
			head->ptr = new_ptr;
			head->size = size;
			break;
		}
	}
	memcpy(new_ptr, ptr, len);
	munmap(ptr, len);
	return new_ptr;
}
void heap_free(void *heap, void *ptr) {
	heap_delete_node(heap, ptr);
}

void free(void *ptr) {
	heap_delete_node(heap, ptr);
}
