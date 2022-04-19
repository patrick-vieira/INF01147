#include "asm.h"

void asm_TAC_BEGINFUN(FILE* fout, TAC* tac);
void asm_TAC_ENDFUN(FILE* fout, TAC* tac);

void asm_TAC_PRINT_STRING(FILE* fout, TAC* tac);
void asm_TAC_PRINT_INT(FILE* fout, TAC* tac);
void asm_TAC_PRINT(FILE* fout, TAC* tac);

void asm_TAC_MOVE(FILE* fout, TAC* tac);

void asm_TAC_ADD(FILE* fout, TAC* tac);
void asm_TAC_SUB(FILE* fout, TAC* tac);
void asm_TAC_MULT(FILE* fout, TAC* tac);
void asm_TAC_DIV(FILE* fout, TAC* tac);

void asm_TAC_LABEL(FILE* fout, TAC* tac);

void asm_TAC_GT(FILE* fout, TAC* tac);
void asm_TAC_GTE(FILE* fout, TAC* tac);
void asm_TAC_LT(FILE* fout, TAC* tac);
void asm_TAC_LTE(FILE* fout, TAC* tac);
void asm_TAC_EQ(FILE* fout, TAC* tac);
void asm_TAC_DIF(FILE* fout, TAC* tac);

void asm_TAC_JMP(FILE* fout, TAC* tac);
void asm_TAC_JMPZ(FILE* fout, TAC* tac);
void asm_TAC_GOTO(FILE* fout, TAC* tac);

void asm_TAC_READ(FILE* fout, TAC* tac);


int BL = 0;
int CMP_LBL_TEMP = 0;


void generateAsm(TAC* first) {

    FILE *fout;
    fout = fopen("tests/out.s", "w");

    // globals
    hashPrintAsm(fout);

    // init

    fprintf(fout, "\n # PRINT"
                  "\nprint_string_int:\n"
//                  "\t.string\t\"%%d\\n\"\n"
                  "\t.string\t\"%%d\"\n"
                  "print_string:\n"
//                  "\t.string\t\"%%s\\n\"\n\n");
                  "\t.string\t\"%%s\"\n\n");

    fprintf(fout, "\n #READ"
                  "\nread:\n"
                  "\t.string\t\"%%d\""
                  "\n\n");

    // tacs

    TAC* tac;

    for (tac=first; tac; tac=tac->next) {
        switch (tac->type) {
            case TAC_BEGINFUN: asm_TAC_BEGINFUN(fout, tac); break;
            case TAC_ENDFUN: asm_TAC_ENDFUN(fout, tac); break;

            case TAC_PRINT_STRING: asm_TAC_PRINT_STRING(fout, tac); break;
            case TAC_PRINT_INT: asm_TAC_PRINT_INT(fout, tac); break;
            case TAC_PRINT: asm_TAC_PRINT(fout, tac); break;

            case TAC_MOVE: asm_TAC_MOVE(fout, tac); break;

            case TAC_ADD: asm_TAC_ADD(fout, tac); break;
            case TAC_SUB: asm_TAC_SUB(fout, tac); break;
            case TAC_MULT: asm_TAC_MULT(fout, tac); break;
            case TAC_DIV: asm_TAC_DIV(fout, tac); break;

            case TAC_LABEL: asm_TAC_LABEL(fout, tac); break;

            case TAC_GT: asm_TAC_GT(fout, tac); break;
            case TAC_GTE: asm_TAC_GTE(fout, tac); break;
            case TAC_LT: asm_TAC_LT(fout, tac); break;
            case TAC_LTE: asm_TAC_LTE(fout, tac); break;
            case TAC_EQ: asm_TAC_EQ(fout, tac); break;
            case TAC_DIF: asm_TAC_DIF(fout, tac); break;

            case TAC_JMP: asm_TAC_JMP(fout, tac); break;
            case TAC_JMPZ: asm_TAC_JMPZ(fout, tac); break;

            case TAC_GOTO: asm_TAC_GOTO(fout, tac); break;

            case TAC_READ: asm_TAC_READ(fout, tac); break;


            default:
                break;

        }
    }

    // hash table
}


