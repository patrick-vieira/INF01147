#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "ast.h"
#include "tacs.h"
#include "semantic.h"
#include "asm.h"

extern FILE *yyin;

int yyparse(void);

int getLineNumber(void);

AST *getRootNode(void);
int getErrorCount(void);


int main(int argc, char **argv) {

    // se existe um arquivo lê ele
    // se não lê do console;
    hashInit();

    if (argc < 2) {
        fprintf(stderr, "missing file argument.");
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    if (yyin == 0) {
        fprintf(stderr, "Cannot open file %s.\n", argv[1]);
        exit(2);
    }

    int i = yyparse();
    int semantic_error_count = getErrorCount();

    if(semantic_error_count != 0) {
        fprintf(stderr, "Semantic errors found: %d.\n", semantic_error_count);
        exit(3);
    }

    AST *rootNode = getRootNode();
    int semanticErrors = get_semantic_errors(rootNode);

    // TACS
    //astPrint(rootNode, 0);
    TAC* code = tacGenerateCode(rootNode);

    //fprintf(stderr, "\nhash after tacGenerateCode\n\n");
    //hashPrint();
    //fprintf(stderr, "\n\n");

    //tacPrintBackwards(code);
    generateAsm(tacReverseTAC(code), argv[1]);

    if (semanticErrors > 0) {
        printf("\n\nCompilation Fail! Semantic errors count %d\n", semanticErrors);
        exit(4);
    }


    //hashPrint();

    if (argc > 2) {  //write output
        FILE *fp;

        char *code = astToCode(rootNode, 0);
        fp = fopen(argv[2], "w+");
        fputs(code, fp);
        // fprintf(stderr, "%s \n", code); //print code output.txt

        fclose(fp);
    }


    printf("Numero de linhas: %d.\n", getLineNumber());
    printf("Compilation Success.\n\n Output Program: \n\n");

    exit(0);
}