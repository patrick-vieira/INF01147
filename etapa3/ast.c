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

        case AST_COMMAND_LIST:       fprintf(stderr, "AST_COMMAND_LIST"); break;


        case AST_DECLARATION_FUNCTION:                  fprintf(stderr, "AST_DECLARATION_FUNCTION"); break;
        case AST_DECLARATION_FUNCTION_INT:                  fprintf(stderr, "AST_DECLARATION_FUNCTION_INT"); break;
        case AST_DECLARATION_FUNCTION_CHAR:                  fprintf(stderr, "AST_DECLARATION_FUNCTION_CHAR"); break;
        case AST_DECLARATION_FUNCTION_FLOAT:                  fprintf(stderr, "AST_DECLARATION_FUNCTION_FLOAT"); break;
        case AST_DECLARATION_FUNCTION_ARGS_INT:             fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_INT"); break;
        case AST_DECLARATION_FUNCTION_ARGS_CHAR:             fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_CHAR"); break;
        case AST_DECLARATION_FUNCTION_ARGS_FLOAT:             fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_FLOAT"); break;
        case AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY:    fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY"); break;
        case AST_DECLARATION_FUNCTION_BODY:             fprintf(stderr, "AST_DECLARATION_FUNCTION_BODY"); break;


        case AST_DECLARATION_LIST:             fprintf(stderr, "AST_DECLARATION_LIST"); break;
        case AST_DECLARATION:             fprintf(stderr, "AST_DECLARATION"); break;

        case AST_PROGRAM:             fprintf(stderr, "AST_PROGRAM"); break;
                
        case AST_LABEL:       fprintf(stderr, "AST_LABEL"); break;

    
        default: fprintf(stderr, "AST_UNKNOWN"); break;
    }

    if (node->symbol != 0) 
        fprintf(stderr, ", %s) {\n", node->symbol->text);
    else 
        fprintf(stderr, ") {\n");

    for (int i=0; i<MAX_SONS; ++i)
        astPrint(node->son[i], level+1);    

    // for(int i=0; i<level; i++) 
    //     fprintf(stderr, "  ");
    
    // fprintf(stderr, "}\n");
    
}


char* astToCode(AST* node) {
	if(node == 0)
		return "";

	switch (node->type) {
        case AST_PROGRAM: {
            fprintf(stderr, "AST_PROGRAM \n"); 
            char* prog = astToCode(node->son[0]);
            
            return prog;
            break;
        }
        
        case AST_DECLARATION_LIST: {
            fprintf(stderr, "AST_DECLARATION_LIST \n");             
            return astToCode(node->son[0]);
            break;            
        }          
        
        
        case AST_DECLARATION_FUNCTION_INT: {
            fprintf(stderr, "AST_DECLARATION_FUNCTION_INT \n"); 
            
            char* args = astToCode(node->son[0]);
            char* body = astToCode(node->son[1]);
            fprintf(stderr, "args: %s \nbody: %s \n", args, body); 

            char* fn_declaration = (char*)calloc(7 + strlen(node->symbol->text) + strlen(args) + strlen(body) +1, sizeof(char));            
            char* fn_name = node->symbol->text;
            
            sprintf(fn_declaration, "int %s(%s)%s", fn_name, args, body); 
            
            return fn_declaration;
            break;
        }   
        
        case AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY: {
            fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY\n");
            
            char* args = astToCode(node->son[0]);
            return args;
            fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY\n");

            break;
        }   
        case AST_DECLARATION_FUNCTION_ARGS_INT: {
            fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_INT\n");
            
            char* fn_args_int = (char*)calloc(4 + strlen(node->symbol->text) +1, sizeof(char));            
            sprintf(fn_args_int, "int %s", node->symbol->text); 
            
            
            return fn_args_int;
            fprintf(stderr, "AST_DECLARATION_FUNCTION_ARGS_INT\n");
            break;
        }   
        case AST_DECLARATION_FUNCTION_BODY: {
            fprintf(stderr, "AST_DECLARATION_FUNCTION_BODY\n");
            char* body = astToCode(node->son[0]);
            return body;
            break;
        }   
        case AST_COMMAND_BLOCK: {
            fprintf(stderr, "AST_COMMAND_BLOCK\n");
            char* block_content = astToCode(node->son[0]);

            char* block = (char*)calloc(6 + sizeof(block_content), sizeof(char));
            sprintf(block, "{\n%s}", block_content);

            return block;
            break;
        }   
        case AST_COMMAND_LIST: {
            fprintf(stderr, "AST_COMMAND_LIST\n");
            
            char* cmd = astToCode(node->son[0]);
            char* cmdListRest = astToCode(node->son[1]);

            char* cmdList = (char*)calloc(1 + sizeof(cmd) + sizeof(cmdListRest) + 1, sizeof(char));;
            sprintf(cmdList, "%s;\n%s", cmd, cmdListRest);
            
            return cmdList;            
            break;
        }   
        case AST_ATTRIBUITION: {
            fprintf(stderr, "AST_ATTRIBUITION\n");
            
            char* varName = node->symbol->text;
            char* value = astToCode(node->son[0]);

            char* attribuition = (char*)calloc(1 + sizeof(varName) + sizeof(value) + 1, sizeof(char));;
            sprintf(attribuition, "%s=%s", varName, value);

            return attribuition;            
            break;
        }     
        case AST_SYMBOL: {
            fprintf(stderr, "AST_SYMBOL\n");            
            return node->symbol->text;
            break;
        }   
        case AST_ADD: {
            fprintf(stderr, "AST_SYMBOL\n");            
            
            char* valueLeft = astToCode(node->son[0]);            
            char* valueRight = astToCode(node->son[1]);

            char* add = (char*)calloc(1 + sizeof(valueLeft) + sizeof(valueRight) + 1, sizeof(char));;
            sprintf(add, "%s+%s", valueLeft, valueRight);
            
            return add;
            break;
        }   
    
        default: fprintf(stderr, "AST_UNKNOWN\n"); return " "; break;
        
        
    }
}

// EOF
