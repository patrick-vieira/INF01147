%{
    #include <stdio.h>
    #include "hash.h"
    #include "ast.h"

    void syntaxError(const char *s);
    void yyerror(const char *s);
    int getLineNumber(void);
    AST* getRootNode(void); 

    int getErrorCount(void);
    int error_count = 0;

    int yylex(void); 

    AST *rootNode;

%}

%union 
{
    HASH_NODE *symbol;
    AST *ast;
}

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

%type<ast> semi_column
%type<ast> print_comma
%type<ast> fun_args_comma
%type<ast> return_expression
%type<ast> flux_control_expression

%left OPERATOR_LTE OPERATOR_LT OPERATOR_GTE OPERATOR_GT OPERATOR_EQ OPERATOR_DIF
%left OPERATOR_ADD OPERATOR_SUB
%left OPERATOR_MULT OPERATOR_DIV


%left KW_FLOAT KW_INT KW_CHAR

%left KW_IF KW_THEN
%left KW_ELSE
%left KW_WHILE KW_GOTO KW_READ KW_PRINT KW_RETURN

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

semi_column: ';'		{ $$ = 0; }
	| error		{ $$ = 0; syntaxError("Expecting ;\n");}
	;

declaration_global_int: KW_INT TK_IDENTIFIER ':' expression semi_column         { $$ = astCreate(AST_DECLARATION_GLOBAL_INT, $2, $4,0,0,0); }
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' semi_column                      { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, $2, lit_arr_size,0,0,0); }
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val semi_column        { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_INT, $2, lit_arr_size,$7,0,0); }
    | KW_INT TK_IDENTIFIER '[' error ']' ':'			                { $$ = 0; syntaxError("Global Integer array declaration error.\n");}
    | KW_INT TK_IDENTIFIER error 			                	{ $$ = 0; syntaxError("Global Integer declaration error.\n");}
    ;

declaration_global_char: KW_CHAR TK_IDENTIFIER ':' expression semi_column       { $$ = astCreate(AST_DECLARATION_GLOBAL_CHAR, $2, $4,0,0,0); }
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' semi_column                     { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, $2, lit_arr_size,0,0,0); }
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val semi_column       { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_CHAR, $2, lit_arr_size,$7,0,0); }
    | KW_CHAR TK_IDENTIFIER '[' error ']' ':'			                { $$ = 0; syntaxError("Global Char array declaration error.\n");}
    | KW_CHAR TK_IDENTIFIER error 			                	{ $$ = 0; syntaxError("Global Char declaration error.\n");}
    ;

declaration_global_float: KW_FLOAT TK_IDENTIFIER ':' LIT_INTEGER OPERATOR_DIV LIT_INTEGER semi_column    { AST* lit1 = astCreate(AST_SYMBOL, $4, 0,0,0,0); AST* lit2 = astCreate(AST_SYMBOL, $6, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_FLOAT, $2, lit1,lit2,0,0); }
    | KW_FLOAT TK_IDENTIFIER '[' LIT_INTEGER ']' semi_column                                    { AST* lit_arr_size = astCreate(AST_SYMBOL, $4, 0,0,0,0); $$ = astCreate(AST_DECLARATION_GLOBAL_ARRAY_FLOAT, $2, lit_arr_size,0,0,0); }
    | KW_FLOAT TK_IDENTIFIER '[' error ']'			                	{ $$ = 0; syntaxError("Global float declaration error.\n");}
    | KW_FLOAT TK_IDENTIFIER error 			                	{ $$ = 0; syntaxError("Global Float declaration error.\n");}
    ;


array_val: LIT_INTEGER array_val                    { $$ = astCreate(AST_ARRAY_VAL, $1, $2,0,0,0); }
    | LIT_INTEGER                                   { $$ = astCreate(AST_ARRAY_VAL, $1, 0,0,0,0); }
    | LIT_CHAR array_val                            { $$ = astCreate(AST_ARRAY_VAL, $1, $2,0,0,0); }
    | LIT_CHAR                                      { $$ = astCreate(AST_ARRAY_VAL, $1, 0,0,0,0); }
    | ','                                      	{ $$ = 0; syntaxError("Unexpected comma while initializing array.\n");}
    ;


// -----------------------------------
// ---------  Functions  -------------
// -----------------------------------

