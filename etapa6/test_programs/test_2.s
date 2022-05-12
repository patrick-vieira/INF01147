	.data
__TMP_VAR_11: .string	"\n"
__TMP_VAR_4: .long	0
__TMP_VAR_25: .string	"º numero de fibonacci, que é "
_0: .long	0
_1: .long	1
__TMP_VAR_15: .long	0
_a: .long	0
_b: .long	1
__TMP_VAR_20: .string	"\nO valor de "
_n: .long	0
__TMP_VAR_3: .long	0
__TMP_VAR_19: .string	"! é "
_input__dash__one: .long	0
__TMP_VAR_2: .long	0
__TMP_VAR_26: .long	0
__TMP_VAR_1: .long	0
_argsa: .long	0
__TMP_VAR_21: .long	0
__TMP_VAR_12: .long	0
__TMP_VAR_0: .long	0
_result__dash__fac: .long	0
__TMP_VAR_16: .long	0
__TMP_VAR_27: .long	0
__TMP_VAR_30: .long	0
__TMP_VAR_22: .string	" que é maior do que o "
__TMP_VAR_31: .string	"º numero de fibonacci.\n"
__TMP_VAR_13: .string	"Enter the second value: "
__TMP_VAR_28: .long	0
__TMP_VAR_17: .long	0
__TMP_VAR_9: .string	"Calculo fatorial e fubinacci, [read, while, if, function call] \n"
__TMP_VAR_32: .string	"x maior que o "
__TMP_VAR_23: .string	" que é menor do que o "
_input__dash__two: .long	0
__TMP_VAR_8: .string	"Teste 1:"
_result: .long	0
__TMP_VAR_10: .string	"Enter the first value: "
__TMP_VAR_33: .string	" é, pelo menos, "
_argsb: .long	0
__TMP_VAR_29: .long	0
__TMP_VAR_7: .long	0
_result__dash__fib: .long	0
__TMP_VAR_14: .long	0
__TMP_VAR_24: .string	"\n"
__TMP_VAR_6: .long	0
__TMP_VAR_18: .long	0
__TMP_VAR_34: .string	"\nO fatorial de "
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
	.globl	fatorial
fatorial:
	pushq	%rbp
	movq	%rsp, %rbp

	# TAC_DEC_FUNC_ARGS
    movl	$0, %edx

	movl	16(%rbp), %eax
	movl	%eax, _argsa(%rip)

