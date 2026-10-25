/*24) Faça um programa em C que:
a) Leia a idade de várias pessoas. O final da lista contém o valor da idade igual a -1 que deverá ser
computado.
b) Calcule e mostre a idade média desse grupo de indivíduos. Escreva também a porcentagem de
pessoas entre 21 e 65 anos inclusive.*/

#include <stdio.h>

int main () {

    int idade;
    int soma = 0;
    int quantidade = 0;
    int entre21e65 = 0;

    printf("Digite uma idade (-1 para terminar): ");
    scanf("%d", &idade);

    while (idade != -1) {

        soma += idade;
        quantidade++;

        if (idade >= 21 && idade <= 65) {
            entre21e65++;
        }

        printf("Digite uma idade (-1 para terminar): ");
        scanf("%d", &idade);
    }

    if (quantidade > 0) {

        printf("\nIdade media: %.2f\n",
               (soma * 1.0) / quantidade);

        printf("Porcentagem entre 21 e 65 anos: %.2f%%\n",
               (entre21e65 * 100.0) / quantidade);
    }

    return 0;
}