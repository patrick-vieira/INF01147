// AST

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


#define AST_DECLARATION_FUNCTION_BODY    1000



typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;


AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3);
void astPrint(AST *node, int level);

#endif

// EOF
