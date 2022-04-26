	.file	"t1.c"
	.text
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	2
	.globl	c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	1111
	.globl	f1
	.align 4
	.type	f1, @object
	.size	f1, 4
f1:
	.long	1
	.globl	f2
	.align 4
	.type	f2, @object
	.size	f2, 4
f2:
	.long	2
	.globl	f3
	.align 4
	.type	f3, @object
	.size	f3, 4
f3:
	.long	3
	.globl	f4
	.align 4
	.type	f4, @object
	.size	f4, 4
f4:
	.long	4
	.globl	f5
	.align 4
	.type	f5, @object
	.size	f5, 4
f5:
	.long	5
	.globl	f6
	.align 4
	.type	f6, @object
	.size	f6, 4
f6:
	.long	6
	.globl	f7
	.align 4
	.type	f7, @object
	.size	f7, 4
f7:
	.long	7
	.globl	f8
	.align 4
	.type	f8, @object
	.size	f8, 4
f8:
	.long	8
	.globl	f9
	.align 4
	.type	f9, @object
	.size	f9, 4
f9:
	.long	9
	.globl	f10
	.align 4
	.type	f10, @object
	.size	f10, 4
f10:
	.long	10
	.globl	d
	.align 8
	.type	d, @object
	.size	d, 12
d:
	.long	1111
	.long	2222
	.long	3333
	.text
	.globl	fn
	.type	fn, @function
fn:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	#movl	%edi, -4(%rbp)
	#movl	%esi, -8(%rbp)

	subq	$8, %rsp
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addq	$16, %rsp

	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fn, .-fn
	.section	.rodata
.LC0:
	.string	"%d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	f2(%rip), %edi
	movl	f1(%rip), %esi

	movl	%esi, -4(%rbp)
    movl	%edi, -8(%rbp)

	call	fn
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
