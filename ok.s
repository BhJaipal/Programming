	.file	"ok.c"
	.text
	.section	.rodata
.LC0:
	.string	"Hello World\n"
	.text
	.globl	_start
_start:
	movl	$13, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	write@PLT
	movl	$0, %edi
	call	exit@PLT
