	.file	"switchcases.c"
	.section	.rodata
.LC0:
	.string	"\number 1"
.LC1:
	.string	"\number 2"
.LC2:
	.string	"\number 3"
.LC3:
	.string	"\number 4"
.LC4:
	.string	"\ndefault case"
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
	movl	$3, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$2, %eax
	jg	.L4
	cmpl	$1, %eax
	je	.L5
	jmp	.L2
.L4:
	cmpl	$3, %eax
	je	.L6
	cmpl	$4, %eax
	je	.L7
	jmp	.L2
.L5:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L8
.L3:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L8
.L6:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L8
.L7:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L8
.L2:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L8:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
