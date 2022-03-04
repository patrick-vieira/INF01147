// AST

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#ifndef ASH_HEADER
#define ASH_HEADER

#define MAX_SONS 4


#define AST_SYMBOL 1

#define AST_ADD 2
#define AST_SUB 3
#define AST_MULT 4
#define AST_DIV 5

#define AST_LT 6
#define AST_LTE 7
#define AST_GT 8
#define AST_GTE 9

#define AST_EQ 10
#define AST_DIF 11



#define AST_COMMAND         200
#define AST_COMMAND_BLOCK   201
#define AST_FLUX_CONTROL    202
#define AST_PRINT           203
#define AST_RETURN          204
#define AST_ATTRIBUITION    205

#define AST_COMMAND_LIST    222


#define AST_DECLARATION_FUNCTION                    1000
#define AST_DECLARATION_FUNCTION_INT                1001
#define AST_DECLARATION_FUNCTION_CHAR               1002
#define AST_DECLARATION_FUNCTION_FLOAT              1003

#define AST_DECLARATION_FUNCTION_ARGS               1100
#define AST_DECLARATION_FUNCTION_ARGS_INT           1101
#define AST_DECLARATION_FUNCTION_ARGS_CHAR          1102
#define AST_DECLARATION_FUNCTION_ARGS_FLOAT         1103
#define AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY      1200
#define AST_DECLARATION_FUNCTION_BODY               1300


#define AST_DECLARATION               5000
#define AST_DECLARATION_LIST          5001

#define AST_PROGRAM          21



#define AST_LABEL               2000



typedef struct astnode
{
    int type;    
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;


AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);
char* testtt();
char* astToCode(AST *node);

#endif

// EOF
