	.text
	.globl putchar
	.type putchar, @function

	.globl write
	.type write, @function

	.globl exit
	.type exit, @function

write:
	movq %rsi, %rdx
	movq %rdi, %rsi
	mov $1, %rax
	mov $1, %rdi
	syscall
	ret

exit:
	mov $60, %rax
	syscall
	ret
