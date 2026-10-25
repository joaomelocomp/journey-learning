/*16) Faça um programa em C que atenda às regras do seguinte jogo de dados. Dois jogadores estão
confrontando-se entre si, usando dois dados, numerados de 1 até 6 (dado = RAND(5) + 1). Vence uma
rodada quem obtiver o maior número no lançamento. Entretanto, caso um jogador obtiver um lançamento
com dois dados iguais (por exemplo, 1 e 1, 2 e 2,....) e o outro jogador não, o jogador que tiver lançado a
dupla ganha. Caso os dois jogadores fizerem o lançamento e o resultado for de duas duplas para os dois
jogadores, ganha o jogador com a dupla maior. A disputa é em 11 lançamentos. Indique o jogador
vencedor ou se houve empate.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    int jogador1 = 0;
    int jogador2 = 0;

    int dado1;
    int dado2;

    srand(time(NULL));

    for (int i = 1; i <= 11; i++) {

        int j1dado1 = rand() % 6 + 1;
        int j1dado2 = rand() % 6 + 1;

        int j2dado1 = rand() % 6 + 1;
        int j2dado2 = rand() % 6 + 1;

        int dupla1 = j1dado1 == j1dado2;
        int dupla2 = j2dado1 == j2dado2;

        printf("\nRodada %d\n", i);

        printf("Jogador 1: %d e %d\n", j1dado1, j1dado2);
        printf("Jogador 2: %d e %d\n", j2dado1, j2dado2);

        if (dupla1 && !dupla2) {
            jogador1++;
        }

        else if (dupla2 && !dupla1) {
            jogador2++;
        }

        else if (dupla1 && dupla2) {

            if (j1dado1 > j2dado1) {
                jogador1++;
            }

            else if (j2dado1 > j1dado1) {
                jogador2++;
            }
        }

        else {

            int soma1 = j1dado1 + j1dado2;
            int soma2 = j2dado1 + j2dado2;

            if (soma1 > soma2) {
                jogador1++;
            }

            else if (soma2 > soma1) {
                jogador2++;
            }
        }
    }

    printf("\nVitorias do jogador 1: %d\n", jogador1);
    printf("Vitorias do jogador 2: %d\n", jogador2);

    if (jogador1 > jogador2) {
        printf("Jogador 1 venceu!\n");
    }

    else if (jogador2 > jogador1) {
        printf("Jogador 2 venceu!\n");
    }

    else {
        printf("Empate!\n");
    }

    return 0;
}