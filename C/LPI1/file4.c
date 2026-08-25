/*4) Escreva um programa em C que calcule o fatorial de um número inteiro positivo. */

#include <stdio.h>

int fatorial (int numero) {
    if (numero < 0) {
        printf("ERR0R");
        return -1;
    }

    int calculo = 1;

    for (int i = 1; i <= numero; i++) {
        calculo = calculo * i;
    }

    return calculo; 
}

int main () {
    int numero = 0;
    scanf("%d", &numero);

    printf("%d", fatorial(numero));

    return 0;
}