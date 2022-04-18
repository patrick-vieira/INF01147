

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"



int SemanticErrors;
AST* rootNode;

int get_semantic_errors(AST* node);

void check_and_set_declarations(AST* node);
void check_undeclared(); // percorre a hash

void check_expressions(AST* node);
void check_attibuition(AST* node);
void check_function_call(AST* node);
void check_array_acess(AST* node);
void check_array_size(AST* node);
void check_array_initial_values(AST* node);
void check_return(AST* node);
void check_print(AST* node);
void check_flux_control(AST* node);

// ---------- AUX FUNCTIONS
void set_datatype(AST* node);
void logAttribuitionExpression(AST* node);
void logBinaryExpression(AST* node);

int is_number(AST* node);
int is_boolean(AST* node);
int is_arithmetic_operation(AST* node);
int is_boolean_operation(AST* node);
int is_expression_of_type_aux(AST* node, int of_type);
int is_expression_of_type(AST* node, int of_type);
int is_valid_array_index(AST* node);
int is_array_of_type(AST* node, int of_type);
int is_variable_of_type(AST* node, int of_type);
int is_lit_of_type(AST* node, int of_type);
int is_function_call_of_type(AST* node, int of_type);
int check_return_aux(AST* node, int type, int errors);

void check_func_call_args(AST* func_call_node);

int get_func_args_size(char* func_name, AST* rootNode);
int get_func_call_args_size(AST* func_call_node);

#endif

// END OF FILE