.data
char:
	.byte
str:
	.string ""
num:
	.long 0

	.text
	.globl putchar
	.type putchar, @function

	.globl write
	.type write, @function

	.globl exit
	.type exit, @function

putchar:
	mov %rax, char(%rip)
	mov $char, %rsi
	mov $1, %rdi
	mov $1, %rax
	mov $1, %rdx
	syscall
	ret
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