void asm_TAC_BEGINFUN(FILE* fout, TAC* tac) {
    fprintf(fout, "\n\n# TAC_BEGINFUN\n"
                  "\t.text\n"
                  "\t.globl\t%s\n"
                  "%s:\n"
                  "\tpushq\t%%rbp\n"
                  "\tmovq\t%%rsp, %%rbp\n\n", tac->res->text, tac->res->text);
}

void asm_TAC_ENDFUN(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n## TAC_ENDFUN\n"
                  "\tpopq\t%%rbp\n"
                  "\tret\n\n");
}

void asm_TAC_PRINT_STRING(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_PRINT_STRING \n"
                  "    leaq\t_%s(%%rip), %%rdi\n"
                  "    movl\t$0, %%eax\n"
                  "    call\tprintf@PLT\n"
                  "    movl\t$0, %%eax\n\n", tac->res->text);
}
void asm_TAC_PRINT_INT(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_PRINT_INT \n"
                  "    movl\t_%s(%%rip), %%esi   # mov a to reg\n"
                  "    #movl\t%%eax, %%esi\n"
                  "    leaq\tprint_string_int(%%rip), %%rdi\n"
                  "\tcall\tprintf@PLT\n\n", tac->res->text);
}
void asm_TAC_PRINT(FILE* fout, TAC* tac){
    // ignore, all in tac_print_string and tac_print_int
}

void asm_TAC_MOVE(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_MOVE //ASSIGN \n"
                  "    movl\t_%s(%%rip), %%eax\n"
                  "    movl\t%%eax, _%s(%%rip)\n"
                  "    movl\t$0, %%eax\n"  // limpa reg
                  "\n\n", tac->op1->text, tac->res->text);
}


void asm_TAC_ADD(FILE* fout, TAC* tac){

    /*
        movl	a(%rip), %edx
        movl	b(%rip), %eax
        addl	%edx, %eax
        movl	%eax, a(%rip)
        movl	$0, %eax // limpa reg
     */

    fprintf(fout, "\n\n# TAC_ADD \n"
                  "    movl\t_%s(%%rip), %%edx\n"
                  "    movl\t_%s(%%rip), %%eax\n"
                  "    addl\t%%edx, %%eax\n"
                  "    movl\t%%eax, _%s(%%rip)\n"
                  "    movl\t$0, %%eax\n"  // limpa reg
                  "\n\n", tac->op1->text, tac->op2->text, tac->res->text);
}

void asm_TAC_SUB(FILE* fout, TAC* tac){

    /*
        movl	a(%rip), %edx
        movl	b(%rip), %eax
        subl	%eax, %edx
        movl	%edx, %eax
        movl	%eax, a(%rip)
        movl	$0, %eax // limpa reg

     */

    fprintf(fout, "\n\n# TAC_SUB \n"
                  "    movl\t_%s(%%rip), %%edx\n"
                  "    movl\t_%s(%%rip), %%eax\n"
                  "    subl\t%%eax, %%edx\n"
                  "    movl\t%%edx, %%eax\n"
                  "    movl\t%%eax, _%s(%%rip)\n"
                  "    movl\t$0, %%eax\n"  // limpa reg
                  "\n\n", tac->op1->text, tac->op2->text, tac->res->text);
}

void asm_TAC_MULT(FILE* fout, TAC* tac){

    /*
        movl	a(%rip), %edx
        movl	b(%rip), %eax
        imull	%edx, %eax
        movl	%eax, a(%rip)
        movl	$0, %eax
     */
    fprintf(fout, "\n\n# TAC_MULT \n"
                  "    movl\t_%s(%%rip), %%edx\n"
                  "    movl\t_%s(%%rip), %%eax\n"
                  "    imull\t%%edx, %%eax\n"
                  "    movl\t%%eax, _%s(%%rip)\n"
                  "    movl\t$0, %%eax\n"  // limpa reg
                  "\n\n", tac->op1->text, tac->op2->text, tac->res->text);
}

