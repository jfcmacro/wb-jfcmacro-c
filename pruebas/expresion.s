	.file	"expresion.c"
	.section	.rodata
.LC0:
	.string	"a= %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$2, -4(%ebp)
	movl	-4(%ebp), %edx
	leal	-4(%ebp), %eax
	addl	%edx, (%eax)
	leal	-4(%ebp), %eax
	incl	(%eax)
	subl	$8, %esp
	pushl	-4(%ebp)
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.3.2 20031022 (Red Hat Linux 3.3.2-1)"
