/*Soma de 1 a n [O(n)]
1
Escreva uma função que receba como entrada um número n 
e retorne a soma dos números 1 a n. [O(n)]*/

#include<stdio.h>

int somar(int n) {
    int soma = 0;
    for (int i = 0; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int numero = 3;
    int resultado = 0;
    resultado = somar(numero);
    printf("%d", resultado);

    return 0;
}