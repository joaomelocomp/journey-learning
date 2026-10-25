/*10)Escrever um programa em C que calcule a frequência de uso de cada palavra dentro de uma cadeia de
caracteres que possui diversas palavras. Considerar o tamanho máximo da cadeia como sendo de 80 colunas. */

#include <stdio.h>
#include <string.h>

int main() {
    char texto[81];
    char palavras[40][20];
    int frequencia[40];

    int quantidade = 0;

    printf("Digite uma cadeia: ");
    fgets(texto, 81, stdin);

    char *palavra = strtok(texto, " \n");

    while (palavra != NULL) {
        int encontrou = 0;

        for (int i = 0; i < quantidade; i++) {
            if (strcmp(palavras[i], palavra) == 0) {
                frequencia[i]++;
                encontrou = 1;
            }
        }

        if (encontrou == 0) {
            strcpy(palavras[quantidade], palavra);
            frequencia[quantidade] = 1;
            quantidade++;
        }

        palavra = strtok(NULL, " \n");
    }

    printf("\nFrequencia das palavras:\n");

    for (int i = 0; i < quantidade; i++) {
        printf("%s: %d\n", palavras[i], frequencia[i]);
    }

    return 0;
}