	.file	"ptr.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	"\033[34m[DEBUG]: \033[0m"
	.text
	.globl	_Z5debugPKcz
	.type	_Z5debugPKcz, @function
_Z5debugPKcz:
.LFB1731:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$224, %rsp
	movq	%rdi, -216(%rbp)
	movq	%rsi, -168(%rbp)
	movq	%rdx, -160(%rbp)
	movq	%rcx, -152(%rbp)
	movq	%r8, -144(%rbp)
	movq	%r9, -136(%rbp)
	testb	%al, %al
	je	.L2
	movaps	%xmm0, -128(%rbp)
	movaps	%xmm1, -112(%rbp)
	movaps	%xmm2, -96(%rbp)
	movaps	%xmm3, -80(%rbp)
	movaps	%xmm4, -64(%rbp)
	movaps	%xmm5, -48(%rbp)
	movaps	%xmm6, -32(%rbp)
	movaps	%xmm7, -16(%rbp)
.L2:
	movq	%fs:40, %rax
	movq	%rax, -184(%rbp)
	xorl	%eax, %eax
	movl	$8, -208(%rbp)
	movl	$48, -204(%rbp)
	leaq	16(%rbp), %rax
	movq	%rax, -200(%rbp)
	leaq	-176(%rbp), %rax
	movq	%rax, -192(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-208(%rbp), %rdx
	movq	-216(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	vprintf@PLT
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-184(%rbp), %rax
	subq	%fs:40, %rax
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1731:
	.size	_Z5debugPKcz, .-_Z5debugPKcz
	.section	.rodata
.LC1:
	.string	" "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1744:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, %edi
	call	_Z8make_ptrIiE7PointerIT_Em
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	leaq	-48(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5writeEi
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiEdeEv
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE7deallocEv
	leaq	-48(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5allocEm
	leaq	-48(%rbp), %rax
	movl	$7, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5writeEi
	leaq	-48(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiEplEj
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-32(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5writeEi
	leaq	-48(%rbp), %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiEplEj
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-32(%rbp), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5writeEi
	movq	$0, -56(%rbp)
	jmp	.L5
.L6:
	movq	-56(%rbp), %rax
	movl	%eax, %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN7PointerIiEplEj
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE4readEv
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	addq	$1, -56(%rbp)
.L5:
	cmpq	$2, -56(%rbp)
	jbe	.L6
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE7deallocEv
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1744:
	.size	main, .-main
	.section	.text._Z8make_ptrIiE7PointerIT_Em,"axG",@progbits,_Z8make_ptrIiE7PointerIT_Em,comdat
	.weak	_Z8make_ptrIiE7PointerIT_Em
	.type	_Z8make_ptrIiE7PointerIT_Em, @function
_Z8make_ptrIiE7PointerIT_Em:
.LFB2005:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiEC1Ev
	movq	-40(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN7PointerIiE5allocEm
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rcx
	subq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2005:
	.size	_Z8make_ptrIiE7PointerIT_Em, .-_Z8make_ptrIiE7PointerIT_Em
	.section	.rodata
.LC2:
	.string	"Curr size: %d, Pointer: %p"
	.section	.text._ZN7PointerIiE5writeEi,"axG",@progbits,_ZN7PointerIiE5writeEi,comdat
	.align 2
	.weak	_ZN7PointerIiE5writeEi
	.type	_ZN7PointerIiE5writeEi, @function
_ZN7PointerIiE5writeEi:
.LFB2006:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE13error_on_nullEv
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	_Z5debugPKcz
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2006:
	.size	_ZN7PointerIiE5writeEi, .-_ZN7PointerIiE5writeEi
	.section	.text._ZN7PointerIiEdeEv,"axG",@progbits,_ZN7PointerIiEdeEv,comdat
	.align 2
	.weak	_ZN7PointerIiEdeEv
	.type	_ZN7PointerIiEdeEv, @function
_ZN7PointerIiEdeEv:
.LFB2007:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE13error_on_nullEv
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2007:
	.size	_ZN7PointerIiEdeEv, .-_ZN7PointerIiEdeEv
	.section	.text._ZN7PointerIiE7deallocEv,"axG",@progbits,_ZN7PointerIiE7deallocEv,comdat
	.align 2
	.weak	_ZN7PointerIiE7deallocEv
	.type	_ZN7PointerIiE7deallocEv, @function
_ZN7PointerIiE7deallocEv:
.LFB2010:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L16
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L16
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv@PLT
.L16:
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2010:
	.size	_ZN7PointerIiE7deallocEv, .-_ZN7PointerIiE7deallocEv
	.section	.rodata
	.align 8
.LC3:
	.string	"Prev Size: %d, Curr size: %d, Pointer: %p"
.LC4:
	.string	"Address: %p, size: %d"
	.section	.text._ZN7PointerIiE5allocEm,"axG",@progbits,_ZN7PointerIiE5allocEm,comdat
	.align 2
	.weak	_ZN7PointerIiE5allocEm
	.type	_ZN7PointerIiE5allocEm, @function
_ZN7PointerIiE5allocEm:
.LFB2011:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L21
	movq	-8(%rbp), %rax
	movq	(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	-16(%rbp), %rdx
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	_Z5debugPKcz
	movq	-16(%rbp), %rax
	movabsq	$2305843009213693950, %rdx
	cmpq	%rdx, %rax
	ja	.L19
	salq	$2, %rax
	movq	%rax, %rdi
	call	_Znam@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	_Z5debugPKcz
	jmp	.L21
.L19:
	call	__cxa_throw_bad_array_new_length@PLT
.L21:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2011:
	.size	_ZN7PointerIiE5allocEm, .-_ZN7PointerIiE5allocEm
	.section	.rodata
	.align 8
.LC5:
	.string	"Cannot excess access outside scope of pointer\n"
	.section	.text._ZN7PointerIiEplEj,"axG",@progbits,_ZN7PointerIiEplEj,comdat
	.align 2
	.weak	_ZN7PointerIiEplEj
	.type	_ZN7PointerIiEplEj, @function
_ZN7PointerIiEplEj:
.LFB2012:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-40(%rbp), %rax
	movq	8(%rax), %rdx
	movl	-44(%rbp), %eax
	cmpq	%rax, %rdx
	ja	.L23
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$1, %edi
	call	exit@PLT
.L23:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movl	-44(%rbp), %ecx
	subq	%rcx, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rcx
	movl	-44(%rbp), %eax
	salq	$2, %rax
	addq	%rax, %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN7PointerIiEC1EPim
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rcx
	subq	%fs:40, %rcx
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2012:
	.size	_ZN7PointerIiEplEj, .-_ZN7PointerIiEplEj
	.section	.text._ZN7PointerIiE4readEv,"axG",@progbits,_ZN7PointerIiE4readEv,comdat
	.align 2
	.weak	_ZN7PointerIiE4readEv
	.type	_ZN7PointerIiE4readEv, @function
_ZN7PointerIiE4readEv:
.LFB2013:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7PointerIiE13error_on_nullEv
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2013:
	.size	_ZN7PointerIiE4readEv, .-_ZN7PointerIiE4readEv
	.section	.text._ZN7PointerIiEC2Ev,"axG",@progbits,_ZN7PointerIiEC5Ev,comdat
	.align 2
	.weak	_ZN7PointerIiEC2Ev
	.type	_ZN7PointerIiEC2Ev, @function
_ZN7PointerIiEC2Ev:
.LFB2093:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2093:
	.size	_ZN7PointerIiEC2Ev, .-_ZN7PointerIiEC2Ev
	.weak	_ZN7PointerIiEC1Ev
	.set	_ZN7PointerIiEC1Ev,_ZN7PointerIiEC2Ev
	.section	.rodata
.LC6:
	.string	"\033[91m[ERROR]:\033[0m "
.LC7:
	.string	"Null pointer exception\n"
	.section	.text._ZN7PointerIiE13error_on_nullEv,"axG",@progbits,_ZN7PointerIiE13error_on_nullEv,comdat
	.align 2
	.weak	_ZN7PointerIiE13error_on_nullEv
	.type	_ZN7PointerIiE13error_on_nullEv, @function
_ZN7PointerIiE13error_on_nullEv:
.LFB2095:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L31
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$1, %edi
	call	exit@PLT
.L31:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2095:
	.size	_ZN7PointerIiE13error_on_nullEv, .-_ZN7PointerIiE13error_on_nullEv
	.section	.text._ZN7PointerIiEC2EPim,"axG",@progbits,_ZN7PointerIiEC5EPim,comdat
	.align 2
	.weak	_ZN7PointerIiEC2EPim
	.type	_ZN7PointerIiEC2EPim, @function
_ZN7PointerIiEC2EPim:
.LFB2099:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2099:
	.size	_ZN7PointerIiEC2EPim, .-_ZN7PointerIiEC2EPim
	.weak	_ZN7PointerIiEC1EPim
	.set	_ZN7PointerIiEC1EPim,_ZN7PointerIiEC2EPim
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2261:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L35
	cmpl	$65535, -8(%rbp)
	jne	.L35
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L35:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2261:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z5debugPKcz, @function
_GLOBAL__sub_I__Z5debugPKcz:
.LFB2262:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2262:
	.size	_GLOBAL__sub_I__Z5debugPKcz, .-_GLOBAL__sub_I__Z5debugPKcz
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z5debugPKcz
	.hidden	__dso_handle
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
