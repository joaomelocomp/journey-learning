#include <stdio.h>

int main () {
    FILE *arquivo;
    char palavra[20];

    arquivo = fopen("teste.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }
    printf("Digite uma palavra");
    scanf("%s", palavra);

    fprintf(arquivo, "%s", palavra);

    fclose(arquivo);

    return 0;
}