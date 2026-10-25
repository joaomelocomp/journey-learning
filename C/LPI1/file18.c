/*18) Faça um programa em C se imprima os N primeiros números que sejam primos e façam
parte da série de Fibonacci.*/

#include <stdio.h>

int primo(int numero) {

    int contador = 0;

    for (int i = 1; i <= numero; i++) {

        if (numero % i == 0) {
            contador++;
        }
    }

    if (contador == 2) {
        return 1;
    }

    return 0;
}

int main () {

    int N;
    int quantidade = 0;

    int anterior = 0;
    int atual = 1;

    printf("Digite N: ");
    scanf("%d", &N);

    printf("Numeros primos de Fibonacci:\n");

    while (quantidade < N) {

        if (primo(anterior)) {
            printf("%d ", anterior);
            quantidade++;
        }

        int proximo = anterior + atual;

        anterior = atual;
        atual = proximo;
    }

    return 0;
}