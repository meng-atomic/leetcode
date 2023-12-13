	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$10, %edi
	callq	_malloc
	xorl	%ecx, %ecx
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rdi
	movl	%ecx, %esi
	movl	$10, %edx
	movl	%ecx, -28(%rbp)         ## 4-byte Spill
	callq	_memset
	movl	-28(%rbp), %eax         ## 4-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
