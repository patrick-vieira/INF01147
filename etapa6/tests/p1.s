
# DEC de variaveis  ou constantes
a:
	.long	777


b:
	.long	666



print_string_int:
	.string	"%d\n"

print_string:
	.string	"%s\n"


# TAC_BEGINFUN
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp

# TAC_PRINT printf("%d", 88);
	movl	$88, %esi
	leaq	print_string_int(%rip), %rdi
	call	printf@PLT

# TAC_PRINT printf("%d", a);
    movl	b(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT


## TAC_ENDFUN
	popq	%rbp
	ret





