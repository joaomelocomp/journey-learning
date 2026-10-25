/*23) Fazer um programa em C que leia um número e imprima se ele é ou não um número triangular. Um
número triangular é aquele que é o produto de três números consecutivos. Por exemplo: 24 = 2 * 3 * 4.*/

#include <stdio.h>

int main () {

    int numero;
    int encontrado = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (int i = 1; i < numero; i++) {

        if (i * (i + 1) * (i + 2) == numero) {
            encontrado = 1;
        }
    }

    if (encontrado == 1) {
        printf("E um numero triangular");
    } else {
        printf("Nao e um numero triangular");
    }

    return 0;
}