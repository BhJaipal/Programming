	.text
	.globl read
	.type read, @function

	.globl write
	.type write, @function

	.globl exit
	.type exit, @function

	.globl mmap
	.type mmap, @function

	.globl munmap
	.type munmap, @function

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
	mov $60, %rax
	syscall
	ret

mmap:
	# edi has alloc size
	# esi has memory location
	# mov memory location to %rdi
	# mov size to %rsi
	mov $9, %rax # mmap for memory alloc
	mov $3, %rdx # read & write memory
	mov $0x22, %rcx
	mov $0, %r9d
	mov $0, %r8d
	syscall
	ret

munmap:
	mov $0xb, %rax # #munmap for memory free
	syscall
	ret
