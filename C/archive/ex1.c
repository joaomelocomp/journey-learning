#include <stdio.h>

int main () {
    FILE *arquivo;
    char palavra[20];

    arquivo = fopen("teste.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }
    fscanf(arquivo, "%s", palavra);
    printf("%s", palavra);

    fclose(arquivo);

    return 0;
}