.text
.globl _start

_start:
	mov $4, %rsi
	mov $0, %rdi
	call mmap

	mov $0xa69614a, (%rax)
	movq %rax, %rdi
	mov  $4, %rsi
	call write

	call munmap

	mov  $0, %rdi
	call exit
