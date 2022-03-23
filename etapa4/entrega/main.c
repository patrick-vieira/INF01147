#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "ast.h"

extern FILE *yyin;
int yyparse(void);
int getLineNumber(void);  
AST* getRootNode(void);  


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
  
  if (argc > 2) {
    AST* rootNode = getRootNode();
    astPrint(rootNode, 0);
    char* code = astToCode(rootNode, 0);

    FILE *fp;

    fp = fopen(argv[2], "w+");
    fputs(code, fp);
    //fprintf(fp, "%s \n", code);
    fprintf(stderr, "%s \n", code);
   
    fclose(fp);
    

    
    //unparse(argv[2]); 
  }  

  //astToCode(rootNode, fopen(argv[1], "w"));

  hashPrint();
  
  
  printf("Numero de linhas: %d.\n", getLineNumber());    
  printf("Compilation Success.\n");    
  
  exit(0);
}