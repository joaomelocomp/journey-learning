/*20) Fazer um programa em C que faça a soma de duas matrizes.*/

#include <stdio.h>

int main () {

    int A[3][3];
    int B[3][3];
    int C[3][3];

    printf("Digite a primeira matriz:\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite a segunda matriz:\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatriz resultante:\n");

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}