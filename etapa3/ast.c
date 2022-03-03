// AST
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ast.h"


AST *astCreate(int type, HASH_NODE *symbol, AST* s0, AST* s1, AST* s2, AST* s3) {

    AST *newnode;

    newnode = (AST*) calloc(1, sizeof(AST));

    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;

    return newnode;
}
void astPrint(AST *node, int level) {

    if (node==0) return;

    for(int i=0; i<level; i++) 
        fprintf(stderr, "  ");

    fprintf(stderr, "ast(");

    switch (node->type) {
        case AST_SYMBOL:        fprintf(stderr, "AST_SYMBOL"); break;

        case AST_ADD:           fprintf(stderr, "AST_ADD"); break;
        case AST_SUB:           fprintf(stderr, "AST_SUB"); break;
        case AST_MULT:          fprintf(stderr, "AST_MULT"); break;
        case AST_DIV:           fprintf(stderr, "AST_DIV"); break;

        case AST_LT:            fprintf(stderr, "AST_LT"); break;
        case AST_LTE:           fprintf(stderr, "AST_LTE"); break;
        case AST_GT:            fprintf(stderr, "AST_GT"); break;
        case AST_GTE:           fprintf(stderr, "AST_GTE"); break;
        case AST_EQ:            fprintf(stderr, "AST_EQ"); break;
        case AST_DIF:           fprintf(stderr, "AST_DIF"); break;

        case AST_COMMAND:       fprintf(stderr, "AST_COMMAND"); break;
        case AST_COMMAND_BLOCK: fprintf(stderr, "AST_COMMAND_BLOCK"); break;
        case AST_FLUX_CONTROL:  fprintf(stderr, "AST_FLUX_CONTROL"); break;
        case AST_PRINT:         fprintf(stderr, "AST_PRINT"); break;
        case AST_RETURN:        fprintf(stderr, "AST_RETURN"); break;
        case AST_ATTRIBUITION:  fprintf(stderr, "AST_ATTRIBUITION"); break;



        case AST_DECLARATION_FUNCTION_BODY:  fprintf(stderr, "AST_DECLARATION_FUNCTION_BODY"); break;
        
        
        case AST_COMMAND_LIST:       fprintf(stderr, "AST_COMMAND_LIST"); break;
    
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }

    if (node->symbol != 0) 
        fprintf(stderr, ", %s\n", node->symbol->text);
    else 
        fprintf(stderr, ")\n");

    for (int i=0; i<MAX_SONS; ++i)
        astPrint(node->son[i], level+1);    

    
    
}


// EOF
