.text
	.globl _start

_start:
	mov $9, %rax # mmap for memory alloc
	mov $0, %rdi # memory location for allocation
	mov $4, %rsi # memory size
	mov $3, %rdx # read & write memory
	mov $0x22, %r10
	mov $0, %r8
	mov $0, %rbp
	syscall

	mov $0xa69614a, %rdi
	mov %rdi, (%rax)
	mov %rax, %rsi
	mov $4, %rdx
	mov $1, %rax
	mov $1, %rdi
	syscall

	mov %rsi, %rdi
	mov $0xb, %rax # #munmap for memory free
	syscall

	mov $60, %rax
	mov $0, %rdi
	syscall
