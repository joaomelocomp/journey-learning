/*5) O troco em moedas é uma combinação de moedas com os seguintes valores :
R$ 1,00 ; 0,50; 0,25; 0,10; 0,05; 0,01
Escreva um programa em C que leia qualquer valor em centavos (R$0,01 até R$1,00). Calcule e imprima
seu equivalente em moedas. Encontre a solução que utilize o menor número possível de moedas.*/

#include <stdio.h>

int main () {

    int valor;

    int moeda1 = 0;
    int moeda50 = 0;
    int moeda25 = 0;
    int moeda10 = 0;
    int moeda5 = 0;
    int moeda1centavo = 0;

    printf("Digite o valor em centavos: ");
    scanf("%d", &valor);

    moeda1 = valor / 100;
    valor = valor % 100;

    moeda50 = valor / 50;
    valor = valor % 50;

    moeda25 = valor / 25;
    valor = valor % 25;

    moeda10 = valor / 10;
    valor = valor % 10;

    moeda5 = valor / 5;
    valor = valor % 5;

    moeda1centavo = valor;

    printf("\nMoedas utilizadas:\n");

    printf("R$ 1,00: %d\n", moeda1);
    printf("R$ 0,50: %d\n", moeda50);
    printf("R$ 0,25: %d\n", moeda25);
    printf("R$ 0,10: %d\n", moeda10);
    printf("R$ 0,05: %d\n", moeda5);
    printf("R$ 0,01: %d\n", moeda1centavo);

    return 0;
}