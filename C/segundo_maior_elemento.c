#include <stdio.h>

int encontraSegundo (int *vetor, int tamanhoVetor) {
    int maior = vetor[0];
    int segundoMaior = 0;
    for (int i = 0; i < tamanhoVetor; i++) {
        if (vetor[i] > maior) {
            segundoMaior = maior;
            maior = vetor[i];
        }
    }
    return segundoMaior;
}
int main () {
    int vetor[5] = {10, 37, 9, 52, 150};
    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    int teste = 0;
    teste = encontraSegundo(vetor, tamanhoVetor);
    printf("%d", teste);

    return 0;
}