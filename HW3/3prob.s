	.file	"3prob.c"
	.text
	.globl	float_to_string
	.type	float_to_string, @function
float_to_string:
.LFB40:
	.cfi_startproc
	endbr64
	movd	%xmm0, %esi
	movl	$0, %ecx
	jmp	.L2
.L5:
	movl	$48, %edx
.L3:
	movl	$31, %eax
	subl	%ecx, %eax
	cltq
	movb	%dl, (%rdi,%rax)
	addl	$1, %ecx
.L2:
	cmpl	$31, %ecx
	jg	.L6
	movl	%esi, %eax
	shrl	%cl, %eax
	testb	$1, %al
	je	.L5
	movl	$49, %edx
	jmp	.L3
.L6:
	ret
	.cfi_endproc
.LFE40:
	.size	float_to_string, .-float_to_string
	.globl	print_float
	.type	print_float, @function
print_float:
.LFB41:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	movl	$0, %ebx
	jmp	.L8
.L9:
	addl	$1, %ebx
.L8:
	cmpl	$31, %ebx
	jg	.L12
	movslq	%ebx, %rax
	movsbl	0(%rbp,%rax), %edi
	call	putchar@PLT
	testl	%ebx, %ebx
	sete	%al
	cmpl	$8, %ebx
	sete	%dl
	orb	%dl, %al
	je	.L9
	movl	$32, %edi
	call	putchar@PLT
	jmp	.L9
.L12:
	movl	$10, %edi
	call	putchar@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	print_float, .-print_float
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"f=%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$64, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movq	8(%rsi), %rdi
	movl	$0, %esi
	call	strtod@PLT
	pxor	%xmm1, %xmm1
	cvtsd2ss	%xmm0, %xmm1
	movss	%xmm1, 12(%rsp)
	pxor	%xmm0, %xmm0
	cvtss2sd	%xmm1, %xmm0
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	leaq	16(%rsp), %rbx
	movl	$32, %esi
	movq	%rbx, %rdi
	movss	12(%rsp), %xmm0
	call	float_to_string
	movl	$32, %esi
	movq	%rbx, %rdi
	movl	$0, %eax
	call	print_float
	movq	56(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L16
	movl	$0, %eax
	addq	$64, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L16:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
