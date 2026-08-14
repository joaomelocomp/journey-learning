/*Dado um vetor, mostre apenas os elementos que aparecem exatamente uma vez.*/
#include <stdio.h>

void twice (int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int contador = 0;
        for (int j = 0; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) contador++;
        }
        if (contador == 1) {
            printf("%d", vetor[i]);
        }
        }
    }

int main () {
    int vetor[] = {2, 3, 2, 5, 7, 3, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    twice(vetor, tamanho);

    return 0;
}