declaration_function: KW_INT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body     { $$ = astCreate(AST_DECLARATION_FUNCTION_INT, $2, $4,$6,0,0); }
    | KW_CHAR TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body                    { $$ = astCreate(AST_DECLARATION_FUNCTION_CHAR, $2, $4,$6,0,0); }
    | KW_FLOAT TK_IDENTIFIER '(' declaration_function_args_or_empty ')' declaration_function_body                   { $$ = astCreate(AST_DECLARATION_FUNCTION_FLOAT, $2, $4,$6,0,0); }

    | KW_INT error '(' declaration_function_args_or_empty ')' declaration_function_body                   { $$ = 0; syntaxError("Identifier not found for integger function declaration.\n");}
    | KW_CHAR error '(' declaration_function_args_or_empty ')' declaration_function_body                   { $$ = 0; syntaxError("Identifier not found for char function declaration.\n");}
    | KW_FLOAT error '(' declaration_function_args_or_empty ')' declaration_function_body                   { $$ = 0; syntaxError("Identifier not found for float function declaration.\n");}
    | TK_IDENTIFIER '(' declaration_function_args_or_empty ')'                    { $$ = 0; syntaxError("Function type not found.\n");}

    ;


declaration_function_args_or_empty: declaration_function_args                                                       { $$ = $1; } //astCreate(AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY, 0, $1,0,0,0); }
    |                                                                                                               { $$ = 0; }
    ;

declaration_function_args: KW_INT TK_IDENTIFIER fun_args_comma declaration_function_args       { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   $2, $4,0,0,0); }
    | KW_CHAR TK_IDENTIFIER fun_args_comma declaration_function_args                           { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  $2, $4,0,0,0); }
    | KW_FLOAT TK_IDENTIFIER fun_args_comma declaration_function_args                          { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, $2, $4,0,0,0); }
    | KW_INT TK_IDENTIFIER                                                          { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_INT,   $2, 0,0,0,0); }
    | KW_CHAR TK_IDENTIFIER                                                         { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_CHAR,  $2, 0,0,0,0); }
    | KW_FLOAT TK_IDENTIFIER                                                        { $$ = astCreate(AST_DECLARATION_FUNCTION_ARGS_FLOAT, $2, 0,0,0,0); }

    | error TK_IDENTIFIER                                                       { $$ = 0; syntaxError("Function args malformatted, expected  type and identifier \n");}
    | KW_INT error                                                        	{ $$ = 0; syntaxError("Function args malformatted, integer args identifier expected \n");}
    | KW_CHAR error                                                        	{ $$ = 0; syntaxError("Function args malformatted, char args identifier expected \n");}
    | KW_FLOAT error                                                        	{ $$ = 0; syntaxError("Function args malformatted, float args identifier expected \n");}

    ;

fun_args_comma: ','		{ $$ = 0; }
	| error		{ $$ = 0; syntaxError("Function args malformatted, comma expected between arguments \n");}
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

command_list:   command semi_column command_list        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$3,0,0); }
    | label command_list                        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$2,0,0); }
    |                                           { $$ = 0;}
    ;


attribution: TK_IDENTIFIER '=' expression       {  $$ = astCreate(AST_ATTRIBUITION, $1, $3,0,0,0); }
    | TK_IDENTIFIER '[' expression ']' '=' expression              {  $$ = astCreate(AST_ARRAY_ATTRIBUITION, $1, $3,$6,0,0); }
    | TK_IDENTIFIER '[' expression ']' error expression               { $$ = 0; syntaxError("Attribuition error '=' expected.\n");}
    | TK_IDENTIFIER error expression            			 { $$ = 0; syntaxError("Attribuition error '=' expected.\n");}
    ;


