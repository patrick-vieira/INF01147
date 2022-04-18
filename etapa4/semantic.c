#include "semantic.h"

#include "y.tab.h"

int SemanticErrors = 0;



int get_semantic_errors(AST* startNode) {

    rootNode = startNode;

    fprintf(stderr, "\n\nhash before Semantics\n\n");
    hashPrint();

    fprintf(stderr, "\n\nSemantics start \n\n");
    check_and_set_declarations(rootNode);

    fprintf(stderr, "\nhash after Semantics\n\n");
    hashPrint();

    check_undeclared();
    check_expressions(rootNode);
    check_attibuition(rootNode);
    check_function_call(rootNode); // TODO
    //check_array_acess(rootNode); // TODO CHECK INDEX LIMITS
    check_array_size(rootNode); // TODO
    check_array_initial_values(rootNode); //TODO
    check_return(rootNode);
    check_print(rootNode);
    check_flux_control(rootNode);



    return SemanticErrors;
}

void check_and_set_declarations(AST* node) {

    if (node==0) return;

    switch (node->type) {

        case AST_LABEL:
            if (node->symbol)
                if(node->symbol->type != TK_IDENTIFIER) {
                    fprintf(stderr, "Semantic ERROR: label %s already declared \n", node->symbol->text);
                    ++SemanticErrors;
                } else{
                    node->symbol->type = SYMBOL_LABEL;
                    set_datatype(node);
                }
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
                    fprintf(stderr, "\n\nSemantic ERROR [DECLARATION]: variable [%s] already declared \n\n", node->symbol->text);
                    ++SemanticErrors;
                } else{
                    node->symbol->type = SYMBOL_VARIABLE;
                    set_datatype(node);
                }
            break;


        case AST_DECLARATION_FUNCTION_ARGS_INT:
        case AST_DECLARATION_FUNCTION_ARGS_CHAR:
        case AST_DECLARATION_FUNCTION_ARGS_FLOAT:
            if (node->symbol)
                if(node->symbol->type != TK_IDENTIFIER) {
                    fprintf(stderr, "Semantic ERROR: function args or variable name [%s] already declared \n", node->symbol->text);
                    ++SemanticErrors;
                } else{
                    node->symbol->type = SYMBOL_FUNCTION_ARGS;
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

        case AST_SYMBOL:
            set_datatype(node);
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

void check_expressions(AST* node) {
    if (node==0) return;

    switch (node->type) {

        case AST_EXPRESSION_BINARY_BOOLEAN:
            //logBinaryExpression(node);

//            if(!is_boolean(node->son[0])) {
//                fprintf(stderr, "\nSemantic ERROR: [CHECK OPERANDS]: \n invalid left operand [%s] datatype [%d] for OP[%s] \n\n", node->son[0]->symbol->text, node->son[0]->symbol->datatype, node->symbol->text);
//                ++SemanticErrors;
//            }
//            if(!is_boolean(node->son[1])) {
//                fprintf(stderr, "\nSemantic ERROR: [CHECK OPERANDS]: \n  invalid right operand [%s] datatype [%d] for OP[%s] \n\n", node->son[1]->symbol->text, node->son[1]->symbol->datatype, node->symbol->text);
//                ++SemanticErrors;
//            }
//            break;
        case AST_EXPRESSION_BINARY_ARITHMETIC:
            //logBinaryExpression(node);

            if(!is_number(node->son[0])) {
                if(node->son[0]->type == AST_EXPRESSION_BLOCK)
                    fprintf(stderr,"Semantic ERROR: [CHECK EXPRESSIONS]: Invalid left block [%s] for aritmetic expression [%s]\n", astToCode(node->son[0], 0), astToCode(node, 0));
                else
                    fprintf(stderr, "\nSemantic ERROR: [CHECK BINARY EXPRESSIONS]: invalid left operand [%s] datatype [%d] for OP[%s] \n\n", node->son[0]->symbol->text, node->son[0]->symbol->datatype, node->symbol->text);
                ++SemanticErrors;
            }
            if(!is_number(node->son[1])) {
                if(node->son[1]->type == AST_EXPRESSION_BLOCK)
                    fprintf(stderr,"Semantic ERROR: [CHECK EXPRESSIONS]: Invalid right block [%s] for aritmetic expression [%s]\n", astToCode(node->son[1], 0), astToCode(node, 0));
                else
                    fprintf(stderr, "\nSemantic ERROR: [CHECK EXPRESSIONS]: invalid right operand [%s] datatype [%d] for OP[%s] \n\n", node->son[1]->symbol->text, node->son[1]->symbol->datatype, node->symbol->text);
                ++SemanticErrors;
            }
            break;
        case AST_EXPRESSION_BLOCK:
            break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_expressions(node->son[i]);
}

void check_attibuition(AST* node){
    if (node==0) return;

    switch (node->type) {

        case AST_ATTRIBUITION:
            switch (node->symbol->type) {
                case SYMBOL_VARIABLE:
                    if(!is_number(node->son[0]) && is_boolean(node->son[0])){
                        fprintf(stderr,"Semantic ERROR: [ATTIBUITION]: Invalid assignment block [%s] \n", astToCode(node, 0));
                        ++SemanticErrors;
                    }
                    break;
                default:
                    fprintf(stderr,"Semantic ERROR: [TYPE ATTIBUITION]: Invalid assignment block [%s] \n", astToCode(node, 0));
                    ++SemanticErrors;
                    break;
            }
            break;

        case AST_ARRAY_ATTRIBUITION:

            //AST* arrEl = node->son[0];
            //AST* val = node->son[1];

            switch (node->son[0]->symbol->type) {
                case SYMBOL_VECTOR:
                    if(!is_valid_array_index(node->son[0]) || !is_number(node->son[1])){
                        fprintf(stderr,"Semantic ERROR: [ARRAY ATTIBUITION]: Invalid assignment block [%s] \n", astToCode(node, 0));
                        ++SemanticErrors;
                    }
                    break;
                default:
                    fprintf(stderr,"Semantic ERROR: [ARRAY TYPE ATTIBUITION]: Invalid assignment block [%s] \n", astToCode(node, 0));
                    ++SemanticErrors;
                    break;
            }
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

        case AST_FUNCTION_CALL:
            check_func_call_args(node);
            break;
        case AST_FUNCTION_CALL_ARGS:
            break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_function_call(node->son[i]);
}

void check_func_call_args(AST* func_call_node) {
    if (func_call_node==0) return;

    if (func_call_node->type == AST_FUNCTION_CALL) {
        int args_size = get_func_args_size(func_call_node->symbol->text, rootNode);
        if (args_size < 0) args_size = 0;

        int args_size_call = get_func_call_args_size(func_call_node);
        if (args_size_call < 0) args_size = 0;

        if (args_size != args_size_call) {
            fprintf(stderr, "\nSemantic ERROR: [CHECK FUNCTION CALL ARGS SIZE]: \n invalid number of argument function [%s] expected [%d] received [%d]\n\n", func_call_node->symbol->text,args_size, args_size_call);
            SemanticErrors += 1;
        }
    }

    return;
}

int get_func_call_args_size(AST* node) {
    if (node==0) return 0;

    int size = 0;
    AST* args_node;

    if (node->type == AST_FUNCTION_CALL) {
        if (node->son[0] != 0) {
            args_node = node->son[0];
            do {
                size += 1;
                args_node = args_node->son[1];
            } while (args_node != 0);
        }
    }
    return size;
}

int get_func_args_size(char* func_name, AST* node) {

    if (node==0) return -1;

    int size = 0;
    AST* args_node;
    AST* body_node;

    switch (node->type){
        case AST_DECLARATION_FUNCTION_INT:
        case AST_DECLARATION_FUNCTION_CHAR:
        case AST_DECLARATION_FUNCTION_FLOAT: {

            if (node->symbol->text == func_name) {
                args_node = node->son[0]; // 1200 AST_DECLARATION_FUNCTION_ARGS_OR_EMPTY
                body_node = node->son[1]; // 1300

                while (args_node && args_node->son[0] != 0) {
                    size += 1;
                    args_node = args_node->son[0];
                }

                return size;
            }
            break;
        }
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i) {
        int returned_size = get_func_args_size(func_name, node->son[i]);
        if (returned_size >= 0)
            return returned_size;
    }
}

void check_array_acess(AST* node) {
    if (node==0) return;

    switch (node->type) {
        case AST_ARRAY_ELEMENT:
            //logBinaryExpression(node);

            if(!is_valid_array_index(node->son[0])) {
                fprintf(stderr, "\nSemantic ERROR: [CHECK INDEX]: \n invalid array access index [%s] datatype [%d] for OP[%s] \n\n", node->son[0]->symbol->text, node->son[0]->symbol->datatype, node->symbol->text);
                ++SemanticErrors;
            }
            break;
        case AST_EXPRESSION_BLOCK:
            break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_array_acess(node->son[i]);
}

void check_array_size(AST* node){
    if (node==0) return;

    switch (node->type) {
        case AST_DECLARATION_GLOBAL_ARRAY_INT:
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:
            //fprintf(stderr, "\nSemantic ERROR: [CHECK ARRAY SIZE]: \n invalid array size [%s] \n\n", astToCode(node, 0));

            break;

        default:
            break;
    }


    for (int i=0; i<MAX_SONS; ++i)
        check_array_size(node->son[i]);
}

void check_array_initial_values(AST* node){
    if (node==0) return;

    switch (node->type) {
        case AST_DECLARATION_GLOBAL_ARRAY_INT:
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:
            //TODO fprintf(stderr, "\nSemantic ERROR: [CHECK ARRAY SIZE]: \n invalid array size [%s] \n\n", astToCode(node, 0));

            break;

        default:
            break;
    }


    for (int i=0; i<MAX_SONS; ++i)
        check_array_initial_values(node->son[i]);
}

int check_return_aux(AST* node, int type, int errors){
    if(node->type == AST_RETURN)
        if(!is_expression_of_type(node->son[0], type)){
            fprintf(stderr, "\nSemantic ERROR: [CHECK RETURN VALUE]: expected [%d] found [%d]\n\n", type, node->son[0]->symbol->datatype);
            ++errors;
        }

    if(node->son[0])
        errors = check_return_aux(node->son[0], type, errors);

    return errors;
}

void check_return(AST* node){
    if (node==0) return;

    switch (node->type) {
        case AST_DECLARATION_FUNCTION_INT:
        case AST_DECLARATION_FUNCTION_CHAR:
        case AST_DECLARATION_FUNCTION_FLOAT:
            // son 0 args son 1 body
            if(node->son[1])
                if(check_return_aux(node->son[1], DATATYPE_INT, 0))
                    ++SemanticErrors;

            break;
        default:
            break;
    }

    for (int i=0; i<MAX_SONS; ++i)
        check_return(node->son[i]);

}

void check_print(AST* node){
    if (node==0) return;

    switch (node->type) {
        case AST_PRINT:
            check_print(node->son[0]);
            break;
        case AST_PRINT_REST:
            if((node->son[0]->symbol->type == SYMBOL_STRING) && !(node->son[1])) {
                break; // ok só string
            }
            else if ((node->son[0]->symbol->type == SYMBOL_STRING) && node->son[1]) {
                if (node->son[1]->type == AST_PRINT_REST)
                    check_print(node->son[1]);
                else
                    check_expressions(node->son[1]);
            }
            break;
        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_print(node->son[i]);
}

void check_flux_control(AST* node){
    if (node==0) return;

    switch (node->type) {
        case AST_FLUX_CONTROLL_IF:
            if(!is_boolean(node->son[0])){
                fprintf(stderr,"Semantic ERROR: [FLUX CONTROL IF]: Invalid condition [%s] \n", astToCode(node, 0));
                ++SemanticErrors;
            }
            break;
        case AST_FLUX_CONTROLL_WHILE:
            if(!is_boolean(node->son[0])){
                fprintf(stderr,"Semantic ERROR: [FLUX CONTROL WHILE]: Invalid condition [%s] \n", astToCode(node, 0));
                ++SemanticErrors;
            }
            break;
        case AST_FLUX_CONTROLL_GOTO:
            if(!(node->symbol->type == SYMBOL_LABEL)){
                fprintf(stderr,"Semantic ERROR: [FLUX CONTROL]: Invalid label [%s] \n", astToCode(node, 0));
                ++SemanticErrors;
            }
            break;

        default:
            break;

    }

    for (int i=0; i<MAX_SONS; ++i)
        check_flux_control(node->son[i]);
}

// -------------- AUX FUNCTIONS

void set_datatype(AST* node){
    switch (node->type) {
        case AST_DECLARATION_GLOBAL_ARRAY_INT:      {
            node->symbol->datatype = DATATYPE_ARRAY_INT;
            node->symbol->datavalue = atoi(node->son[0]->symbol->text);
            break;
        }
        case AST_DECLARATION_GLOBAL_ARRAY_CHAR:     {
            node->symbol->datatype = DATATYPE_ARRAY_CHAR;
            node->symbol->datavalue = atoi(node->son[0]->symbol->text);
            break;
        }
        case AST_DECLARATION_GLOBAL_ARRAY_FLOAT:    {
            node->symbol->datatype = DATATYPE_ARRAY_FLOAT;
            node->symbol->datavalue = atoi(node->son[0]->symbol->text);
            break;
        }


        case AST_DECLARATION_GLOBAL_CHAR:           node->symbol->datatype = DATATYPE_CHAR          ; break;
        case AST_DECLARATION_GLOBAL_FLOAT:          node->symbol->datatype = DATATYPE_FLOAT         ; break; //TODO pode ser int?
        case AST_DECLARATION_GLOBAL_INT:            node->symbol->datatype = DATATYPE_INT           ; break;

        case AST_DECLARATION_FUNCTION_ARGS_INT:
        case AST_DECLARATION_FUNCTION_INT:          node->symbol->datatype = DATATYPE_INT           ; break;
        case AST_DECLARATION_FUNCTION_CHAR:         node->symbol->datatype = DATATYPE_CHAR          ; break;
        case AST_DECLARATION_FUNCTION_FLOAT:        node->symbol->datatype = DATATYPE_FLOAT         ; break;



        case AST_SYMBOL:
            //fprintf(stderr, "set_datatype AST_SYMBOL \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);

            if (node->symbol) {
                if (node->symbol->type == LIT_INTEGER) {
                    node->symbol->datatype = DATATYPE_INT;
                    node->symbol->datavalue = atoi(node->symbol->text);
                    node->symbol->type = SYMBOL_LIT_INT;
                }
                if (node->symbol->type == LIT_CHAR) {
                    node->symbol->datatype = DATATYPE_CHAR;
                    node->symbol->type = SYMBOL_LIT_CHAR;
                }
                if (node->symbol->type == LIT_STRING) {
                    node->symbol->datatype = DATATYPE_STRING;
                    node->symbol->type = SYMBOL_STRING;
                }
            } else {
                char *code = astToCode(node, 0);
                fprintf(stderr, "WARNING UNDEFINED AST_SYMBOL: \t %s \n\n", code);
            }

            //fprintf(stderr, "set_datatype AST_SYMBOL \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);
            //fprintf(stderr, "\n");

            break;

        default: break;
    }
}

void logAttribuitionExpression(AST* node){

    fprintf(stderr, "\n");

    fprintf(stderr, "ATTRIBUITION OPERATION \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);

    char* code = astToCode(node, 0);
    fprintf(stderr, "            EXPRESSION \t %s \n\n", code);

}

void logBinaryExpression(AST* node){

    if(node->symbol) {
        fprintf(stderr, "\n");

        fprintf(stderr, "BYNARY ARITHMETIC OPERATION \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->type, node->symbol->text, node->symbol->type, node->symbol->datatype);

        if(node->son[0] && node->son[0]->symbol)
            fprintf(stderr, "                  LEFT  SON \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->son[0]->type, node->son[0]->symbol->text, node->son[0]->symbol->type, node->son[0]->symbol->datatype);
        if(node->son[1] && node->son[1]->symbol)
            fprintf(stderr, "                  RIGHT SON \t node->type [%d]   \t symbol->text: %s \t symbol->type %d  \t symbol->datatype  %d  \n", node->son[1]->type, node->son[1]->symbol->text, node->son[1]->symbol->type, node->son[1]->symbol->datatype);
    }
    char* code = astToCode(node, 0);
    fprintf(stderr, "                 EXPRESSION \t %s \n\n", code);

}


int is_integer(AST* node) {
    if(node->type == AST_EXPRESSION_BLOCK && is_integer(node->son[0])
       || is_lit_of_type(node, DATATYPE_INT)
       || is_lit_of_type(node, DATATYPE_CHAR)
       || (is_arithmetic_operation(node) && is_integer(node->son[0]) && is_integer(node->son[1]))
       || is_array_of_type(node, DATATYPE_ARRAY_INT)
       || is_variable_of_type(node, DATATYPE_INT)
       || is_function_call_of_type(node, DATATYPE_INT)
            )
        return 1;
    return 0;
}

int is_valid_expression(AST* node){
    if ((node->type == AST_EXPRESSION_BLOCK && is_valid_expression(node->son[0]))

        || is_lit_of_type(node, DATATYPE_INT)
        || is_lit_of_type(node, DATATYPE_CHAR)
        || is_lit_of_type(node, DATATYPE_FLOAT)

        || is_arithmetic_operation(node)
        || is_boolean_operation(node)

        || is_array_of_type(node, DATATYPE_ARRAY_INT)
        || is_variable_of_type(node, DATATYPE_INT)
        || is_function_call_of_type(node, DATATYPE_INT)
            )
        return 1;
    return 0;
}

int is_number(AST* node) {
    if((node->type == AST_EXPRESSION_BLOCK && is_number(node->son[0]))
       || is_lit_of_type(node, DATATYPE_INT)
       || is_lit_of_type(node, DATATYPE_CHAR)
       || is_lit_of_type(node, DATATYPE_FLOAT)
       || (is_arithmetic_operation(node) && is_number(node->son[0]) && is_number(node->son[1]))
       || (is_array_of_type(node, DATATYPE_ARRAY_INT) && is_valid_array_index(node))
       || is_variable_of_type(node, DATATYPE_INT)
       || is_function_call_of_type(node, DATATYPE_INT)
            )
        return 1;
    return 0;
}
int is_boolean(AST* node) {
    if((node->type == AST_EXPRESSION_BLOCK && is_boolean(node->son[0]))
       || (is_boolean_operation(node) && is_number(node->son[0]) && is_number(node->son[1]))
            )
        return 1;
    return 0;
}

int is_arithmetic_operation(AST* node){
    if(node->symbol && (
            node->symbol->type == OPERATOR_ADD
            || node->symbol->type == OPERATOR_SUB
            || node->symbol->type == OPERATOR_MULT
            || node->symbol->type == OPERATOR_DIV)
            )
        return 1;
    return 0;
}

int is_boolean_operation(AST* node){
    if(node->symbol && (
            node->symbol->type == OPERATOR_LTE
            || node->symbol->type == OPERATOR_LT
            || node->symbol->type == OPERATOR_GTE
            || node->symbol->type == OPERATOR_GT
            || node->symbol->type == OPERATOR_EQ
            || node->symbol->type == OPERATOR_DIF)
            )
        return 1;
    return 0;
}

int is_expression_of_type_aux(AST* node, int of_type) {

    if (node == 0) return 1;

    int match_type = 0;

    switch (node->type) {

        case AST_SYMBOL:
            match_type = node->symbol->datatype == of_type;
            break;
        case AST_FUNCTION_CALL:
            match_type = node->symbol->datatype == of_type;
            break;

        case AST_ARRAY_ELEMENT:
            match_type = is_array_of_type(node, of_type);
            break;

        case AST_LT:
        case AST_LTE:
        case AST_GT:
        case AST_GTE:
        case AST_EQ:
        case AST_DIF:
        case AST_EXPRESSION_BINARY_BOOLEAN:
            match_type = ((of_type == DATATYPE_BOOL) && is_boolean_operation(node));
            break;


        case AST_ADD:
        case AST_SUB:
        case AST_MULT:
        case AST_DIV:
        case AST_EXPRESSION_BINARY_ARITHMETIC:
            match_type = is_expression_of_type_aux(node->son[0], of_type) && is_expression_of_type_aux(node->son[1], of_type);
            break;
        case AST_EXPRESSION_BLOCK:
            match_type = is_expression_of_type_aux(node->son[0], of_type);
            break;

        default:
            break;
    }

    return match_type != 0;
}

int is_expression_of_type(AST* node, int of_type){
    int is_from_type = is_expression_of_type_aux(node, of_type);
    if(!is_from_type && node->symbol)
        fprintf(stderr, "Expression of node [%s] not from type [%d] is from type [%d]\n", node->symbol->text, of_type, node->symbol->datatype);
    return is_from_type;
}

int is_valid_array_index(AST* node){
    if(node->symbol
       && node->symbol->type == SYMBOL_VECTOR
       && is_integer(node->son[0])
       && node->symbol->datavalue > node->son[0]->symbol->datavalue)
        return 1;
    return 0;
}

int is_array_of_type(AST* node, int of_type) {
    if(node->symbol
       && node->symbol->type == SYMBOL_VECTOR
       && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

int is_variable_of_type(AST* node, int of_type){
    if(node->symbol && node->symbol->type == SYMBOL_VARIABLE && node->type == AST_SYMBOL && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

int is_lit_of_type(AST* node, int of_type){
    if(node->type == AST_SYMBOL && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

int is_function_call_of_type(AST* node, int of_type){
    if(node->symbol && node->symbol->type == SYMBOL_FUNCTION && node->symbol->datatype == of_type)
        return 1;
    return 0;
}

