/*14) Faça um programa em C que simule um cronômetro com horas, minutos e segundos. A simulação deverá
mostrar no vídeo o cronômetro no seguinte formato HH: MM: SS. Inicialmente o cronômetro será zerado
( 00: 00: 00 ), sendo que os segundos começarão a ser incrementados, depois os minutos e depois as
horas. Lembre-se que a cada 60 segundos os minutos deverão ser incrementados, depois os minutos
voltarão a zero. Quando as horas estiverem prestes a chegar em 24, o cronômetro deverá voltar a zero (
00: 00: 00 ).*/

#include <stdio.h>

int main () {

    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    while (1) {

        printf("%02d: %02d: %02d\n", horas, minutos, segundos);

        segundos++;

        if (segundos == 60) {
            segundos = 0;
            minutos++;
        }

        if (minutos == 60) {
            minutos = 0;
            horas++;
        }

        if (horas == 24) {
            horas = 0;
        }
    }

    return 0;
}