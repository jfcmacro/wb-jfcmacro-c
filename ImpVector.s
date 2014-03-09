	.file	"ImpVector.c"
	.section	.rodata
.LC0:
	.string	"a[i] = %d i[a] = %d\n"
.LC1:
	.string	"*(a + i) = %d *(i + a) = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$1, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$4, -24(%rbp)
	movl	$5, -20(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %ecx
	movl	$.LC0, %eax
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	-32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movl	$.LC1, %eax
	movl	%ecx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	$3, %eax
	jbe	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.6.3 20120306 (Red Hat 4.6.3-2)"
	.section	.note.GNU-stack,"",@progbits
