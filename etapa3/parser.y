%{

    #include "hash.h"

    void yyerror(const char *s);  
    int getLineNumber(void);  

%}

%union 
{
    int value; 
    HASH_NODE *symbol;
}


%token KW_CHAR           
%token KW_INT            
%token KW_FLOAT  

%token KW_IF             
%token KW_THEN           
%token KW_ELSE           
%token KW_WHILE          
%token KW_GOTO           
%token KW_READ           
%token KW_PRINT          
%token KW_RETURN      

%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF   

%token TK_IDENTIFIER     

%token<value> LIT_INTEGER      
%token<value> LIT_CHAR          
%token LIT_STRING   

%token TOKEN_ERROR        

%type<value> expression


%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-' 
%left '*' '/'

%%


programa: declaration_list
    ;

declaration_list: declaration declaration_list
    | 
    ;

declaration: declaration_function 
    | declaration_global
    ;

// -----------------------------------
// -----------  Globals  -------------
// -----------------------------------

// tipo da variavel ou retorno de função
// nome
// resto

declaration_global: declaration_global_int 
    | declaration_global_char
    | declaration_global_float
    ;


declaration_global_int: KW_INT TK_IDENTIFIER ':' expression ';'
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'
    ;

declaration_global_char: KW_CHAR TK_IDENTIFIER ':' expression ';'
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'
    ;

declaration_global_float: KW_FLOAT TK_IDENTIFIER ':' LIT_INTEGER '/' LIT_INTEGER ';'
    | KW_FLOAT TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
    ;


array_val: LIT_INTEGER array_val
    | LIT_INTEGER 
    | LIT_CHAR array_val
    | LIT_CHAR 
    ;


// -----------------------------------
// ---------  Functions  -------------
// -----------------------------------

declaration_function: KW_INT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body
    | KW_CHAR TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body
    | KW_FLOAT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body
    ;

declaration_function_args_or_empty: declaration_function_args
    |
    ;

declaration_function_args: KW_INT TK_IDENTIFIER ',' declaration_function_args
    | KW_CHAR TK_IDENTIFIER ',' declaration_function_args
    | KW_FLOAT TK_IDENTIFIER ',' declaration_function_args    
    | KW_INT TK_IDENTIFIER
    | KW_CHAR TK_IDENTIFIER
    | KW_FLOAT TK_IDENTIFIER
    ;

declaration_function_body: command
    ;

function_call: TK_IDENTIFIER '(' function_args_or_empty ')'
    ;

function_args_or_empty: function_args
    | 
    ;

function_args: expression
    | expression ',' function_args
    ;

// -----------------------------------
// ----------  Commands  -------------
// -----------------------------------

command: attribution
    | flux_control
    | print
    | return
    | command_block
    |
    ;
  
command_block: '{' command_list '}'
    ;

command_list:   command ';' command_list
//    | command ';'
//    | label
    | label command_list
    | ';' command_list
//    | ';'
    | 
    ;


attribution: TK_IDENTIFIER '=' expression       { fprintf(stderr, "EXPRESSION parser int %d \n", $3); }
    | array_element '=' expression
    ;


expression: LIT_INTEGER                         { fprintf(stderr, "TAG parser int %d \n", $1); }
    | LIT_CHAR                                  { fprintf(stderr, "TAG parser char %d \n", $1); }
    | TK_IDENTIFIER                             { $$ = 0; }
    | KW_READ                                   { $$ = 0; }
//    | array_element
    | expression '+' expression                 { $$ = $1 + $3; }
    | expression '-' expression                 { $$ = $1 - $3; }
    | expression '*' expression                 { $$ = $1 * $3; }
    | expression '/' expression                 { $$ = $1 / $3; }
    | expression '<' expression                 { $$ = $1 < $3; }
    | expression '>' expression                 { $$ = $1 > $3; }
    | expression OPERATOR_LE expression
    | expression OPERATOR_GE expression
    | expression OPERATOR_EQ expression
    | expression OPERATOR_DIF expression
    | '(' expression ')'                        { $$ = $2; }
//    | function_call
    ; 

array_element: TK_IDENTIFIER '[' expression ']'
    ;

print:  KW_PRINT print_rest    
    ;

print_rest: LIT_STRING
    | LIT_STRING ',' print_rest
    | expression
    | expression ',' print_rest
    ;

return: KW_RETURN expression
    ;


// -----------------------------------
// --------  Flux Control  -----------
// -----------------------------------


flux_control: KW_IF expression KW_THEN command
    | KW_IF expression KW_THEN command KW_ELSE command
    | KW_WHILE expression command
    | go_to
    ;

label: TK_IDENTIFIER ':'
    ;

go_to: KW_GOTO TK_IDENTIFIER
    ;


%%

void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d.\n", s, getLineNumber());
    exit(3);
}