/***
**** UFRGS - INF01147 - COMPILADORES - TURMA B - Marcelo Johann - 2021/2 - Etapa 1
***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef HASH_HEADER
#define HASH_HEADER


#define HASH_SIZE 997

typedef struct hash_node {
    int type;
    char *text;
    struct hash_node * next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);

HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type);
void hashPrint(void);


#endif