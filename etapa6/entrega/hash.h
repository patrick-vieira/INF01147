/***
**** UFRGS - INF01147 - COMPILADORES - TURMA B - Marcelo Johann - 2021/2 - Etapa 1
***/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commons.h"

#ifndef HASH_HEADER
#define HASH_HEADER


#define HASH_SIZE 997

#define DATATYPE_UNDEFINED       0
#define DATATYPE_INT             1
#define DATATYPE_CHAR            2
#define DATATYPE_FLOAT           3
#define DATATYPE_BOOL            4
#define DATATYPE_STRING          5
#define DATATYPE_LABEL           6

#define DATATYPE_ARRAY_INT       10
#define DATATYPE_ARRAY_CHAR      11
#define DATATYPE_ARRAY_FLOAT     12

#define  SYMBOL_VARIABLE            258
#define  SYMBOL_FUNCTION            259
#define  SYMBOL_FUNCTION_ARGS       260
#define  SYMBOL_VECTOR              261

#define  SYMBOL_LIT_INT             262
#define  SYMBOL_LIT_CHAR            263
#define  SYMBOL_STRING              264
#define  SYMBOL_LABEL               265
#define  SYMBOL_RETURN              266

#define  SYMBOL_EXPRESSION_BLOCK    267

#define SYMBOL_TEMP                 1607

typedef struct hash_node {
    int type;
    int datatype;
    int datavalue;
    char* datastring;
    char *text;
    struct hash_node * next;
} HASH_NODE;


static int serialTempVar = 0;
static int serialTempLabel = 0;


void hashInit(void);
int hashAddress(char *text);

HASH_NODE *hashFind(char *text);
HASH_NODE *hashFindLabel(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint(void);
HASH_NODE *getFirstNode();
HASH_NODE *getNode(int i);

HASH_NODE* makeTemp();
HASH_NODE* makeLabel();

void hashPrintAsm(FILE* fout);

#endif