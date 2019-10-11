	.file	"test_efficence.c"
	.text
	.section	.rodata
.LC0:
	.string	"1234567890" //字符串都是同样的一个
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp //把%rbp的数据压入stack,因为要保存rbp的数据
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp //把rsp的值传递给rbp,这样形成main帧
	.cfi_def_cfa_register 6
	subq	$64, %rsp //申请64字节给rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$1, -33(%rbp)
	movabsq	$4050765991979987505, %rax
	movq	%rax, -19(%rbp)
	movw	$12345, -11(%rbp)
	movb	$0, -9(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -32(%rbp)
	movzbl	-18(%rbp), %eax
	movb	%al, -33(%rbp)
	movq	-32(%rbp), %rax
	movzbl	1(%rax), %eax
	movb	%al, -33(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
