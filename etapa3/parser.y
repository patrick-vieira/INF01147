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

%token OPERATOR_LTE       
%token OPERATOR_GTE       
%token OPERATOR_EQ       
%token OPERATOR_DIF   

%token<symbol> TK_IDENTIFIER     

%token<symbol> LIT_INTEGER      
%token<symbol> LIT_CHAR          
%token LIT_STRING   

%token TOKEN_ERROR        

%type<ast> program

%type<ast> declaration_list
%type<ast> declaration


%type<ast> declaration_global
%type<ast> declaration_global_int
%type<ast> declaration_global_char
%type<ast> declaration_global_float


%type<ast> declaration_function
%type<ast> declaration_function_args
%type<ast> declaration_function_args_or_empty
%type<ast> declaration_function_body

%type<ast> command
%type<ast> command_block
%type<ast> command_list
%type<ast> label

%type<ast> attribution

%type<ast> expression


%left '<' '>' OPERATOR_LTE OPERATOR_GTE OPERATOR_EQ OPERATOR_DIF
%left '+' '-' 
%left '*' '/'

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

declaration_global: declaration_global_int      
    | declaration_global_char                   
    | declaration_global_float                  
    ;


declaration_global_int: KW_INT TK_IDENTIFIER ':' expression ';'         //{ $$ = astCreate(AST_DECLARATION_GLOBAL_INT, 0, $1,0,0,0); }
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
    | KW_INT TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'
    ;

declaration_global_char: KW_CHAR TK_IDENTIFIER ':' expression ';'       //{ $$ = astCreate(AST_DECLARATION_GLOBAL_CHAR, 0, $1,0,0,0); }
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
    | KW_CHAR TK_IDENTIFIER '[' LIT_INTEGER ']' ':' array_val ';'
    ;

declaration_global_float: KW_FLOAT TK_IDENTIFIER ':' LIT_INTEGER '/' LIT_INTEGER ';'    //{ $$ = astCreate(AST_DECLARATION_GLOBAL_FLOAT, 0, $1,0,0,0); }
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

command: attribution                            { $$=$1;} //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | flux_control                              //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | print                                     //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | return                                    //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    | command_block                             { $$=$1;} //{ $$ = astCreate(AST_COMMAND, 0, $1,0,0,0); }
    |                                           { $$ = 0;}
    ;
  
command_block: '{' command_list '}'             { $$ = astCreate(AST_COMMAND_BLOCK, 0, $2,0,0,0); }
    ;

command_list:   command ';' command_list        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$3,0,0); }
    | label command_list                        { $$ = astCreate(AST_COMMAND_LIST, 0, $1,$2,0,0); }
    |                                           { $$ = 0;}
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

label: TK_IDENTIFIER ':'        { $$ = astCreate(AST_LABEL,   $1, 0,0,0,0); }
    ;

go_to: KW_GOTO TK_IDENTIFIER
    ;


%%

AST* getRootNode() {
    //astPrint(rootNode, 0);
    return rootNode;
}

void unparse(char* outPath) {
    
    FILE *fp;

    fp = fopen(outPath, "w+");
    fprintf(fp, "AAAAAAAAAAAAAAAAAAAA..\n");
    fputs("asdasdasdAD...\n", fp);
   
    fclose(fp);


    /* FILE *file;      
    file = fopen(outPath, "w+");    
    
    // astPrint(rootNode, 0, file);
    char* code = astToCode(rootNode);
    //testwrite(outPath);

    fprintf(file, code);
    
    fclose(file);     */

}

void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d.\n", s, getLineNumber());
    exit(3);
}