# TAC_MOVE //ASSIGN 
    movl	_argsa(%rip), %eax
    movl	%eax, _n(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	_1(%rip), %eax
    movl	%eax, _result(%rip)
    movl	$0, %eax




# TAC_LABEL
    __TMP_LABEL_0:	# AUTO



# TAC_GT 
	movl	_n(%rip), %edx
	movl	_1(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_0 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_0(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_1 		# e pula para o final do bloco

CMP_LBL_TEMP_0: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_0(%rip)

CMP_LBL_TEMP_1:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_0(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_1


# TAC_MULT 
    movl	_result(%rip), %edx
    movl	_n(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_1(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_1(%rip), %eax
    movl	%eax, _result(%rip)
    movl	$0, %eax




# TAC_SUB 
    movl	_n(%rip), %edx
    movl	_1(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_2(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_2(%rip), %eax
    movl	%eax, _n(%rip)
    movl	$0, %eax




# TAC_JMP
	jmp	__TMP_LABEL_0



# TAC_LABEL
    __TMP_LABEL_1:	# AUTO


## TAC_ENDFUN
	movl	_result(%rip), %eax #return
	popq	%rbp
	ret



# TAC_BEGINFUN
	.text
	.globl	fibonacci
fibonacci:
	pushq	%rbp
	movq	%rsp, %rbp

	# TAC_DEC_FUNC_ARGS
    movl	$0, %edx

	movl	16(%rbp), %eax
	movl	%eax, _argsb(%rip)

# TAC_MOVE //ASSIGN 
    movl	_argsb(%rip), %eax
    movl	%eax, _n(%rip)
    movl	$0, %eax




# TAC_EQ 
	movl	_n(%rip), %edx
	movl	_0(%rip), %eax
	cmpl	%eax, %edx 
	je	CMP_LBL_TEMP_2 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_3(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_3 		# e pula para o final do bloco

CMP_LBL_TEMP_2: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_3(%rip)

CMP_LBL_TEMP_3:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_3(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_2

## TAC_ENDFUN
	movl	_0(%rip), %eax #return
	popq	%rbp
	ret



# TAC_LABEL
    __TMP_LABEL_2:	# AUTO



# TAC_EQ 
	movl	_n(%rip), %edx
	movl	_1(%rip), %eax
	cmpl	%eax, %edx 
	je	CMP_LBL_TEMP_4 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_4(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_5 		# e pula para o final do bloco

CMP_LBL_TEMP_4: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_4(%rip)

CMP_LBL_TEMP_5:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_4(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_3

## TAC_ENDFUN
	movl	_1(%rip), %eax #return
	popq	%rbp
	ret



# TAC_LABEL
    __TMP_LABEL_3:	# AUTO



# TAC_MOVE //ASSIGN 
    movl	_1(%rip), %eax
    movl	%eax, _result(%rip)
    movl	$0, %eax




# TAC_LABEL
    __TMP_LABEL_4:	# AUTO



# TAC_GT 
	movl	_n(%rip), %edx
	movl	_1(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_6 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_5(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_7 		# e pula para o final do bloco

CMP_LBL_TEMP_6: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_5(%rip)

CMP_LBL_TEMP_7:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_5(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_5


# TAC_ADD 
    movl	_a(%rip), %edx
    movl	_b(%rip), %eax
    addl	%edx, %eax
    movl	%eax, __TMP_VAR_6(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_6(%rip), %eax
    movl	%eax, _result(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	_b(%rip), %eax
    movl	%eax, _a(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	_result(%rip), %eax
    movl	%eax, _b(%rip)
    movl	$0, %eax




# TAC_SUB 
    movl	_n(%rip), %edx
    movl	_1(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_7(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_7(%rip), %eax
    movl	%eax, _n(%rip)
    movl	$0, %eax




# TAC_JMP
	jmp	__TMP_LABEL_4



# TAC_LABEL
    __TMP_LABEL_5:	# AUTO


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
    leaq	__TMP_VAR_8(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_9(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_11(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_10(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_READ
	leaq	__TMP_VAR_12(%rip), %rsi
	leaq	read(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_12(%rip), %eax
    movl	%eax, _input__dash__one(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_13(%rip), %rdi
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
    movl	%eax, _input__dash__two(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	_input__dash__one(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	fatorial
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_16(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_16(%rip), %eax
    movl	%eax, _result__dash__fac(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	_input__dash__two(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	fibonacci
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_18(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_18(%rip), %eax
    movl	%eax, _result__dash__fib(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_20(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_input__dash__one(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_19(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_result__dash__fac(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_GT 
	movl	_result__dash__fac(%rip), %edx
	movl	_result__dash__fib(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_8 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_21(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_9 		# e pula para o final do bloco

CMP_LBL_TEMP_8: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_21(%rip)

CMP_LBL_TEMP_9:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_21(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_6


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_22(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_JMP
	jmp	__TMP_LABEL_7



# TAC_LABEL
    __TMP_LABEL_6:	# AUTO



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_23(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_LABEL
    __TMP_LABEL_7:	# AUTO


# TAC_PRINT_INT 
    movl	_input__dash__two(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_25(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_result__dash__fib(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_24(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_SUB 
    movl	_result__dash__fac(%rip), %edx
    movl	_result__dash__fib(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_26(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_26(%rip), %eax
    movl	%eax, _a(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	_0(%rip), %eax
    movl	%eax, _b(%rip)
    movl	$0, %eax




# TAC_LABEL
    __TMP_LABEL_8:	# AUTO



# TAC_GT 
	movl	_a(%rip), %edx
	movl	_0(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_10 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_27(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_11 		# e pula para o final do bloco

CMP_LBL_TEMP_10: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_27(%rip)

CMP_LBL_TEMP_11:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_27(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_9


# TAC_ADD 
    movl	_b(%rip), %edx
    movl	_1(%rip), %eax
    addl	%edx, %eax
    movl	%eax, __TMP_VAR_28(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_28(%rip), %eax
    movl	%eax, _b(%rip)
    movl	$0, %eax




# TAC_SUB 
    movl	_a(%rip), %edx
    movl	_result__dash__fib(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_29(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_29(%rip), %eax
    movl	%eax, _a(%rip)
    movl	$0, %eax




# TAC_JMP
	jmp	__TMP_LABEL_8



# TAC_LABEL
    __TMP_LABEL_9:	# AUTO



# TAC_LT 
	movl	_0(%rip), %edx
	movl	_b(%rip), %eax
	cmpl	%eax, %edx 
	jl	CMP_LBL_TEMP_12 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_30(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_13 		# e pula para o final do bloco

CMP_LBL_TEMP_12: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_30(%rip)

CMP_LBL_TEMP_13:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_30(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_10


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_34(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_input__dash__one(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_33(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_b(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_32(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_input__dash__two(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_31(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_LABEL
    __TMP_LABEL_10:	# AUTO



## TAC_ENDFUN
	popq	%rbp
	ret

