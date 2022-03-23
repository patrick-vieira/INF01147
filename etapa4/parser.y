%{
    #include <stdio.h>
    #include "hash.h"
    #include "ast.h"

    void yyerror(const char *s);  
    int getLineNumber(void); 
    AST* getRootNode(void); 
    
    int yylex(void); 

    AST *rootNode;

%}

%union 
{
    HASH_NODE *symbol;
    AST *ast;
}

%token<symbol> SYMBOL_VARIABLE     
%token<symbol> SYMBOL_FUNCTION     
%token<symbol> SYMBOL_VECTOR     


%token<symbol> KW_CHAR           
%token<symbol> KW_INT
%token<symbol> KW_FLOAT

%token KW_IF             
%token KW_THEN           
%token KW_ELSE           
%token KW_WHILE          
%token KW_GOTO           
%token KW_READ           
%token KW_PRINT          
%token KW_RETURN      

%token<symbol> OPERATOR_ADD   
%token<symbol> OPERATOR_SUB    
%token<symbol> OPERATOR_MULT  
%token<symbol> OPERATOR_DIV    

%token<symbol> OPERATOR_LTE       
%token<symbol> OPERATOR_LT       
%token<symbol> OPERATOR_GTE       
%token<symbol> OPERATOR_GT
%token<symbol> OPERATOR_EQ       
%token<symbol> OPERATOR_DIF   

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INTEGER      
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING   

%token TOKEN_ERROR        

%type<ast> program

%type<ast> declaration_list
%type<ast> declaration
%type<ast> return

%type<ast> print
%type<ast> print_rest

%type<ast> declaration_global
%type<ast> declaration_global_int
%type<ast> declaration_global_char
%type<ast> declaration_global_float

%type<ast> array_val
%type<ast> array_element


%type<ast> declaration_function
%type<ast> declaration_function_args
%type<ast> declaration_function_args_or_empty
%type<ast> declaration_function_body

%type<ast> function_call
%type<ast> function_call_args_or_empty
%type<ast> function_call_args

%type<ast> command
%type<ast> command_block
%type<ast> command_list

%type<ast> label
%type<ast> flux_control
%type<ast> go_to

%type<ast> attribution

%type<ast> expression


%left OPERATOR_LTE OPERATOR_LT OPERATOR_GTE OPERATOR_GT OPERATOR_EQ OPERATOR_DIF
%left OPERATOR_ADD OPERATOR_SUB
%left OPERATOR_MULT OPERATOR_DIV

%%


program: declaration_list              { $$ = astCreate(AST_PROGRAM, 0, $1,0,0,0); rootNode = $$; }
    ;

declaration_list: declaration declaration_list      { $$ = astCreate(AST_DECLARATION_LIST, 0, $1,$2,0,0); }
    |                                               { $$ = 0; }
    ;       

declaration: declaration_function           {$$=$1;} //{ $$ = astCreate(AST_DECLARATION, 0, $1,0,0,0); }
    | declaration_global                    {$$=$1;} //{ $$ = astCreate(AST_DECLARATION, 0, $1,0,0,0); }
    ;

// -----------------------------------
// -----------  Globals  -------------
// -----------------------------------

// tipo da variavel ou retorno de função
// nome
// resto

declaration_global: declaration_global_int    {$$=$1;}//{ $$ = astCreate(DECLARATION_GLOBAL_INT, 0, $1,0,0,0); }  
    | declaration_global_char                 {$$=$1;}//{ $$ = astCreate(DECLARATION_GLOBAL_CHAR, 0, $1,0,0,0); }    
    | declaration_global_float                {$$=$1;}//{ $$ = astCreate(DECLARATION_GLOBAL_FLOAT, 0, $1,0,0,0); }    
    ;


declaration_global_int: KW_INT TK_IDENTIFIER ':' expression ';'         { $$ = astCreate(AST_DECLARATION_GLOBAL_INT, $2, $4,0,0,0); }
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ';'                      { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, $2, lit_arr_size,0,0,0); }
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'        { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, $2, lit_arr_size,$7,0,0); }
    ;

