#include "semantic.h"

#include "y.tab.h"

int SemanticErrors = 0;

#define DATATYPE_ARRAY_INT       1;
#define DATATYPE_CHAR            2;
#define DATATYPE_ARRAY_CHAR      3;
#define DATATYPE_FLOAT           4;
#define DATATYPE_ARRAY_FLOAT     5;
#define DATATYPE_INT             6;

void set_datatype(AST* node){
    switch (node->type) {        
        case AST_DECLARATION_GLOBAL_ARRAY_INT:      node->symbol->datatype = DATATYPE_ARRAY_INT     ; break;      
        case AST_DECLARATION_GLOBAL_CHAR:           node->symbol->datatype = DATATYPE_CHAR          ; break;
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:     node->symbol->datatype = DATATYPE_ARRAY_CHAR    ; break;
        case AST_DECLARATION_GLOBAL_FLOAT:          node->symbol->datatype = DATATYPE_FLOAT         ; break;
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:    node->symbol->datatype = DATATYPE_ARRAY_FLOAT   ; break;
        case AST_DECLARATION_GLOBAL_INT:            node->symbol->datatype = DATATYPE_INT           ; break;
        
        case AST_DECLARATION_FUNCTION_INT:          node->symbol->datatype = DATATYPE_INT           ; break;
        case AST_DECLARATION_FUNCTION_CHAR:         node->symbol->datatype = DATATYPE_CHAR          ; break;    
        case AST_DECLARATION_FUNCTION_FLOAT:        node->symbol->datatype = DATATYPE_FLOAT         ; break;

        default: break;
    }
}

void check_and_set_declarations(AST* node) {

    if (node==0) return;

    switch (node->type) {
        
        case AST_DECLARATION_GLOBAL_ARRAY_INT:         
        case AST_DECLARATION_GLOBAL_CHAR:
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:        
        case AST_DECLARATION_GLOBAL_FLOAT: 
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:        
        case AST_DECLARATION_GLOBAL_INT:           
            if (node->symbol)  
                if(node->symbol->type != TK_IDENTIFIER) {
                    fprintf(stderr, "Semantic ERROR: variable %s already declared \n", node->symbol->text);
                    ++SemanticErrors;                    
                } else{
                    node->symbol->type = SYMBOL_VARIABLE;
                    set_datatype(node);
                }
            break;
        
        
        case AST_DECLARATION_FUNCTION_INT:          
        case AST_DECLARATION_FUNCTION_CHAR:             
        case AST_DECLARATION_FUNCTION_FLOAT:
            if (node->symbol)  
                if(node->symbol->type != TK_IDENTIFIER) {
                    fprintf(stderr, "Semantic ERROR: function %s already declared \n", node->symbol->text);
                    ++SemanticErrors;
                } else{
                    node->symbol->type = SYMBOL_FUNCTION;
                    set_datatype(node);
                }                
                
            break;            
        
        default: 
            break;

    }
    

    
    for (int i=0; i<MAX_SONS; ++i)
        check_and_set_declarations(node->son[i]);    
}



void check_operands(AST* node) {
    if (node==0) return;

    switch (node->type) {
        
        case AST_EXPRESSION_BINARY: 
            fprintf(stderr, "BYNARY OPERATION \t text: %s \t OP code %d  \t symbol datatype  %d  \n", node->symbol->text, node->symbol->type, node->symbol->datatype);
            
            break;
        default: 
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_operands(node->son[i]);    
}


void check_undeclared() {

    HASH_NODE *node;

    int i;
    for (i=0; i<HASH_SIZE; i++){
        for (node=getNode(i); node; node=node->next) {
            if(node -> type == TK_IDENTIFIER) {
                printf("\nSEMANTIC ERROR: symbol %s undeclared.\n", node->text);
                ++SemanticErrors;
            } 
        }
    }
    printf("\n\n Erros semanticos: %d \n\n", SemanticErrors);
}


int get_semantic_errors() {
    return SemanticErrors;
}
