	.file	"shortcircuiting.c"
	.section	.rodata
.LC0:
	.string	"\nHello"
.LC1:
	.string	"\nHi"
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
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$5, -16(%rbp)
	movl	$1, -12(%rbp)
	movl	$2, -8(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$0, -16(%rbp)
	je	.L2
	cmpl	$0, -12(%rbp)
	jne	.L3
.L2:
	cmpl	$0, -8(%rbp)
	je	.L4
	cmpl	$0, -4(%rbp)
	je	.L4
.L3:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L4:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
.L5:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
