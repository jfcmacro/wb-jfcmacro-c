	.file	"prueba.c"
	.section	.rodata
.LC0:
	.string	"0x"
.LC1:
	.string	"%02x"
.LC2:
	.string	"\n"
	.text
.globl imprimirflotante
	.type	imprimirflotante, @function
imprimirflotante:
	# basic block 0
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, -8(%ebp)
.L2:
	# basic block 1
	cmpl	$3, -8(%ebp)
	jbe	.L5
	# basic block 2
	jmp	.L3
.L5:
	# basic block 3
	subl	$8, %esp
	movl	-8(%ebp), %eax
	addl	-4(%ebp), %eax
	movzbl	(%eax), %eax
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	leal	-8(%ebp), %eax
	incl	(%eax)
	jmp	.L2
.L3:
	# basic block 5
	subl	$12, %esp
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	imprimirflotante, .-imprimirflotante
.globl vector
	.data
	.align 4
	.type	vector, @object
	.size	vector, 24
vector:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.text
.globl main
	.type	main, @function
main:
	# basic block 0
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$0x0, %eax
	movl	%eax, -4(%ebp)
	movl	$0x3f800000, %eax
	movl	%eax, -8(%ebp)
	subl	$12, %esp
	pushl	-4(%ebp)
	call	imprimirflotante
	addl	$16, %esp
	subl	$12, %esp
	pushl	-8(%ebp)
	call	imprimirflotante
	addl	$16, %esp
	subl	$12, %esp
	flds	-4(%ebp)
	fadds	-8(%ebp)
	leal	-4(%esp), %esp
	fstps	(%esp)
	call	imprimirflotante
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
