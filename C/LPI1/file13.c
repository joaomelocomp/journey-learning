/*13) Dados três vetores com 10 posições cada um, preenchidos com números inteiros, fazer um programa
em C que, após a leitura dos vetores coloque-os em ordem crescente.*/

#include <stdio.h>

int main () {

    int A[10];
    int B[10];
    int C[10];
    int vetor[30];

    for (int i = 0; i < 10; i++) {
        printf("Digite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("Digite B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("Digite C[%d]: ", i);
        scanf("%d", &C[i]);
    }

    for (int i = 0; i < 10; i++) {
        vetor[i] = A[i];
        vetor[i + 10] = B[i];
        vetor[i + 20] = C[i];
    }

    for (int i = 0; i < 30; i++) {

        for (int j = i + 1; j < 30; j++) {

            if (vetor[i] > vetor[j]) {

                int auxiliar = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = auxiliar;
            }
        }
    }

    printf("\nVetor em ordem crescente:\n");

    for (int i = 0; i < 30; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}