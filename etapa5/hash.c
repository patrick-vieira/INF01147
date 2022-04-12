/***
**** UFRGS - INF01147 - COMPILADORES - TURMA B - Marcelo Johann - 2021/2 - Etapa 1
***/
#include "hash.h"

HASH_NODE *Table[HASH_SIZE];
int first_node = -1;

HASH_NODE* getFirstNode() {
    HASH_NODE* first; 
    // first = Table[first_node];
    first = Table[0];

    return first;
}

HASH_NODE* getNode(int i) {
    HASH_NODE* node; 
    // first = Table[first_node];
    node = Table[i];

    return node;
}

void hashInit(void){
    int i;
    for(i=0; i<HASH_SIZE; i++) {
        Table[i] = 0;
    }
}

int hashAddress(char *text) {
    int address = 1;
    int i;

    for (i=0; i<strlen(text); i++) {
        address = (address * text[i]) % HASH_SIZE + 1;        
    }

    return address-1;    
}

HASH_NODE *hashFind(char *text) {
    HASH_NODE *node;
    int address = hashAddress(text);

    for (node=Table[address]; node; node = node->next) {
        if (strcmp(node->text, text) == 0) {
            return node;
        }
    }

    return 0;
}
//TODO add line??
HASH_NODE *hashInsert(char *text, int type) {
    HASH_NODE *newnode;
    int address = hashAddress(text);
    
    if(first_node < 0)
        first_node = address;

    if ((newnode=hashFind(text)) != 0) {
        return newnode;
    }

    newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newnode->type = type;
    newnode->text = (char*) calloc(strlen(text)+1, sizeof(char));
    strcpy(newnode->text, text);

    newnode->next = Table[address];
    Table[address] = newnode;

    return newnode;
}

void hashPrint(void) {
    int i;
    HASH_NODE *node;

    for (i=0; i<HASH_SIZE; i++){
        for (node=Table[i]; node; node=node->next) {
            printf("Table[%d] \t has %s    \t type %d    \t datatype %d \n", i, node->text, node->type, node->datatype);
        }
    }
}

HASH_NODE* makeTemp(){
    static int serial = 0;

    char buffer[256] = "";

    sprintf(buffer, "_TMP-VAR_[%d]", serial++);

    return hashInsert(buffer, SYMBOL_TEMP);
}

HASH_NODE* makeLabel(){
    static int serial = 0;

    char buffer[256] = "";

    sprintf(buffer, "__LABEL[%d]", serial++);

    return hashInsert(buffer, SYMBOL_LABEL);
}
