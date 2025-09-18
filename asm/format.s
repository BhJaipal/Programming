	.file	"format.c"
	.text
	.section	.rodata
.LC0:
	.string	" "
	.text
	.globl	format
	.type	format, @function
format:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$208, %rsp
	movq	%rdi, -200(%rbp)
	movq	%rsi, -168(%rbp)
	movq	%rdx, -160(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L3
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L3:
	movq	-200(%rbp), %rax
	movq	%rax, %rdi
	call	println@PLT
#APP
# 5 "format.c" 1
	pop %rax

# 0 "" 2
# 7 "format.c" 1
	pop %rax

# 0 "" 2
#NO_APP
	movq	%rax, -192(%rbp)
	movq	-192(%rbp), %rax
	movl	%eax, %edi
	call	write_uint@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	print@PLT
#APP
# 11 "format.c" 1
	pop %rax

# 0 "" 2
#NO_APP
	movq	%rax, -184(%rbp)
	movq	-184(%rbp), %rax
	movq	%rax, %rdi
	call	println@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	format, .-format
	.section	.rodata
.LC1:
	.string	"World"
.LC2:
	.string	"Hello {}"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	format
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
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
