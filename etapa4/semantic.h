

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"


#define DATATYPE_UNDEFINED       0
#define DATATYPE_INT             1
#define DATATYPE_CHAR            2
#define DATATYPE_FLOAT           3

#define DATATYPE_ARRAY_INT       10
#define DATATYPE_ARRAY_CHAR      11
#define DATATYPE_ARRAY_FLOAT     12

int SemanticErrors;
int get_semantic_errors();

void check_and_set_declarations(AST* node);
void check_undeclared(); // percorre a hash
void check_operands(AST* node);
void check_attibuition(AST* node);
void check_function_call(AST* node);

// ---------- AUX FUNCTIONS
void set_datatype(AST* node);
void logBinaryExpression(AST* node);

int is_number(AST* node);
int is_arithmetic(AST* node);
int is_expression_of_type_aux(AST* node, int of_type);
int is_expression_of_type(AST* node, int of_type);
int is_valid_array_index(AST* node);
int is_array_index_of_type(AST* node, int of_type);
int is_variable_of_type(AST* node, int of_type);
int is_lit_of_type(AST* node, int of_type);
int is_function_call_of_type(AST* node, int of_type);


#endif

// END OF FILE