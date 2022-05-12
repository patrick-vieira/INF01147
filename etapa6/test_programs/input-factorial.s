	.data
__TMP_VAR_11: .string	"\n temp= "
__TMP_VAR_4: .long	0
_0: .long	0
_1: .long	1
__TMP_VAR_15: .string	"Enter the value to  calc: "
__TMP_VAR_20: .string	"\n Factorial of "
_n: .long	0
__TMP_VAR_3: .string	"\n ZERO: n = "
__TMP_VAR_19: .string	" is: "
__TMP_VAR_2: .string	" temp = "
__TMP_VAR_1: .long	0
_vum: .long	1
__TMP_VAR_21: .string	"nice!"
__TMP_VAR_12: .long	0
__TMP_VAR_0: .string	"\n Call n: "
__TMP_VAR_16: .long	0
_temp: .long	0
_input: .long	0
__TMP_VAR_22: .string	"\n"
__TMP_VAR_13: .string	"\n"
__TMP_VAR_17: .long	0
__TMP_VAR_9: .string	" n * temp = "
__TMP_VAR_8: .long	0
__TMP_VAR_10: .string	" n= "
__TMP_VAR_7: .long	0
__TMP_VAR_14: .string	"Factorial calc: "
_res: .long	0
__TMP_VAR_6: .long	0
__TMP_VAR_18: .long	0
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
	.globl	factorial
factorial:
	pushq	%rbp
	movq	%rsp, %rbp

	# TAC_DEC_FUNC_ARGS
    movl	$0, %edx

	movl	16(%rbp), %eax
	# movl	%eax, _n(%rip)
	movl	%eax, %r10d

# TAC_PRINT_STRING 
    leaq	__TMP_VAR_0(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    # movl	_n(%rip), %esi   # mov a to reg
    movl	%r10d, %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_EQ 
	# movl	_n(%rip), %edx
	movl	%r10d, %edx
	movl	_0(%rip), %eax
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


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_3(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    # movl	_n(%rip), %esi   # mov a to reg
    movl	%r10d, %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_2(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_temp(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT


## TAC_ENDFUN
	movl	_1(%rip), %eax #return
	popq	%rbp
	ret



# TAC_JMP
	jmp	__TMP_LABEL_1



# TAC_LABEL
    __TMP_LABEL_0:	# AUTO



# TAC_SUB 
    #movl	_n(%rip), %edx
    movl	%r10d, %edx
    movl	_1(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_4(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	__TMP_VAR_4(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	factorial
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_6(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_6(%rip), %eax
    movl	%eax, _temp(%rip)
    movl	$0, %eax




# TAC_ADD 
    movl	_n(%rip), %edx
    movl	_1(%rip), %eax
    addl	%edx, %eax
    movl	%eax, __TMP_VAR_7(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_7(%rip), %eax
    movl	%eax, _n(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_11(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_temp(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_10(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    # movl	_n(%rip), %esi   # mov a to reg
    movl	%r10d, %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_9(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_MULT 
    # movl	_n(%rip), %edx
    movl	%r10d, %edx
    movl	_temp(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_8(%rip)
    movl	$0, %eax



# TAC_PRINT_INT 
    movl	__TMP_VAR_8(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_MULT 
    movl	_n(%rip), %edx
    movl	_temp(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_12(%rip)
    movl	$0, %eax



## TAC_ENDFUN
	movl	__TMP_VAR_12(%rip), %eax #return
	popq	%rbp
	ret



# TAC_LABEL
    __TMP_LABEL_1:	# AUTO



## TAC_ENDFUN
	popq	%rbp
	ret



# TAC_BEGINFUN
	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_14(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_13(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_15(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_READ
	leaq	__TMP_VAR_16(%rip), %rsi
	leaq	read(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_16(%rip), %eax
    movl	%eax, _input(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	_input(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	factorial
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_18(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_18(%rip), %eax
    movl	%eax, _res(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_20(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_input(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_19(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_res(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_22(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_21(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



## TAC_ENDFUN
	popq	%rbp
	ret