declaration_global_char: KW_CHAR TK_IDENTIFIER ':' expression ';'       { $$ = astCreate(AST_DECLARATION_GLOBAL_CHAR, $2, $4,0,0,0); }
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ';'                     { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, $2, lit_arr_size,0,0,0); }    
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'       { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, $2, lit_arr_size,$7,0,0); }    
    ;

declaration_global_float: KW_FLOAT TK_IDENTIFIER ':' LIT_INTEGER OPERATOR_DIV LIT_INTEGER ';'    { AST* lit1 = astCreate(AST_SYMBOL, $4, 0,0,0,0); AST* lit2 = astCreate(AST_SYMBOL, $6, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_FLOAT, $2, lit1,lit2,0,0); }
    | KW_FLOAT TK_IDENTIFIER '[' LIT_INTEGER ']' ';'                                    { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_FLOAT, $2, lit_arr_size,0,0,0); }   
    ;


array_val: LIT_INTEGER array_val                    { $$ = astCreate(AST_ARRAY_VAL, $1, $2,0,0,0); }
    | LIT_INTEGER                                   { $$ = astCreate(AST_ARRAY_VAL, $1, 0,0,0,0); }
    | LIT_CHAR array_val                            { $$ = astCreate(AST_ARRAY_VAL, $1, $2,0,0,0); }
    | LIT_CHAR                                      { $$ = astCreate(AST_ARRAY_VAL, $1, 0,0,0,0); }
    ;


// -----------------------------------
// ---------  Functions  -------------
// -----------------------------------

declaration_function: KW_INT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body     { $$ = astCreate(AST_DECLARATION_FUNCTION_INT, $2, $4,$6,0,0); }
    | KW_CHAR TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body                    { $$ = astCreate(AST_DECLARATION_FUNCTION_CHAR, $2, $4,$6,0,0); }
    | KW_FLOAT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body                   { $$ = astCreate(AST_DECLARATION_FUNCTION_FLOAT, $2, $4,$6,0,0); }
    ;

declaration_function_args_or_empty: declaration_function_args                                                       { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY, 0, $1,0,0,0); }
    |                                                                                                               { $$ = 0; }
    ;

declaration_function_args: KW_INT TK_IDENTIFIER ',' declaration_function_args       { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   $2, $4,0,0,0); }
    | KW_CHAR TK_IDENTIFIER ',' declaration_function_args                           { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  $2, $4,0,0,0); }
    | KW_FLOAT TK_IDENTIFIER ',' declaration_function_args                          { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, $2, $4,0,0,0); }    
    | KW_INT TK_IDENTIFIER                                                          { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   $2, 0,0,0,0); }
    | KW_CHAR TK_IDENTIFIER                                                         { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  $2, 0,0,0,0); }
    | KW_FLOAT TK_IDENTIFIER                                                        { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, $2, 0,0,0,0); }    
    ;

declaration_function_body: command      { $$ = astCreate(AST_DECLARATION_FUNCTION_BODY, 0, $1,0,0,0);  }
    ;

function_call: TK_IDENTIFIER '(' function_call_args_or_empty ')'     { $$ = astCreate(AST_FUNCTION_CALL, $1, $3,0,0,0);  }
    ;

function_call_args_or_empty: function_call_args     { $$ = $1; }
    |                                               { $$ = 0; }
    ;

function_call_args: expression                       { $$ = astCreate(AST_FUNCTION_CALL_ARGS, 0, $1,0,0,0);  }
    | expression ',' function_call_args              { $$ = astCreate(AST_FUNCTION_CALL_ARGS, 0, $1,$3,0,0);  }
    ;

// -----------------------------------
// ----------  Commands  -------------
// -----------------------------------

command: attribution                            { $$=$1;} 
    | flux_control                              { $$=$1;} 
    | print                                     { $$=$1;} 
    | return                                    { $$=$1;} 
    | command_block                             { $$=$1;} 
    |                                           { $$=0; }
    ;
  
command_block: '{' command_list '}'             { $$ = astCreate(AST_COMMAND_BLOCK, 0, $2,0,0,0); }
    ;

