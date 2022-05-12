	.data
_first__dash__char: .byte	97
_fa: 	.long	2
	.long	3
__TMP_VAR_11: .string	"tipos de dados e chamadas com multiplos argumentos [int, char, float] \n"
__TMP_VAR_4: .string	", "
_0: .long	0
_1: .long	1
_2: .long	2
_3: .long	3
_5: .long	5
_6: .long	6
__TMP_VAR_15: .long	0
_n: .long	0
__TMP_VAR_3: .long	0
_fb: 	.long	5
	.long	6
__TMP_VAR_19: .long	0
_count: .long	0
__TMP_VAR_2: .string	"As proximas "
_repeat: .long	0
__TMP_VAR_1: .string	" letras do alfabeto depois de ["
__TMP_VAR_12: .string	"Digite o numero de letras: "
__TMP_VAR_0: .string	"] são: \n"
__TMP_VAR_16: .long	0
_in__dash__repeat: .long	0
__TMP_VAR_13: .string	"\n"
__TMP_VAR_17: .long	0
__TMP_VAR_9: .string	"\n\n O quarto argumento é um float com valor: "
__TMP_VAR_8: .string	"\n"
_result: .long	0
__TMP_VAR_10: .string	"Teste 4:"
__TMP_VAR_7: .string	"\n\n O terceiro argumento é um float com valor: "
__TMP_VAR_14: .long	0
_argsfb: 	.long	0
	.long	0
_caracter: .byte	114
__TMP_VAR_6: .long	0
__TMP_VAR_18: .long	0
_argsfa: 	.long	0
	.long	0
__TMP_VAR_5: .long	0

 # PRINT
print_string_int:
	.string	"%d"

print_string_float:
	.string	"%d/%d"

print_string_char:
	.string	"%c"
print_string:
	.string	"%s"


 #READ
read:
	.string	"%d"



# TAC_BEGINFUN
	.text
	.globl	repeatchar
repeatchar:
	pushq	%rbp
	movq	%rsp, %rbp

	# TAC_DEC_FUNC_ARGS
    movl	$0, %edx

	movl	16(%rbp), %eax
	movl	%eax, _repeat(%rip)
	movl	24(%rbp), %eax
	movl	%eax, _caracter(%rip)
	movl	32(%rbp), %eax
	movl	40(%rbp), %edx
	movl	%eax, _argsfa(%rip)
	movl	%edx, 4+_argsfa(%rip)
	movl	48(%rbp), %eax
	movl	56(%rbp), %edx
	movl	%eax, _argsfb(%rip)
	movl	%edx, 4+_argsfb(%rip)

# TAC_PRINT_STRING 
    leaq	__TMP_VAR_2(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_repeat(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_1(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_CHAR 
    movzbl	_caracter(%rip), %eax   # mov a to reg
    movsbl	%al, %eax
    movl	%eax, %esi
    leaq	print_string_char(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_0(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_LABEL
    __TMP_LABEL_0:	# AUTO



# TAC_LT 
	movl	_count(%rip), %edx
	movl	_repeat(%rip), %eax
	cmpl	%eax, %edx 
	jl	CMP_LBL_TEMP_0 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_3(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_1 		# e pula para o final do bloco

CMP_LBL_TEMP_0: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_3(%rip)

CMP_LBL_TEMP_1:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_3(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_1

# TAC_PRINT_CHAR 
    movzbl	_caracter(%rip), %eax   # mov a to reg
    movsbl	%al, %eax
    movl	%eax, %esi
    leaq	print_string_char(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_4(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_ADD 
    movl	_count(%rip), %edx
    movl	_1(%rip), %eax
    addl	%edx, %eax
    movl	%eax, __TMP_VAR_5(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_5(%rip), %eax
    movl	%eax, _count(%rip)
    movl	$0, %eax




# TAC_ADD 
    movl	_caracter(%rip), %edx
    movl	_1(%rip), %eax
    addl	%edx, %eax
    movl	%eax, __TMP_VAR_6(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_6(%rip), %eax
    movl	%eax, _caracter(%rip)
    movl	$0, %eax




# TAC_JMP
	jmp	__TMP_LABEL_0



# TAC_LABEL
    __TMP_LABEL_1:	# AUTO



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_7(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_FLOAT 
    movl	4+_argsfa(%rip), %edx   # mov a to reg
    movl	_argsfa(%rip), %eax   # mov a to reg
    movl	%eax, %esi
    leaq	print_string_float(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_9(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_FLOAT 
    movl	4+_argsfb(%rip), %edx   # mov a to reg
    movl	_argsfb(%rip), %eax   # mov a to reg
    movl	%eax, %esi
    leaq	print_string_float(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_8(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


## TAC_ENDFUN
	movl	_result(%rip), %eax #return
	popq	%rbp
	ret



# TAC_BEGINFUN
	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_10(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_11(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_13(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_12(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_READ
	leaq	__TMP_VAR_14(%rip), %rsi
	leaq	read(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_14(%rip), %eax
    movl	%eax, _in__dash__repeat(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	4+_fb(%rip), %r10d
	pushq	%r10
	movl	_fb(%rip), %r10d
	pushq	%r10

	movl	4+_fa(%rip), %r10d
	pushq	%r10
	movl	_fa(%rip), %r10d
	pushq	%r10

	movl	_first__dash__char(%rip), %r10d
	pushq	%r10

	movl	_in__dash__repeat(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	repeatchar
	addq	$48, %rsp
	movl	%eax, __TMP_VAR_19(%rip) #move return to tempvar

## TAC_ENDFUN
	movl	__TMP_VAR_19(%rip), %eax #return
	popq	%rbp
	ret

