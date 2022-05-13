	.data
__TMP_VAR_4: .string	"\n"
_0: .long	0
_1: .long	1
_2: .long	2
_a: .long	0
__TMP_VAR_3: .long	0
__TMP_VAR_2: .long	0
__TMP_VAR_1: .string	"char arr value: "
__TMP_VAR_0: .string	"\n"
__TMP_VAR_7: .long	0
_char_a: .long	'a'
_res: .long	0
__TMP_VAR_6: .long	0
__TMP_VAR_5: .string	"char arr value: "

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
	 .long 'a' 	# char__dash__arr[0]
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
	movl	%eax, _a(%rip)

# TAC_PRINT_STRING 
    leaq	__TMP_VAR_1(%rip), %rdi
    movl	$0, %eax
    call	printf@PLT
    movl	$0, %eax



# TAC_PRINT_CHAR 
    leaq	_a(%rip), %rdi
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
    leaq	__TMP_VAR_5(%rip), %rdi
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
 # LIT CHAR 
	movl	_char_a(%rip), %r10d
	pushq	%r10

	# TAC_TAC_FUN_CALL
	call	fun
	addq	$8, %rsp
	movl	%eax, __TMP_VAR_7(%rip) #move return to tempvar


# TAC_MOVE //ASSIGN 
    movl	__TMP_VAR_7(%rip), %eax
    movl	%eax, _res(%rip)
    movl	$0, %eax




## TAC_ENDFUN
	popq	%rbp
	ret

