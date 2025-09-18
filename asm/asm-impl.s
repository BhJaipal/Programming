	.text
	.globl _start
	.type _start, @function

_start:
	pop %rsi
	mov %rsp, %rdx
	call _libc_main
