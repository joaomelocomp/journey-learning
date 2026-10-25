/*25) Crie um programa em C que simule um caixa eletrônico que lê a quantidade de dinheiro a ser sacado e
imprime a menor quantidade de notas a ser dada ao usuário. Sua máquina de saque eletrônico é
carregada com 100 notas de 200, 100, 50, 20, 10, 5 cada. Imprimir também a quantidade de cada nota
a ser dada ao usuário. Lembre-se que você tem uma quantidade finita de cada tipo de nota. O final da
leitura é marcado pelo valor 0 que não deve ser calculado. Exemplo: 95 = uma nota de 50, duas notas de
20, uma nota de 5. Perceba que a cada saque há uma quantidade menor de cada tipo de notas. Outra
situação é quando não é possível sacar o dinheiro com a quantidade e valores de notas existentes.
Neste caso, o programa deve cancelar a operação e informar o usuário que não é possível realizar o
saque.*/

#include <stdio.h>

int main () {

    int notas200 = 100;
    int notas100 = 100;
    int notas50 = 100;
    int notas20 = 100;
    int notas10 = 100;
    int notas5 = 100;

    int saque;

    while (1) {

        printf("\nDigite o valor do saque (0 para terminar): ");
        scanf("%d", &saque);

        if (saque == 0) {
            break;
        }

        int restante = saque;

        int usada200 = 0;
        int usada100 = 0;
        int usada50 = 0;
        int usada20 = 0;
        int usada10 = 0;
        int usada5 = 0;

        int quantidade;

        quantidade = restante / 200;

        if (quantidade > notas200) {
            quantidade = notas200;
        }

        usada200 = quantidade;
        restante -= quantidade * 200;

        quantidade = restante / 100;

        if (quantidade > notas100) {
            quantidade = notas100;
        }

        usada100 = quantidade;
        restante -= quantidade * 100;

        quantidade = restante / 50;

        if (quantidade > notas50) {
            quantidade = notas50;
        }

        usada50 = quantidade;
        restante -= quantidade * 50;

        quantidade = restante / 20;

        if (quantidade > notas20) {
            quantidade = notas20;
        }

        usada20 = quantidade;
        restante -= quantidade * 20;

        quantidade = restante / 10;

        if (quantidade > notas10) {
            quantidade = notas10;
        }

        usada10 = quantidade;
        restante -= quantidade * 10;

        quantidade = restante / 5;

        if (quantidade > notas5) {
            quantidade = notas5;
        }

        usada5 = quantidade;
        restante -= quantidade * 5;

        if (restante != 0) {

            printf("Nao e possivel realizar o saque.\n");
        }

        else {

            notas200 -= usada200;
            notas100 -= usada100;
            notas50 -= usada50;
            notas20 -= usada20;
            notas10 -= usada10;
            notas5 -= usada5;

            printf("\nNotas entregues:\n");
            printf("R$ 200: %d\n", usada200);
            printf("R$ 100: %d\n", usada100);
            printf("R$ 50: %d\n", usada50);
            printf("R$ 20: %d\n", usada20);
            printf("R$ 10: %d\n", usada10);
            printf("R$ 5: %d\n", usada5);
        }
    }

    return 0;
}