#include "c-impl.h"
#define ST (size_t)
inline void putchar(char c) {
	write(&c, 1);
}

int pow(int b, int e) {
	int out = 1;
	for (unsigned i = 0; i < e; i++) {
		out *= b;
	}
	return out;
}

void write_uint(unsigned int x) {
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}
	int exp = 1;
	while (x/pow(10, exp))
		exp++;

	for (int i = exp - 1; i >= 0; i--) {
		int val = x % pow(10, i + 1);
		val /= pow(10, i);
		putchar(val + 0x30);
	}
}

unsigned int read_uint() {
	unsigned int x = 0;
	char num[11];
	for (int i = 0; i < 11;i++) {
		read(num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (num[i] <= '0' || num[i] >= '9') {
			write("\e[91mERROR: \e[0m", 17);
			write("Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		x *= 10;
		x += num[i] - 0x30;
	}
	return x;
}
void write_int(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}

	int exp = 1;
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	while (x / pow(10, exp))
		exp++;
	for (int i = exp - 1; i >= 0; i--) {
		int val = x % pow(10, i + 1);
		val /= pow(10, i);
		putchar(val + 0x30);
	}
}

int read_int() {
	int x = 0;
	char num[11];
	for (int i = 0; i < 11; i++) {
		read(num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		else if (i == 0 && num[i] == '-')
			continue;
		else if (num[i] <= '0' || num[i] >= '9') {
			write("\e[91mERROR: \e[0m", 17);
			write("Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (i == 0 && num[0] == '-')
			continue;
		x *= 10;
		x += num[i] - 0x30;
	}
	if (num[0] == '-')
		x = -x;
	return x;
}


unsigned strlen(const char *str) {
	unsigned i = 0;
	while (str[i]) { i++; }
	return i;
}

void print(const char *str) {
	unsigned i = strlen(str);
	write(str, i);
}

void println(const char *str) {
	write(str, strlen(str));
	putchar(10);
}
void *mmap (void *__addr, size_t __len, MemPermission __prot,
		   MapProps __flags, int __fd, long __offset) {
	void *ptr;
	size_t a = __fd;
	asm("mov %0, %%r8\n" ::"r"(a));
	a = __flags;
	asm("mov %0, %%r10\n" ::"r"(a));
	a = __prot;
	asm("mov %0, %%rdx\n" ::"r"(a));

	asm("mov %0, %%rsi\n" ::"r"(__len));
	asm("mov %0, %%rdi\n" ::"r"(__addr));
	asm("mov %0, %%r9\n" ::"r"(__offset));
	asm("mov $9, %rax\n");
	asm("syscall\n");
	asm("mov %%rax, %0\n": "=r"(ptr));
	return ST ptr == -1 ? null : ptr;
}
void munmap(void *ptr, size_t size) {
	asm("mov $11, %rax\n");
	asm("mov %0, %%rsi\n" ::"r"(size));
	asm("mov %0, %%rdi\n" ::"r"(ptr));
}

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
void heap_destroy(Heap *heap) {
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

typedef enum {
	HeapAlloc,
	HeapDealloc,
} HeapEvent;

Heap* heap = null;

void heap_update(HeapEvent event, void *ptr, size_t len) {
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
	heap_update(HeapAlloc, ptr, size);
	return ptr;
}

void free(void *ptr) {
	heap_update(HeapDealloc, ptr, 0);
}

extern int main();

void _start() {
	heap = heap_init(1096);
	exit(main());
	heap_destroy(heap);
}
