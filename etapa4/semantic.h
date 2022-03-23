

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

int SemanticErrors;
void check_and_set_literals(AST* node);
void check_and_set_declarations(AST* node);
void check_undeclared(); // percorre a hash
void check_operands(AST* node);
void check_attibuition(AST* node);
int get_semantic_errors();
#endif

// END OF FILE