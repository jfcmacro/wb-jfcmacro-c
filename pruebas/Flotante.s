	.file	"Flotante.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
.LC1:
	.string	"%f\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$2139116372, -4(%ebp)
	movl	$2139095040, -8(%ebp)
	leal	-4(%ebp), %eax
	movl	%eax, -12(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	flds	(%eax)
	fadds	(%edx)
	fstps	-20(%ebp)
	subl	$8, %esp
	pushl	-4(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	movl	-12(%ebp), %eax
	flds	(%eax)
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	subl	$8, %esp
	pushl	-8(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	movl	-16(%ebp), %eax
	flds	(%eax)
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	subl	$4, %esp
	flds	-20(%ebp)
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
