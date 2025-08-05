.text
.globl _start

_start:
	push $4
	push $0
	call malloc

	mov  $0xa69614a, %rdi
	mov  %rdi, (%rax)
	movq %rax, %rdi
	push %rax
	mov  $4, %rsi
	call write

	pop  %rdi
	call munmap

	mov  $0, %rdi
	call exit
