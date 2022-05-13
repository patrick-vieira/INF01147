	.data
__TMP_VAR_4: .string	"\n"
_0: .long	0
_1: .long	1
_2: .long	2
__TMP_VAR_3: .long	0
_v: .long	0
_z: .long	0
__TMP_VAR_2: .long	0
_char__dash__x: .long	112
__TMP_VAR_1: .string	"char var value: "
_char_p: .long	'p'
__TMP_VAR_0: .string	"\n"
_113: .long	113
__TMP_VAR_9: .long	0
__TMP_VAR_8: .long	0
__TMP_VAR_7: .long	0
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




## TAC_ENDFUN
	popq	%rbp
	ret

