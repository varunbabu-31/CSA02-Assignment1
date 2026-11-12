	.file	"task_8.c"
	.text
	.type	add_fixed_charge, @function
add_fixed_charge:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$5000, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add_fixed_charge, .-add_fixed_charge
	.section	.rodata
.LC0:
	.string	"Energy charge: Rs %d.%02d\n"
.LC1:
	.string	"Total bill: Rs %d.%02d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$11250, -4(%rbp)
	movl	-4(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1374389535, %rax, %rax
	shrq	$32, %rax
	sarl	$5, %eax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	imull	$100, %eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	-4(%rbp), %edx
	movslq	%edx, %rcx
	imulq	$1374389535, %rcx, %rcx
	shrq	$32, %rcx
	sarl	$5, %ecx
	sarl	$31, %edx
	subl	%edx, %ecx
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	add_fixed_charge
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1374389535, %rax, %rax
	shrq	$32, %rax
	sarl	$5, %eax
	movl	%edx, %ecx
	sarl	$31, %ecx
	subl	%ecx, %eax
	imull	$100, %eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	-8(%rbp), %edx
	movslq	%edx, %rcx
	imulq	$1374389535, %rcx, %rcx
	shrq	$32, %rcx
	sarl	$5, %ecx
	sarl	$31, %edx
	subl	%edx, %ecx
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
