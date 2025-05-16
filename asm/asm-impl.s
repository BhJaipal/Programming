	.text
	.globl read
	.type read, @function

	.globl write
	.type write, @function

	.globl exit
	.type exit, @function

read:
	movq %rsi, %rdx
	movq %rdi, %rsi
	mov  $0, %rax
	mov  $0, %rdi
	syscall
	ret
write:
	movq %rsi, %rdx
	movq %rdi, %rsi
	mov  $1, %rax
	mov  $1, %rdi
	syscall
	ret

exit:
	mov  $60, %rax
	syscall
	ret
