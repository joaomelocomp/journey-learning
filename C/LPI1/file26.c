/*26) Implemente em C o jogo Blackjack ou 21. No caso temos apenas dois jogadores, o cliente (humano) e a
banca (computador). O ás pode valer 1 ou 11, de acordo com as cartas que o jogador possui. O valete (J),
a dama (Q) e o rei (K) valem 10. A simulação da obtenção das cartas deve ser feita com o uso de números
aleatórios (Dica: carta = função randômica(12) +1, isto é, variando de 1 a 13).
Os números 11, 12 e 13 representam respectivamente J, Q e K. Não há a necessidade de representar um
baralho real de 52 cartas. O cliente recebe inicialmente duas cartas aleatoriamente e decide se pede
outra ou não, dependendo do somatório. Caso a soma das cartas seja maior que 21, o cliente perde. O
cliente pode passar a vez para a banca (que não possui cartas no início do jogo), que, para vencer, terá
que obter obrigatoriamente um número maior que o cliente e MENOR do que 21, caso contrário, o cliente
ganha. O jogo tem apenas uma rodada. Informe quem ganhou ou se houve empate.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valorCarta(int carta) {

    if (carta >= 10) {
        return 10;
    }

    return carta;
}

int main () {

    int jogador = 0;
    int banca = 0;

    int carta;
    char opcao;

    srand(time(NULL));

    carta = rand() % 13 + 1;
    jogador += valorCarta(carta);

    carta = rand() % 13 + 1;
    jogador += valorCarta(carta);

    printf("Sua pontuacao: %d\n", jogador);

    while (jogador < 21) {

        printf("\nDeseja outra carta? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 'n') {
            break;
        }

        carta = rand() % 13 + 1;

        jogador += valorCarta(carta);

        printf("Carta recebida: %d\n", valorCarta(carta));
        printf("Sua pontuacao: %d\n", jogador);
    }

    if (jogador > 21) {

        printf("\nVoce perdeu!\n");
    }

    else {

        printf("\nVez da banca.\n");

        while (banca <= jogador && banca < 21) {

            carta = rand() % 13 + 1;

            banca += valorCarta(carta);

            printf("Banca recebeu: %d\n", valorCarta(carta));
            printf("Pontuacao da banca: %d\n", banca);
        }

        if (banca > jogador && banca < 21) {
            printf("\nA banca venceu!\n");
        }

        else if (banca == jogador) {
            printf("\nEmpate!\n");
        }

        else {
            printf("\nVoce venceu!\n");
        }
    }

    return 0;
}