expression: LIT_INTEGER                         { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | LIT_CHAR                                  { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | TK_IDENTIFIER                             { $$ = astCreate(AST_SYMBOL, $1, 0,0,0,0); }
    | KW_READ                                   { $$ = astCreate(AST_READ, 0, 0,0,0,0); }
    | TK_IDENTIFIER '[' expression ']'     	{ $$ = astCreate(AST_ARRAY_ELEMENT, $1, $3,0,0,0); }
    | expression OPERATOR_ADD expression        { $$ = astCreate(AST_ADD, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //
    | expression OPERATOR_SUB expression        { $$ = astCreate(AST_SUB, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //
    | expression OPERATOR_MULT expression       { $$ = astCreate(AST_MULT, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //
    | expression OPERATOR_DIV expression        { $$ = astCreate(AST_DIV, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_ARITHMETIC, $2, $1,$3,0,0); } //
    
    | expression OPERATOR_LT expression         { $$ = astCreate(AST_LT, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    | expression OPERATOR_LTE expression        { $$ = astCreate(AST_LTE, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    | expression OPERATOR_GT expression         { $$ = astCreate(AST_GT, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    | expression OPERATOR_GTE expression        { $$ = astCreate(AST_GTE, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    | expression OPERATOR_EQ expression         { $$ = astCreate(AST_EQ, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    | expression OPERATOR_DIF expression        { $$ = astCreate(AST_DIF, $2, $1,$3,0,0); } //{ $$ = astCreate(AST_EXPRESSION_BINARY_BOOLEAN, $2, $1,$3,0,0); } //
    
    | '(' expression ')'                        { $$ = astCreate(AST_EXPRESSION_BLOCK, 0, $2,0,0,0); }
    | function_call                             { $$ = $1;}
    | expression error expression        { $$ = 0; syntaxError("invalid expression. \n");}
    | expression error         { $$ = 0; syntaxError("invalid expression. \n");}
    | error expression        { $$ = 0; syntaxError("invalid expression. \n");}

    ; 

print: KW_PRINT print_rest              { $$ = astCreate(AST_PRINT, 0, $2,0,0,0); }
    ;

print_rest: LIT_STRING                  { AST* lit = astCreate(AST_SYMBOL, $1, 0,0,0,0); $$ = astCreate(AST_PRINT_STRING, 0, lit,0,0,0); }
    | LIT_STRING print_comma print_rest         { AST* lit = astCreate(AST_SYMBOL, $1, 0,0,0,0); $$ = astCreate(AST_PRINT_STRING, 0, lit,$3,0,0); }
    | expression                        { $$ = astCreate(AST_PRINT_EXP, 0, $1,0,0,0); }
    | expression print_comma print_rest         { $$ = astCreate(AST_PRINT_EXP, 0, $1,$3,0,0); }
    ;

print_comma: ','		{ $$ = 0; }
	| error		{ $$ = 0; syntaxError("Print malformatted, comma expected \n");}
	;

return: KW_RETURN return_expression       { $$ = astCreate(AST_RETURN, 0, $2,0,0,0); }
    ;

return_expression: expression 	{ $$ = $1; }
	| error		{ $$ = 0; syntaxError("Return malformatted, expression or value expected \n");}
	;


// -----------------------------------
// --------  Flux Control  -----------
// -----------------------------------


flux_control: KW_IF flux_control_expression KW_THEN command              { $$ = astCreate(AST_FLUX_CONTROLL_IF,   0, $2,$4,0,0); }
    | KW_IF flux_control_expression KW_THEN command KW_ELSE command      { $$ = astCreate(AST_FLUX_CONTROLL_IF_ELSE,   0, $2,$4,$6,0); }
    | KW_WHILE flux_control_expression command                           { $$ = astCreate(AST_FLUX_CONTROLL_WHILE,   0, $2,$3,0,0); }
    | go_to                                                 { $$ = $1; }
    ;


flux_control_expression: expression 	{ $$ = $1; }
	| error		{ $$ = 0; syntaxError("Flow control expects an expression \n");}
	| '(' error ')'		{ $$ = 0; syntaxError("Flow control expects an expression \n");}
	;

label: TK_IDENTIFIER ':'        { $$ = astCreate(AST_LABEL,   $1, 0,0,0,0); }
    ;

go_to: KW_GOTO TK_IDENTIFIER    { $$ = astCreate(AST_FLUX_CONTROLL_GOTO,   $2, 0,0,0,0); }
    ;


%%

int getErrorCount() {
    return error_count;
}
AST* getRootNode() {
    //astPrint(rootNode, 0);
    return rootNode;
}

void syntaxError(const char *s) {
    fprintf(stderr, "syntax error at line %d: %s.\n", getLineNumber(), s);
    error_count += 1;

}

void yyerror(const char *s) {
    //fprintf(stderr, "%s at line %d.\n", s, getLineNumber());
    // exit(3);
}