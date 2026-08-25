/*3) Um inteiro perfeito n é igual a soma de todos os seus divisores próprios. A faixa de seus divisores próprios
vai de 1 a (n-1). Por exemplo : 6 é um inteiro perfeito; a soma de todos os seus divisores próprios ( 1 + 2 +
3) é igual a 6. Escreva um programa em C que determine se um número no intervalo de 1 a 32767 é um
inteiro perfeito.*/

#include <stdio.h>

void inteiroPerfeito (int numero) {
    int junto = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) junto += i;
    }
    if (junto == numero) {
        printf("inteiro perfeito");
    } else {
        printf("não é inteiro perfeito");
    }
}

int main () { //oi
    int numero = 0;

    scanf("%d", &numero);
    while (numero > 1 && numero < 32767) {
        inteiroPerfeito(numero);

        scanf("%d", &numero);
    }
    return 0;
}