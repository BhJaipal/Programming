	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	" is greatest\n"
	.text
	.globl	_start
	.type	_start, @function
_start:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, -8(%rbp)
	movl	$7, -12(%rbp)
	movl	$9, -16(%rbp)
	movl	$15, %edi
	call	printd@PLT
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jle	.L2
	movl	-8(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jle	.L3
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L3:
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L2:
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jle	.L5
	movl	-12(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L5:
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
.L4:
	movl	$10, %edi
	call	putchar@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	printd@PLT
	movl	$14, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	write@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE0:
	.size	_start, .-_start
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
