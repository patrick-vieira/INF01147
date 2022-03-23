#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "ast.h"
#include "semantic.h"

extern FILE *yyin;
int yyparse(void);
int getLineNumber(void);  
AST* getRootNode(void);  
void check_and_set_declarations(AST*);  


int main(int argc, char** argv) {
  
  // se existe um arquivo lê ele
  // se não lê do console;
  hashInit();
  
  if (argc < 2) { 
    fprintf(stderr, "missing file argument.");
    exit(1);
  }

  yyin = fopen(argv[1], "r");

  if (yyin == 0 ) {
    fprintf(stderr, "Cannot open file %s.\n", argv[1]);
    exit(2);
  }
  
  int i = yyparse();    
  
  AST* rootNode = getRootNode();
  char* code = astToCode(rootNode, 0);

  
  fprintf(stderr, "\n\nhash before Semantics\n\n");
  hashPrint();

  fprintf(stderr, "Semantics start \n\n");
  check_and_set_declarations(rootNode);      

  fprintf(stderr, "\nhash after Semantics\n\n");    
  hashPrint();

  check_undeclared();
  check_operands(rootNode);
    
  if (argc > 2) {  //write output
    FILE *fp;

    fp = fopen(argv[2], "w+");
    fputs(code, fp);
    // fprintf(stderr, "%s \n", code); //print code output.txt
   
    fclose(fp);
  }  
  
  if(get_semantic_errors() > 0) 
    printf("Compilation Fail. Semantic errors count %d\n", get_semantic_errors());      
    exit(4);
  
  printf("Numero de linhas: %d.\n", getLineNumber());    
  printf("Compilation Success.\n");    
  
  exit(0);
}