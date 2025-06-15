	.file	"swap_min_and_max_elements.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -32(%rbp)
	movl	$2, -28(%rbp)
	movl	$-3, -24(%rbp)
	movl	$-4, -20(%rbp)
	movl	$1, -16(%rbp)
	movl	$5, -36(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -56(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	jmp	.L2
.L5:
	movl	-44(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	cmpl	%eax, -60(%rbp)
	jle	.L3
	movl	-44(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, -60(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, -52(%rbp)
.L3:
	movl	-44(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	cmpl	%eax, -56(%rbp)
	jge	.L4
	movl	-44(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, -56(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, -48(%rbp)
.L4:
	addl	$1, -44(%rbp)
.L2:
	movl	-44(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L5
	movl	-48(%rbp), %eax
	cltq
	movl	-60(%rbp), %edx
	movl	%edx, -32(%rbp,%rax,4)
	movl	-52(%rbp), %eax
	cltq
	movl	-56(%rbp), %edx
	movl	%edx, -32(%rbp,%rax,4)
	movl	$0, -40(%rbp)
	jmp	.L6
.L7:
	movl	-40(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	leaq	.LC0(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -40(%rbp)
.L6:
	movl	-40(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.1.1 20250425"
	.section	.note.GNU-stack,"",@progbits
