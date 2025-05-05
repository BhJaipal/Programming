.global _start

.data
str:
	.ascii "Enter name: "
name:
	.ascii ""
output:
	.ascii "       Name: "
endl:
	.ascii "\n"

.text
_start:
	movq $1, %rax
	movq $1, %rdi
	movq $str, %rsi
	movq $12, %rdx
	syscall

	movq $0, %rax
	movq $0, %rdi
	movq $name, %rsi
	movq $7, %rdx
	syscall

	movq $1, %rax
	movq $1, %rdi
	movq $output, %rsi
	movq $15, %rdx
	syscall

	movq $1, %rax
	movq $1, %rdi
	movq $name, %rsi
	movq $7, %rdx
	syscall

	movq $60, %rax
	movq $0, %rdi
	syscall
