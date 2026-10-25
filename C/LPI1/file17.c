/*17) Elabore um programa em C que calcule a quantidade de dias existentes entre duas datas. Dica: utilize
as variáveis D1, M1, A1, D2, M2, A2. Por hipótese, as variáveis dos anos não precisam considerar a correção
do calendário gregoriano. Lembre-se que há regras especiais de anos bissextos conforme o ano específico.*/

#include <stdio.h>

int main () {

    int D1, M1, A1;
    int D2, M2, A2;

    int dias1 = 0;
    int dias2 = 0;

    printf("Digite a primeira data (dia mes ano): ");
    scanf("%d %d %d", &D1, &M1, &A1);

    printf("Digite a segunda data (dia mes ano): ");
    scanf("%d %d %d", &D2, &M2, &A2);

    int diasMes[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    for (int i = 1; i < A1; i++) {

        dias1 += 365;

        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
            dias1++;
        }
    }

    for (int i = 1; i < M1; i++) {
        dias1 += diasMes[i - 1];
    }

    if (M1 > 2 && (A1 % 400 == 0 || (A1 % 4 == 0 && A1 % 100 != 0))) {
        dias1++;
    }

    dias1 += D1;

    for (int i = 1; i < A2; i++) {

        dias2 += 365;

        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
            dias2++;
        }
    }

    for (int i = 1; i < M2; i++) {
        dias2 += diasMes[i - 1];
    }

    if (M2 > 2 && (A2 % 400 == 0 || (A2 % 4 == 0 && A2 % 100 != 0))) {
        dias2++;
    }

    dias2 += D2;

    int diferenca = dias2 - dias1;

    if (diferenca < 0) {
        diferenca = diferenca * -1;
    }

    printf("Quantidade de dias: %d\n", diferenca);

    return 0;
}