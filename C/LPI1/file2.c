/*2) Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou
não primo. */

#include <stdio.h>

void primo (int inteiro) {
    int contador = 1;
    for (int i = 2; i <= inteiro; i++) {
        if (inteiro % i == 0) contador++;
    }
    if (contador == 2) {
        printf("é primo");
    } else {
        printf("não é primo");
    }
}

int main () {
    int numero = 0;
    scanf("%d", &numero);
    primo(numero);
    return 0;
}