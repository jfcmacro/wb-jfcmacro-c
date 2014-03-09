	.file	"Procesos.c"
	.section	.rodata
.LC0:
	.string	"Error: %d\n"
.LC1:
	.string	"Hijo: %d\n"
.LC2:
	.string	"Hijo termino con codigo: %d\n"
.LC3:
	.string	"Se\361al del hijo: %d\n"
.LC4:
	.string	"Se\361al de parada: %d\n"
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
	call	fork
	movl	%eax, -4(%ebp)
	cmpl	$-1, -4(%ebp)
	jne	.L5
	subl	$4, %esp
	subl	$12, %esp
	call	__errno_location
	addl	$12, %esp
	pushl	(%eax)
	pushl	$.LC0
	pushl	stdout
	call	fprintf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$1
	call	exit
.L5:
	cmpl	$0, -4(%ebp)
	jne	.L6
	subl	$12, %esp
	pushl	$30
	call	sleep
	addl	$16, %esp
	subl	$12, %esp
	pushl	$1
	call	exit
.L6:
	subl	$4, %esp
	pushl	-4(%ebp)
	pushl	$.LC1
	pushl	stdout
	call	fprintf
	addl	$16, %esp
	subl	$12, %esp
	leal	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	pushl	-12(%ebp)
	call	wait
	addl	$16, %esp
	movl	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	andl	$127, %eax
	testl	%eax, %eax
	jne	.L8
	movl	-8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	andl	$65280, %eax
	sarl	$8, %eax
	subl	$4, %esp
	pushl	%eax
	pushl	$.LC2
	pushl	stdout
	call	fprintf
	addl	$16, %esp
	jmp	.L7
.L8:
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	$0, -20(%ebp)
	movzbl	-12(%ebp),%eax
	cmpl	$127, %eax
	je	.L11
	movl	-12(%ebp), %eax
	andl	$127, %eax
	testl	%eax, %eax
	je	.L11
	movl	$1, -20(%ebp)
.L11:
	cmpl	$0, -20(%ebp)
	je	.L10
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	andl	$127, %eax
	subl	$4, %esp
	pushl	%eax
	pushl	$.LC3
	pushl	stdout
	call	fprintf
	addl	$16, %esp
	jmp	.L7
.L10:
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	andl	$255, %eax
	cmpl	$127, %eax
	jne	.L7
	movl	-8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	andl	$65280, %eax
	sarl	$8, %eax
	subl	$4, %esp
	pushl	%eax
	pushl	$.LC4
	pushl	stdout
	call	fprintf
	addl	$16, %esp
.L7:
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
