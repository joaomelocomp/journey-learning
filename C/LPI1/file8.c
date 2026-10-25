/*8)Para um vetor A de 50 números inteiros, escrever um programa em C que determine o maior e o segundo
maior elemento desse vetor. Assumir que todos os elementos são distintos. */

#include <stdio.h>

int main() {
    int A[50];

    for (int i = 0; i < 50; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    int maior = A[0];
    int segundoMaior = A[1];

    if (segundoMaior > maior) {
        int auxiliar = maior;
        maior = segundoMaior;
        segundoMaior = auxiliar;
    }

    for (int i = 2; i < 50; i++) {
        if (A[i] > maior) {
            segundoMaior = maior;
            maior = A[i];
        } else if (A[i] > segundoMaior) {
            segundoMaior = A[i];
        }
    }

    printf("Maior: %d\n", maior);
    printf("Segundo maior: %d\n", segundoMaior);

    return 0;
}