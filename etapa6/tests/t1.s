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
	.globl	ch
	.type	ch, @object
	.size	ch, 1
ch:
	.byte	97
	.globl	d
	.align 4
	.type	d, @object
	.size	d, 4
d:
	.long	1075000115
	.globl	e
	.align 4
	.type	e, @object
	.size	e, 4
e:
	.long	1075419546
	.globl	f
	.align 4
	.type	f, @object
	.size	f, 4
f:
	.long	1079613850
	.globl	g
	.align 4
	.type	g, @object
	.size	g, 4
g:
	.long	1079613850
	.globl	h
	.align 4
	.type	h, @object
	.size	h, 4
h:
	.long	1079655793
	.text
	.globl	fn2
	.type	fn2, @function
fn2:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fn2, .-fn2
	.comm	fat,4,4
	.comm	n,4,4
	.section	.rodata
.LC0:
	.string	"\n%d/%d"
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
	movl	b(%rip), %edx
	movl	a(%rip), %eax
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
