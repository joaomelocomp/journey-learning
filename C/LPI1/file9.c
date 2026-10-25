/*9) Escrever um programa em C que calcule e imprima o número de caracteres distintos presentes em uma
cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas. 
*/

#include <stdio.h>

int main() {
    char texto[81];
    int caracteres[256] = {0};
    int quantidade = 0;

    printf("Digite uma cadeia: ");
    fgets(texto, 81, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        int caractere = texto[i];

        if (caracteres[caractere] == 0) {
            caracteres[caractere] = 1;
            quantidade++;
        }
    }

    printf("Quantidade de caracteres distintos: %d\n", quantidade);

    return 0;
}