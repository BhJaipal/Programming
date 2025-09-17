	.text
	.globl _start

_start:
	pop %rsi
	mov %rsp, %rdx
	call _libc_main
