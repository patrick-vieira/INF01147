	.data
__TMP_VAR_11: .long	0
__TMP_VAR_4: .string	"\n"
_0: .long	0
_1: .long	1
_2: .long	2
_5: .long	5
__TMP_VAR_15: .string	"\n"
__TMP_VAR_3: .long	0
_v: .long	0
_z: .long	0
__TMP_VAR_2: .long	0
_char__dash__x: .long	112
__TMP_VAR_1: .string	"char var value: "
_char_p: .long	'p'
__TMP_VAR_12: .string	"\n"
__TMP_VAR_0: .string	"\n"
__TMP_VAR_16: .string	"ahoy: "
_113: .long	113
_10: .long	10
_12: .long	12
__TMP_VAR_13: .long	0
__TMP_VAR_17: .long	0
__TMP_VAR_9: .long	0
__TMP_VAR_8: .long	0
__TMP_VAR_10: .long	0
__TMP_VAR_7: .long	0
__TMP_VAR_14: .long	0
_res: .long	0
__TMP_VAR_6: .string	"char arr value: "
_char_c: .long	'c'
__TMP_VAR_5: .string	" - "

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



# TAC_ARRAY
_char__dash__arr:
	 .long 'r' 	# char__dash__arr[0]
	 .long 'b' 	# char__dash__arr[1]

# TAC_BEGINFUN
	.text
	.globl	fun
fun:
	pushq	%rbp
	movq	%rsp, %rbp

	# TAC_DEC_FUNC_ARGS
    movl	$0, %edx

	movl	16(%rbp), %eax
	movl	%eax, _v(%rip)
	movl	24(%rbp), %eax
	movl	%eax, _z(%rip)

# TAC_PRINT_STRING 
    leaq	__TMP_VAR_1(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_CHAR 
    leaq	_v(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_CHAR 
    leaq	_char_c(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_CHAR 
    leaq	_z(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_0(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


## TAC_ENDFUN
	movl	_10(%rip), %eax #return
	popq	%rbp
	ret



# TAC_BEGINFUN
	.text
	.globl	main
main:
	pushq	%rbp
	movq	%rsp, %rbp


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_6(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_ARRAY GET_ELEMENT
    movl	0+_char__dash__arr(%rip), %eax
    movl	%eax, __TMP_VAR_2(%rip)
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	__TMP_VAR_2(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_5(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_ARRAY GET_ELEMENT
    movl	4+_char__dash__arr(%rip), %eax
    movl	%eax, __TMP_VAR_3(%rip)
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	__TMP_VAR_3(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_4(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_TAC_FUN_CALL_ARGS

	movl	_113(%rip), %r10d
	pushq	%r10
 # VAR CHAR 
	movl	_char__dash__x(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	fun
	addq	$16, %rsp
	movl	%eax, __TMP_VAR_9(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_9(%rip), %eax
    movl	%eax, _res(%rip)
    movl	$0, %eax




# TAC_GT 
	movl	_res(%rip), %edx
	movl	_0(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_0 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_10(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_1 		# e pula para o final do bloco

CMP_LBL_TEMP_0: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_10(%rip)

CMP_LBL_TEMP_1:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_10(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_0


# TAC_MULT 
    movl	_res(%rip), %edx
    movl	_12(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_11(%rip)
    movl	$0, %eax



# TAC_PRINT_INT 
    movl	__TMP_VAR_11(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_12(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_LABEL
    __TMP_LABEL_0:	# AUTO



# TAC_LABEL
    __TMP_LABEL_1:	# AUTO



# TAC_MULT 
    movl	_res(%rip), %edx
    movl	_5(%rip), %eax
    imull	%edx, %eax
    movl	%eax, __TMP_VAR_13(%rip)
    movl	$0, %eax




# TAC_GT 
	movl	__TMP_VAR_13(%rip), %edx
	movl	_12(%rip), %eax
	cmpl	%eax, %edx 
	jg	CMP_LBL_TEMP_2 		# se condição verdadeira pula para setar 1
 	movl	$0, __TMP_VAR_14(%rip) 		# Se falsa seta 0 
	jmp	CMP_LBL_TEMP_3 		# e pula para o final do bloco

CMP_LBL_TEMP_2: 		 #se condição verdadeira seta 1
	movl	$1, __TMP_VAR_14(%rip)

CMP_LBL_TEMP_3:	#final do bloco



# TAC_JMPZ
	movl	__TMP_VAR_14(%rip), %edx
	movl	$0, %eax
	cmpl	%eax, %edx 	# Se condicional anterior for 0 pula o trecho a baixo
    jz __TMP_LABEL_2


# TAC_PRINT_STRING 
    leaq	__TMP_VAR_16(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax


# TAC_PRINT_INT 
    movl	_res(%rip), %esi   # mov a to reg
    #movl	%eax, %esi
    leaq	print_string_int(%rip), %rdi
	call	printf@PLT



# TAC_PRINT_STRING 
    leaq	__TMP_VAR_15(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_SUB 
    movl	_res(%rip), %edx
    movl	_1(%rip), %eax
    subl	%eax, %edx
    movl	%edx, %eax
    movl	%eax, __TMP_VAR_17(%rip)
    movl	$0, %eax




# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_17(%rip), %eax
    movl	%eax, _res(%rip)
    movl	$0, %eax




# TAC_JMP
	jmp	__TMP_LABEL_1



# TAC_LABEL
    __TMP_LABEL_2:	# AUTO


## TAC_ENDFUN
	movl	_1(%rip), %eax #return
	popq	%rbp
	ret

