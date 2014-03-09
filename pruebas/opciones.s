	.file	"opciones.c"
	.section	.rodata
.LC0:
	.string	"in"
.LC1:
	.string	"out"
	.align 4
.LC2:
	.long	.LC0
	.long	1
	.long	0
	.long	1
	.long	.LC1
	.long	1
	.long	0
	.long	2
	.long	0
	.long	0
	.long	0
	.long	0
.LC3:
	.string	"i:o:"
	.align 32
.LC4:
	.string	"c:%c optind:%d opterr:%d optopt:%d optchar:%s\n"
.LC5:
	.string	"Siguiente argumento: %s %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$64, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	leal	-72(%ebp), %edi
	movl	$.LC2, %esi
	cld
	movl	$12, %eax
	movl	%eax, %ecx
	rep
	movsl
.L5:
	subl	$12, %esp
	pushl	$0
	leal	-72(%ebp), %eax
	pushl	%eax
	pushl	$.LC3
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	getopt_long
	addl	$32, %esp
	movl	%eax, -12(%ebp)
	cmpl	$-1, -12(%ebp)
	jne	.L7
	jmp	.L6
.L7:
	subl	$4, %esp
	pushl	optarg
	pushl	optopt
	pushl	opterr
	pushl	optind
	pushl	-12(%ebp)
	pushl	$.LC4
	pushl	stdout
	call	fprintf
	addl	$32, %esp
	movl	optind, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	subl	$12, %esp
	pushl	(%eax,%edx)
	call	atoi
	addl	$16, %esp
	pushl	%eax
	movl	optind, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	pushl	(%eax,%edx)
	pushl	$.LC5
	pushl	stdout
	call	fprintf
	addl	$16, %esp
	jmp	.L5
.L6:
	subl	$12, %esp
	pushl	$0
	call	exit
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
