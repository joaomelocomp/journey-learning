/*19) Escreva um programa em C que leia os dados de uma matriz M(5,5) e calcule as somas:
a) da linha 4 de M;
b) da coluna 2 de M;
c) da diagonal principal;
d) da diagonal secundária;
e) de todos os elementos da matriz;
f) Escreva estas somas e a matriz*/

#include <stdio.h>

int main () {

    int M[5][5];

    int linha4 = 0;
    int coluna2 = 0;
    int diagonalPrincipal = 0;
    int diagonalSecundaria = 0;
    int total = 0;

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            printf("M[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);

            total += M[i][j];

            if (i == 3) {
                linha4 += M[i][j];
            }

            if (j == 1) {
                coluna2 += M[i][j];
            }

            if (i == j) {
                diagonalPrincipal += M[i][j];
            }

            if (i + j == 4) {
                diagonalSecundaria += M[i][j];
            }
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            printf("%d ", M[i][j]);
        }

        printf("\n");
    }

    printf("\nSoma da linha 4: %d\n", linha4);
    printf("Soma da coluna 2: %d\n", coluna2);
    printf("Soma da diagonal principal: %d\n", diagonalPrincipal);
    printf("Soma da diagonal secundaria: %d\n", diagonalSecundaria);
    printf("Soma de todos os elementos: %d\n", total);

    return 0;
}