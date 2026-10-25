/*22) Escrever um programa em C que leia uma cadeia de caracteres de tamanho máximo igual a 80 e
imprimir quantas vogais tem a cadeia lida. Fazer a diferenciação entre letras maiúsculas e minúsculas.
Calcular, também, o percentual do número de vogais com relação ao número total de caracteres da
cadeia.*/

#include <stdio.h>

int main () {

    char texto[81];

    int vogais = 0;
    int caracteres = 0;

    printf("Digite uma cadeia: ");
    fgets(texto, 81, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {

        if (texto[i] == 'a' || texto[i] == 'e' ||
            texto[i] == 'i' || texto[i] == 'o' ||
            texto[i] == 'u' ||
            texto[i] == 'A' || texto[i] == 'E' ||
            texto[i] == 'I' || texto[i] == 'O' ||
            texto[i] == 'U') {

            vogais++;
        }

        if (texto[i] != '\n') {
            caracteres++;
        }
    }

    printf("Quantidade de vogais: %d\n", vogais);

    printf("Percentual de vogais: %.2f%%\n",
           (vogais * 100.0) / caracteres);

    return 0;
}