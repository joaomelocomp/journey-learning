/*11) Escrever um programa em C que leia uma cadeia de caracteres e imprima todas as palavras que
contenham três ou mais vogais.*/

#include <stdio.h>
#include <string.h>

int main () {

    char texto[81];

    printf("Digite uma cadeia: ");
    fgets(texto, 81, stdin);

    char *palavra = strtok(texto, " \n");

    while (palavra != NULL) {

        int vogais = 0;

        for (int i = 0; palavra[i] != '\0'; i++) {

            if (palavra[i] == 'a' || palavra[i] == 'e' ||
                palavra[i] == 'i' || palavra[i] == 'o' ||
                palavra[i] == 'u') {

                vogais++;
            }
        }

        if (vogais >= 3) {
            printf("%s\n", palavra);
        }

        palavra = strtok(NULL, " \n");
    }

    return 0;
}