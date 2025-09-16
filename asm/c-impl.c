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
LinkedList* ll_new(size_t node_size) {
	LinkedList* ll = mmap(null, sizeof(LinkedList), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	ll->head = null;
	ll->node_size = node_size;
	return ll;
}
void ll_add_node(LinkedList *ll, size_t val) {
	if (!ll->head) {
		ll->head = mmap(null, sizeof(ll->node_size), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		ll->head->value = val;
		ll->head->next = null;
		return;
	}
	Node *head = ll->head;
	while (head->next) {
		head = head->next;
	}
	head->next = mmap(null, sizeof(ll->node_size), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	head->next->value = val;
	head->next->next = null;
}
void ll_delete_node(LinkedList *ll, size_t val) {
	Node *head = ll->head;
	if (!head) return;
	Node *prev = null;

	while (head && head->value != val) {
		prev = head;
		head = head->next;
	}
	prev->next = head->next;
	munmap(head, ll->node_size);
}
void ll_destroy(LinkedList *ll) {
	Node *head = ll->head;
	Node *prev = null;

	while (head) {
		prev = head;
		head = head->next;
		munmap(prev, ll->node_size);
	}
}
