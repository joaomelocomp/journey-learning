#include <stdio.h>

int frequencia (int *vetor, int tamanho) {
    int salvar = 0;
    int f = vetor[0];
    for (int i = 0; i < tamanho; i++) {
        int contador = 0;
        for (int j = 0; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) contador++;
        }
        if (salvar < contador) {
            salvar = contador;
            f = vetor[i];
        }
    }
    printf("O número %d apareceu %d vezes ", f, salvar);
}

int main () {
    int vetor[] = {4, 2, 4, 7, 2, 4, 9, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    frequencia(vetor, tamanho);

    return 0;
}