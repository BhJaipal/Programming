#include "syscall.h"

void read(int fd, char *msg, int len) {
	size_t ptr = fd;
	asm("mov %0, %%rdi\n"::"r"(ptr));
	ptr = len;
	asm("mov %0, %%rdx\n"::"r"(ptr));
	asm("mov %0, %%rsi\n"::"r"(msg));
	asm("mov $0, %rax\n");
	asm("syscall\n");
}
void write(int fd, const char *msg, int len) {
	size_t ptr = fd;
	asm("mov %0, %%rdi\n"::"r"(ptr));
	ptr = len;
	asm("mov %0, %%rdx\n"::"r"(ptr));
	asm("mov %0, %%rsi\n"::"r"(msg));
	asm("mov $1, %rax\n");
	asm("syscall\n");
}

void exit(int status) {
	size_t data = status;
	asm("mov %0, %%rdi\n"::"r"(data));
	asm("mov $60, %rax\n");
	asm("syscall\n");
	__builtin_unreachable();
}
#define ST (size_t)
#define null (void*)0

void *mmap (void *__addr, size_t __len, PageProtection __prot,
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
