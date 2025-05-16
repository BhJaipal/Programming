	.file	"c-impl.c"
	.text
	.globl	putchar
	.type	putchar, @function
putchar:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	leaq	-4(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	write@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	putchar, .-putchar
	.globl	pow
	.type	pow, @function
pow:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	cmpl	$0, -24(%rbp)
	jne	.L3
	movl	$1, %eax
	jmp	.L4
.L3:
	cmpl	$1, -24(%rbp)
	jne	.L5
	movl	-20(%rbp), %eax
	jmp	.L4
.L5:
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-20(%rbp), %eax
	imull	%eax, %eax
	movl	%eax, -20(%rbp)
	addl	$1, -4(%rbp)
.L6:
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L7
	movl	-20(%rbp), %eax
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	pow, .-pow
	.globl	printd
	.type	printd, @function
printd:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	cmpl	$9, -20(%rbp)
	ja	.L9
	movl	-20(%rbp), %eax
	addl	$48, %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	jmp	.L8
.L9:
	movl	$1, -4(%rbp)
	jmp	.L11
.L12:
	addl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$10, %edi
	call	pow
	cmpl	%eax, -20(%rbp)
	jnb	.L12
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movl	$10, %edi
	call	pow
	movl	%eax, %ecx
	movl	-20(%rbp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$10, %edi
	call	pow
	movl	%eax, %ecx
	movl	-12(%rbp), %eax
	cltd
	idivl	%ecx
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	addl	$48, %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	subl	$1, -8(%rbp)
.L13:
	cmpl	$0, -8(%rbp)
	jns	.L14
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	printd, .-printd
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
