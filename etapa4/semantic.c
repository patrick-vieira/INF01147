#include "semantic.h"

#include "y.tab.h"

int SemanticErrors = 0;


int get_semantic_errors() {
    return SemanticErrors;
}

void check_and_set_declarations(AST* node) {

    if (node==0) return;

    switch (node->type) {

        case AST_SYMBOL:   
            set_datatype(node);
            break;

        case AST_DECLARATION_GLOBAL_ARRAY_INT:   
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:    
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:    
            if (node->symbol)  
                if(node->symbol->type != TK_IDENTIFIER) {
                    fprintf(stderr, "Semantic ERROR: variable %s already declared \n", node->symbol->text);
                    ++SemanticErrors;                    
                } else{
                    node->symbol->type = SYMBOL_VECTOR;
                    set_datatype(node);
                }
            break;    
            
        case AST_DECLARATION_GLOBAL_CHAR:      
        case AST_DECLARATION_GLOBAL_FLOAT:     
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

void check_undeclared() {

    HASH_NODE *node;

    int i, undeclered_semantic_errors = 0;

    for (i=0; i<HASH_SIZE; i++){
        for (node=getNode(i); node; node=node->next) {
            if(node -> type == TK_IDENTIFIER) {
                printf("\nSEMANTIC ERROR: symbol %s undeclared.\n", node->text);
                ++SemanticErrors;
                ++undeclered_semantic_errors;
            } 
        }
    }

    printf("\n\n Undeclared semantic errors: %d \n\n", undeclered_semantic_errors);
}

void check_operands(AST* node) {
    if (node==0) return;

    switch (node->type) {
        
        case AST_EXPRESSION_BINARY_BOOLEAN: 
            break;
        case AST_EXPRESSION_BINARY_ARITHMETIC: 
            logBinaryExpression(node);

            if(!is_number(node->son[0])) {
                fprintf(stderr, "\nSemantic ERROR: [CHECK OPERANDS]: \n invalid left operand [%s] datatype [%d] for OP[%s] \n\n", node->son[0]->symbol->text, node->son[0]->symbol->datatype, node->symbol->text);
                ++SemanticErrors;
            }
            if(!is_number(node->son[1])) {
                fprintf(stderr, "\nSemantic ERROR: [CHECK OPERANDS]: \n  invalid right operand [%s] datatype [%d] for OP[%s] \n\n", node->son[1]->symbol->text, node->son[1]->symbol->datatype, node->symbol->text);
                ++SemanticErrors;
            }
            break;
        default: 
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_operands(node->son[i]);    
}

void check_attibuition(AST* node){
    if (node==0) return;

    switch (node->type) {
        
        case AST_ATTRIBUITION: 
            fprintf(stderr, "\n[check_attibuition] -  AST_ATTRIBUITION \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype); 

            if(!is_expression_of_type(node->son[0], node->symbol->datatype)){                
                fprintf(stderr, "Semantic ERROR: attribuition fail var typeof[%s] \n", node->symbol->text);
                ++SemanticErrors;      
            }
            break;

        case AST_ARRAY_ATTRIBUITION: 
            break;
        default: 
        break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_attibuition(node->son[i]);    
}

void check_function_call(AST* node){
    if (node==0) return;

    switch (node->type) {
        
        case AST_ATTRIBUITION: 
            break;
        case AST_ARRAY_ATTRIBUITION: 
            break;
        default: 
        break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_operands(node->son[i]);    
}


// -------------- AUX FUNCTIONS

void set_datatype(AST* node){
    switch (node->type) {
        case AST_DECLARATION_GLOBAL_ARRAY_INT:      node->symbol->datatype = DATATYPE_ARRAY_INT     ; break;
        case AST_DECLARATION_GLOBAL_CHAR:           node->symbol->datatype = DATATYPE_CHAR          ; break;
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:     node->symbol->datatype = DATATYPE_ARRAY_CHAR    ; break;
        case AST_DECLARATION_GLOBAL_FLOAT:          node->symbol->datatype = DATATYPE_FLOAT         ; break; //TODO pode ser int?
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:    node->symbol->datatype = DATATYPE_ARRAY_FLOAT   ; break;
        case AST_DECLARATION_GLOBAL_INT:            node->symbol->datatype = DATATYPE_INT           ; break;

        case AST_DECLARATION_FUNCTION_INT:          node->symbol->datatype = DATATYPE_INT           ; break;
        case AST_DECLARATION_FUNCTION_CHAR:         node->symbol->datatype = DATATYPE_CHAR          ; break;
        case AST_DECLARATION_FUNCTION_FLOAT:        node->symbol->datatype = DATATYPE_FLOAT         ; break;

        case AST_SYMBOL:
            fprintf(stderr, "set_datatype AST_SYMBOL \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);

            if(node->symbol->type == LIT_INTEGER)
                node->symbol->datatype = DATATYPE_INT;
            if(node->symbol->type == LIT_CHAR)
                node->symbol->datatype = DATATYPE_CHAR;
            fprintf(stderr, "set_datatype AST_SYMBOL \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);
            fprintf(stderr, "\n");

        default: break;
    }
}

void logBinaryExpression(AST* node){

    fprintf(stderr, "\n");

    fprintf(stderr, "BYNARY ARITHMETIC OPERATION \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);
    fprintf(stderr, "                  LEFT  SON \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->son[0]->type, node->son[0]->symbol->text, node->son[0]->symbol->type, node->son[0]->symbol->datatype);
    fprintf(stderr, "                  RIGHT SON \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->son[1]->type, node->son[1]->symbol->text, node->son[1]->symbol->type, node->son[1]->symbol->datatype);

    char* code = astToCode(node, 0);
    fprintf(stderr, "                 EXPRESSION \t %s \n\n", code);

}

int is_number(AST* node) {
    if(    is_lit_of_type(node, DATATYPE_INT)
           || is_arithmetic(node)
           || is_array_index_of_type(node, DATATYPE_ARRAY_INT)
           || is_variable_of_type(node, DATATYPE_INT)
           || is_function_call_of_type(node, DATATYPE_INT)
            )
        return 1;
    return 0;
}

int is_arithmetic(AST* node){
    if(node->symbol->type == OPERATOR_ADD
       || node->symbol->type == OPERATOR_SUB
       || node->symbol->type == OPERATOR_MULT
       || node->symbol->type == OPERATOR_DIV
            )
        return 1;
    return 0;
}

int is_expression_of_type_aux(AST* node, int of_type){


    if(node->type == AST_SYMBOL && node->symbol->datatype == of_type)
        return 0;
    else if(node->type == AST_FUNCTION_CALL && node->symbol->datatype == of_type)
        return 0;
    else if(node->type == AST_ARRAY_ELEMENT && is_array_index_of_type(node, of_type))
        return 0;
    else if(node->type == AST_EXPRESSION_BINARY_ARITHMETIC){
        int left = is_expression_of_type_aux(node->son[0], of_type);
        int right = is_expression_of_type_aux(node->son[1], of_type);

        if(left + right)
            fprintf(stderr, "\n left [%d] right [%d] = [%d]\n ", left, right, left+right);

        return left + right;
    }

    fprintf(stderr, "\n[is_expression_of_type] expected [%d] \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", of_type, node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);

    return 1;

}

int is_expression_of_type(AST* node, int of_type){
    int is_from_type = is_expression_of_type_aux(node, of_type) == 0;
    if(!is_from_type)
        fprintf(stderr, "Expression of node [%s] not from type [%d] is from type [%d]\n", node->symbol->text, of_type, node->symbol->datatype);
    return is_from_type;
}

int is_valid_array_index(AST* node){
    if(is_expression_of_type(node->son[0], DATATYPE_INT))
        return 1;
    return 0;
}

int is_array_index_of_type(AST* node, int of_type) {

    if(node->symbol->type == SYMBOL_VECTOR) {
        if (node->type == AST_ARRAY_ELEMENT
            && node->symbol->datatype == of_type
            && is_valid_array_index(node))
            return 1;
        else
            fprintf(stderr,
                    "\n[is_array_index_of_type] expected [%d] \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n",
                    of_type, node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);
    }
    return 0;
}

int is_variable_of_type(AST* node, int of_type){
    if(node->symbol->type == SYMBOL_VARIABLE && node->type == AST_SYMBOL && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

int is_lit_of_type(AST* node, int of_type){
    if(node->type == AST_SYMBOL && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

int is_function_call_of_type(AST* node, int of_type){
    if(node->symbol->type == SYMBOL_FUNCTION && node->symbol->datatype == of_type)
        return 1;
    return 0;
}
