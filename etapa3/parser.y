%{
    #include <stdio.h>
    #include "hash.h"
    #include "ast.h"

    void yyerror(const char *s);  
    int getLineNumber(void); 
    int yylex(void); 

%}

%union 
{
    HASH_NODE *symbol;
    AST *ast;
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

%token OPERATOR_LTE       
%token OPERATOR_GTE       
%token OPERATOR_EQ       
%token OPERATOR_DIF   

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INTEGER      
%token<symbol> LIT_CHAR          
%token LIT_STRING   

%token TOKEN_ERROR        

%type<ast> declaration_function
%type<ast> declaration_function_body

%type<ast> command
%type<ast> command_block
%type<ast> command_list

%type<ast> attribution

%type<ast> expression


%left '<' '>' OPERATOR_LTE OPERATOR_GTE OPERATOR_EQ OPERATOR_DIF
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

declaration_function: KW_INT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body     //{ astPrint($6, 0); }
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

declaration_function_body: command      { $$ = astCreate(AST_DECLARATION_FUNCTION_BODY, 0, $1,0,0,0);  }
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

command: attribution                            { $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | flux_control                              //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | print                                     //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | return                                    //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | command_block                             { $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    |                                           { $$ = 0;}
    ;
  
command_block: '{' command_list '}'             { $$ = astCreate(AST_COMMAND_BLOCK, 0, $2,0,0,0); }
    ;

command_list:   command ';' command_list        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$3,0,0); }
//    | command ';'
//    | label
    | label command_list
//    | ';' command_list
//    | ';'
    |                                          { $$ = 0;}
    ;


attribution: TK_IDENTIFIER '=' expression       {  $$ = astCreate(AST_ATTRIBUITION, $1, $3,0,0,0); }
    | array_element '=' expression
    ;


expression: LIT_INTEGER                         { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | LIT_CHAR                                  { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | TK_IDENTIFIER                             { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | KW_READ                                   //{ $$ = 0; }
    | array_element
    | expression '+' expression                 { $$ = astCreate(AST_ADD, 0, $1,$3,0,0); }
    | expression '-' expression                 { $$ = astCreate(AST_SUB, 0, $1,$3,0,0); }
    | expression '*' expression                 { $$ = astCreate(AST_MULT, 0, $1,$3,0,0); }
    | expression '/' expression                 { $$ = astCreate(AST_DIV, 0, $1,$3,0,0); }
    
    | expression '<' expression                 { $$ = astCreate(AST_LT, 0, $1,$3,0,0); }
    | expression OPERATOR_LTE expression        { $$ = astCreate(AST_LTE, 0, $1,$3,0,0); }    
    | expression '>' expression                 { $$ = astCreate(AST_GT, 0, $1,$3,0,0); }    
    | expression OPERATOR_GTE expression        { $$ = astCreate(AST_GTE, 0, $1,$3,0,0); }
    | expression OPERATOR_EQ expression         { $$ = astCreate(AST_EQ, 0, $1,$3,0,0); }
    | expression OPERATOR_DIF expression        { $$ = astCreate(AST_DIF, 0, $1,$3,0,0); }
    
    | '(' expression ')'                        { $$ = $2; }
    | function_call
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