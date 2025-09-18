#include "c-impl.h"

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
	size_t node_size;
	size_t total_size;
	PageProtection prot;
	MapProps flags;
	int fd;
} Heap;

void heap_add_node(Heap *ll, void *ptr, size_t size) {
	if (!ll->head) {
		ll->head = mmap(null, ll->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		ll->head->ptr = ptr;
		ll->head->size = size;
		ll->head->next = null;
		return;
	}
	Ptr *head = ll->head;
	while (head->next) {
		head = head->next;
	}
	head->next = mmap(null, ll->node_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	head->next->ptr = ptr;
	head->next->size = size;
	head->next->next = null;
}
void heap_delete_node(Heap *ll, void *val) {
	Ptr *head = ll->head;
	if (!head) return;
	Ptr *prev = null;

	while (head && head->ptr != val) {
		prev = head;
		head = head->next;
	}
	if (prev)
		prev->next = head->next;
	munmap(head->ptr, head->size);
	munmap(head, ll->node_size);
}
Heap* heap_init(size_t heap_size) {
	Heap *heap = mmap(null, sizeof(Heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	heap->head = null;
	heap->total_size = heap_size;
	heap->node_size = sizeof(Ptr);
	return heap;
}
void heap_destroy(void *_heap) {
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
void* malloc(size_t size) {
	void *ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				  MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	heap_update(heap, HeapAlloc, ptr, size);
	return ptr;
}

void free(void *ptr) {
	heap_update(heap, HeapDealloc, ptr, 0);
}

void* heap_new(PageProtection prot, MapProps flags, int fd, size_t total_size) {
	Heap *heap = heap_init(total_size);
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
void heap_free(void *heap, void *ptr) {
	heap_update(heap, HeapDealloc, ptr, 0);
}
