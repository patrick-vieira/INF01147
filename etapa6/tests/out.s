	.data
_2: .long	2
_a: .long	10
_b: .long	11
_c: .long	111
_d: .long	222
_10: .long	10
_11: .long	11
_111: .long	111
_22: .long	22
_222: .long	222
__TMP_VAR_0: .long	0
__TMP_VAR_1: .long	0
__TMP_VAR_2: .long	0
__TMP_VAR_3: .long	0

 # PRINT
print_string_int:
	.string	"%d\n"
print_string:
	.string	"%s\n"


 #READ
read:
	.string	"%d"



# TAC_BEGINFUN
	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp



# TAC_PRINT_CONCAT printf("%d", var_name);
    movl	__TMP_VAR_0(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT printf("%d", var_name);
    movl	__TMP_VAR_0(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_EQ 
	movl	_a(%rip), %edx
	movl	_b(%rip), %eax
	cmpl	%eax, %edx 
	je	CMP_LBL_TEMP_0 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_1(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_1 		# e pula para o final do bloco

CMP_LBL_TEMP_0: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_1(%rip)

CMP_LBL_TEMP_1:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_1(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_0


# TAC_PRINT_CONCAT printf("%d", var_name);
    movl	__TMP_VAR_2(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT printf("%d", var_name);
    movl	__TMP_VAR_2(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_LABEL
    __TMP_LABEL_0:



# TAC_DIF 
	movl	_a(%rip), %edx
	movl	_b(%rip), %eax
	cmpl	%eax, %edx 
	jne	CMP_LBL_TEMP_2 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_3(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_3 		# e pula para o final do bloco

CMP_LBL_TEMP_2: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_3(%rip)

CMP_LBL_TEMP_3:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_3(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_1


# TAC_PRINT printf("%d", var_name);
    movl	_2(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_LABEL
    __TMP_LABEL_1:



## TAC_ENDFUN
	popq	%rbp
	ret

