/*21) Os números romanos são um sistema de numeração. A tabela de símbolos utilizados por ele está
ilustrada a seguir :
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
Escreva um programa em C que converta um número decimal para o sistema romano de numeração.*/

#include <stdio.h>

int main () {

    int numero;

    int valores[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    char *romanos[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("Numero romano: ");

    for (int i = 0; i < 13; i++) {

        while (numero >= valores[i]) {

            printf("%s", romanos[i]);

            numero -= valores[i];
        }
    }

    return 0;
}