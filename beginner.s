	.file	"beginner.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
	.align 8
.LC1:
	.string	"failed to open file for reading\n"
.LC2:
	.string	","
.LC3:
	.string	"%d\t"
.LC4:
	.string	"%s\t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$8535274769651884388, %rax
	movq	%rax, -41(%rbp)
	movb	$0, -33(%rbp)
	leaq	-41(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -56(%rbp)
	cmpq	$0, -56(%rbp)
	jne	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$32, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
	call	fwrite
	movl	$1, %eax
	jmp	.L10
.L2:
	movq	$0, -64(%rbp)
	jmp	.L4
.L9:
	leaq	-32(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	strtok
	movq	%rax, -64(%rbp)
	movl	$0, -68(%rbp)
	jmp	.L5
.L8:
	cmpl	$0, -68(%rbp)
	je	.L6
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L7
.L6:
	movq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -68(%rbp)
.L7:
	movl	$.LC2, %esi
	movl	$0, %edi
	call	strtok
	movq	%rax, -64(%rbp)
.L5:
	cmpq	$0, -64(%rbp)
	jne	.L8
	movl	$10, %edi
	call	putchar
.L4:
	movq	-56(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movl	$20, %esi
	movq	%rax, %rdi
	call	fgets
	testq	%rax, %rax
	jne	.L9
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
.L10:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~16.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