void asm_TAC_DIV(FILE* fout, TAC* tac){
/*
    movl	a(%rip), %eax
    movl	b(%rip), %ecx
            cltd
    idivl	%ecx
    movl	%eax, a(%rip)
    movl	$0, %eax
*/
    fprintf(fout, "\n\n# TAC_DIV\n"
                  "    movl\t_%s(%%rip), %%eax\n"
                  "    movl\t_%s(%%rip), %%ecx\n"
                  "            cltd\n"
                  "    idivl\t%%ecx\n"
                  "    movl\t%%eax, _%s(%%rip)\n"
                  "    movl\t$0, %%eax\n\n"  // limpa reg
                  "\n\n", tac->op1->text, tac->op2->text, tac->res->text);
}


void asm_TAC_LABEL(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_LABEL\n"
                  "    _%s:\t# %s"
                  "\n\n", tac->res->text, tac->res->datastring?tac->res->datastring:"AUTO");
}

void asm_TAC_GT(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_GT \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tjg\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
                   "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
                   "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}
void asm_TAC_GTE(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_GTE \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tjge\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
            "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
            "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}
void asm_TAC_LT(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_LT \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tjl\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
            "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
            "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}
void asm_TAC_LTE(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_LTE \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tjle\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
            "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
            "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}
void asm_TAC_EQ(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_EQ \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tje\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
            "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
            "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}
void asm_TAC_DIF(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_DIF \n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t_%s(%%rip), %%eax\n"
                  "\tcmpl\t%%eax, %%edx \n", tac->op1->text, tac->op2->text);

    fprintf(fout,
            "\tjne\tCMP_LBL_TEMP_%d \t\t# se condição verdadeira pula para setar 1\n "
            "\tmovl\t$0, _%s(%%rip) \t\t# Se falsa seta 0 \n"
            "\tjmp\tCMP_LBL_TEMP_%d \t\t# e pula para o final do bloco\n"
            , CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    fprintf(fout, "\nCMP_LBL_TEMP_%d: \t\t #se condição verdadeira seta 1\n"
                  "\tmovl\t$1, _%s(%%rip)\n"
                  "\nCMP_LBL_TEMP_%d:\t#final do bloco"
                  "\n\n", CMP_LBL_TEMP, tac->res->text, CMP_LBL_TEMP+1);

    CMP_LBL_TEMP += 2;
}


void asm_TAC_JMP(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_JMP\n"
                  "\tjmp\t_%s"
                  "\n\n", tac->res->text);

}

void asm_TAC_JMPZ(FILE* fout, TAC* tac){
    // compara o temp
    fprintf(fout, "\n\n# TAC_JMPZ\n"
                  "\tmovl\t_%s(%%rip), %%edx\n"
                  "\tmovl\t$0, %%eax\n"
                  "\tcmpl\t%%eax, %%edx \t# Se condicional anterior for 0 pula o trecho a baixo\n"
                  "    jz _%s\n", tac->op1->text, tac->res->text);

}

void asm_TAC_GOTO(FILE* fout, TAC* tac){
    fprintf(fout, "\n\n# TAC_GOTO\n"
                  "\tjmp\t_%s \t# alias for label [%s]"
                  "\n\n", tac->res->text, tac->res->datastring);

}

void asm_TAC_READ(FILE* fout, TAC* tac){
    // compara o temp
    fprintf(fout, "\n\n# TAC_READ\n"
                  "\tleaq\t_%s(%%rip), %%rsi\n"
                  "\tleaq\tread(%%rip), %%rdi\n"
                  "\tmovl\t$0, %%eax\n"
                  "\tcall\t__isoc99_scanf@PLT", tac->res->text);
}
