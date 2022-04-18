#include <stdio.h>

// criar assembly
// gcc t1.c -S
// compilar
// gcc t1.s

// gcc t1.c -S && gcc t1.s && ./a.out

int a = 1;
int b = 2;
int c = 1111;
int d = 2222;

int main() {

    printf("%d maior q %d e %d e %d e %d e %d  \n", a, b, a, b,a, b);

    /*scanf("%d", &a);

    if(a > b) {
        printf("%d maior q %d\n", a, b);
    } else {
        printf("%d menor q %d\n", a, b);
    }*/
}