command_list:   command ';' command_list        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$3,0,0); }
    | label command_list                        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$2,0,0); }
    |                                           { $$ = 0;}
    ;


attribution: TK_IDENTIFIER '=' expression       {  $$ = astCreate(AST_ATTRIBUITION, $1, $3,0,0,0); }
    | array_element '=' expression              {  $$ = astCreate(AST_ARRAY_ATTRIBUITION, 0, $1,$3,0,0); }
    ;


expression: LIT_INTEGER                         { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | LIT_CHAR                                  { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | TK_IDENTIFIER                             { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | KW_READ                                   { $$ = astCreate(AST_READ, 0, 0,0,0,0); }
    | array_element                             { $$ = $1; }
    | expression OPERATOR_ADD expression        { $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_ADD, 0, $1,$3,0,0); }
    | expression OPERATOR_SUB expression        { $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_SUB, 0, $1,$3,0,0); }
    | expression OPERATOR_MULT expression       { $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_MULT, 0, $1,$3,0,0); }
    | expression OPERATOR_DIV expression        { $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_DIV, 0, $1,$3,0,0); }
    
    | expression OPERATOR_LT expression         { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_LT, 0, $1,$3,0,0); } 
    | expression OPERATOR_LTE expression        { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_LTE, 0, $1,$3,0,0); }
    | expression OPERATOR_GT expression         { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_GT, 0, $1,$3,0,0); }    
    | expression OPERATOR_GTE expression        { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_GTE, 0, $1,$3,0,0); }
    | expression OPERATOR_EQ expression         { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EQ, 0, $1,$3,0,0); }
    | expression OPERATOR_DIF expression        { $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_DIF, 0, $1,$3,0,0); }
    
    | '(' expression ')'                        { $$ = astCreate(AST_EXPRESSION_BLOCK, 0, $2,0,0,0); }
    | function_call                             { $$ = $1;}
    ; 

array_element: TK_IDENTIFIER '[' expression ']'     { $$ = astCreate(AST_ARRAY_ELEMENT, $1, $3,0,0,0); }
    ;

print: KW_PRINT print_rest              { $$ = astCreate(AST_PRINT, 0, $2,0,0,0); }
    ;

print_rest: LIT_STRING                  { AST* lit = astCreate(AST_SYMBOL, $1, 0,0,0,0); $$ = astCreate(AST_PRINT_REST, 0, lit,0,0,0); }
    | LIT_STRING ',' print_rest         { AST* lit = astCreate(AST_SYMBOL, $1, 0,0,0,0); $$ = astCreate(AST_PRINT_REST, 0, lit,$3,0,0); }
    | expression                        { $$ = $1; }
    | expression ',' print_rest         { $$ = astCreate(AST_PRINT_REST, 0, $1,$3,0,0); }
    ;

return: KW_RETURN expression        { $$ = astCreate(AST_RETURN, 0, $2,0,0,0); }
    ;


// -----------------------------------
// --------  Flux Control  -----------
// -----------------------------------


flux_control: KW_IF expression KW_THEN command              { $$ = astCreate(AST_FLUX_CONTROLL_IF,   0, $2,$4,0,0); }
    | KW_IF expression KW_THEN command KW_ELSE command      { $$ = astCreate(AST_FLUX_CONTROLL_IF,   0, $2,$4,$6,0); }
    | KW_WHILE expression command                           { $$ = astCreate(AST_FLUX_CONTROLL_WHILE,   0, $2,$3,0,0); }
    | go_to                                                 { $$ = $1; }
    ;

label: TK_IDENTIFIER ':'        { $$ = astCreate(AST_LABEL,   $1, 0,0,0,0); }
    ;

go_to: KW_GOTO TK_IDENTIFIER    { $$ = astCreate(AST_FLUX_CONTROLL_GOTO,   $2, 0,0,0,0); }
    ;


%%

AST* getRootNode() {
    //astPrint(rootNode, 0);
    return rootNode;
}


void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d.\n", s, getLineNumber());
    exit(3);
}