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
HASH_NODE *hashFindLabel(char *text) {
    HASH_NODE *node;
    int address = hashAddress(text);

    for (node=Table[address]; node; node = node->next) {
        if (node->datastring && strcmp(node->datastring, text) == 0) {
            return node;
        }
    }

    return 0;
}
//TODO add line??
HASH_NODE *hashInsert(char *text, int type) {
    HASH_NODE *newnode;

    text = dash_replace(text);

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
            printf("Table[%d] \t has %s    \t type %d    \t datatype %d \t datavalue %d \t datastring %s \n", i, node->text, node->type, node->datatype, node->datavalue, node->datastring);
        }
    }
}

HASH_NODE* makeTemp(){

    char buffer[256] = "";

    sprintf(buffer, "_TMP_VAR_%d", serialTempVar++);

    return hashInsert(buffer, SYMBOL_TEMP);
}

HASH_NODE* makeLabel(){

    char buffer[256] = "";

    sprintf(buffer, "_TMP_LABEL_%d", serialTempLabel++);

    return hashInsert(buffer, SYMBOL_LABEL);
}


void hashPrintAsm(FILE* fout) {
    int i;
    HASH_NODE *node;

    fprintf(fout, "\t.data\n");

    for (i=0; i<HASH_SIZE; i++){
        for (node=Table[i]; node; node=node->next) {
//            printf("Table[%d] \t has %s    \t type %d    \t datatype %d \n", i, node->text, node->type, node->datatype);
            if(node->type == SYMBOL_LIT_INT)
                fprintf(fout, "_%s: .long\t%d\n", node->text, node->datavalue);
            if(node->type == SYMBOL_LIT_CHAR)
                fprintf(fout, "_char_%c: .long\t%s\n", node->datachar, node->text);
//            if(node->type == SYMBOL_STRING)
//                fprintf(fout, "_%s: .string\t\"%s\"\n", node->text, node->text);
//            if(node->type == SYMBOL_VARIABLE)
//                fprintf(fout, "_%s: .long\t%d\n", node->text, node->datavalue);

            if(node->type == SYMBOL_FUNCTION_ARGS || node->type == SYMBOL_VARIABLE){
                if(node->datatype == DATATYPE_CHAR)
                    fprintf(fout, "_%s: .long\t%d\n", node->text, node->datavalue);

                if(node->datatype == DATATYPE_FLOAT)
                    fprintf(fout, "_%s: "
                                  "\t.long\t%d\n"
                                  "\t.long\t%s\n", node->text, node->datavalue,  node->datastring[0]?node->datastring:"0");

                if(node->datatype == DATATYPE_INT)
                    fprintf(fout, "_%s: .long\t%d\n", node->text, node->datavalue);
            }


            if(node->type == SYMBOL_TEMP) {
                if(node->datatype == DATATYPE_STRING)
                    fprintf(fout, "_%s: .string\t\"%s\"\n", node->text, dash_replace_back(node->datastring));

                if(node->datatype != DATATYPE_STRING)
                    fprintf(fout, "_%s: .long\t%d\n", node->text, node->datavalue);
            }
        }
    }
    //for (i=0; i<serialTempVar; i++){
      //  fprintf(fout, "__TMP_VAR_%d: .long\t%d\n", i, 0);
    //}
//    for (i=0; i<serialTempLabel; i++){
//        fprintf(fout, "__TMP_LABEL_%d: .long\t%d\n", i, 0);
//    }
}
