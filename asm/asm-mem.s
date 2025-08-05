	.global _start
	.text

_start:
	mov $0, %rdi
	mov $4, %rsi
	call mmap

	mov $0x69614a, %rax
	movq %rax, %rdi
	mov $4, %rsi
	call write

	movq %rax, %rdi
	call munmap

	mov $0, %rdi
	call exit
