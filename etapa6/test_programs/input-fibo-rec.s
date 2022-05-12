	.data
__TMP_VAR_11: .long	0
__TMP_VAR_4: .long	0
_0: .long	0
_1: .long	1
__TMP_VAR_15: .string	"\nFactorial of "
_n: .long	0
__TMP_VAR_3: .long	0
__TMP_VAR_2: .long	0
__TMP_VAR_1: .long	0
__TMP_VAR_12: .long	0
__TMP_VAR_0: .string	"\n n = "
_temp_result: .long	0
__TMP_VAR_16: .string	"nice!"
_input: .long	0
__TMP_VAR_13: .long	0
__TMP_VAR_17: .string	"\n"
__TMP_VAR_9: .string	"Factorial calc: "
__TMP_VAR_8: .string	"\n"
__TMP_VAR_10: .string	"Enter the value to  calc: "
__TMP_VAR_7: .string	"\n temp res: "
__TMP_VAR_14: .string	" is: "
_res: .long	0
__TMP_VAR_6: .string	" - n value: "
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


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_0(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	16(%rbp), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_EQ 
	movl	16(%rbp), %edx
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


# TAC_MOVE //ASSIGN 
    movl	_1(%rip), %eax
    movl	%eax, 16(%rbp)
    movl	$0, %eax



## TAC_ENDFUN
	movl	16(%rbp), %eax #return
	popq	%rbp
	ret



# TAC_JMP
	jmp	__TMP_LABEL_1



# TAC_LABEL
    __TMP_LABEL_0:	# AUTO



# TAC_SUB 
    movl	16(%rbp), %edx
    movl	_1(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_2(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	__TMP_VAR_2(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	factorial
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_4(%rip) #move return to tempvar


# TAC_MULT 
    movl	16(%rbp), %edx
    movl	__TMP_VAR_4(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_5(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_5(%rip), %eax
    movl	%eax, _temp_result(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_7(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_temp_result(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_6(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    # movl	_n(%rip), %esi   # desse modo
    movl	16(%rbp), %esi   # para esse modo
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT


## TAC_ENDFUN
	movl	_temp_result(%rip), %eax #return
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
    leaq	__TMP_VAR_9(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_8(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_10(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_READ
	leaq	__TMP_VAR_11(%rip), %rsi
	leaq	read(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_11(%rip), %eax
    movl	%eax, _input(%rip)
    movl	$0, %eax




# TAC_TAC_FUN_CALL_ARGS

	movl	_input(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	factorial
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_13(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_13(%rip), %eax
    movl	%eax, _res(%rip)
    movl	$0, %eax




# TAC_PRINT_STRING 
    leaq	__TMP_VAR_15(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_input(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_14(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_res(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_17(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_16(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



## TAC_ENDFUN
	popq	%rbp
	ret

