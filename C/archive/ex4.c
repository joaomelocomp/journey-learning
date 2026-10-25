/*Faça um programa que:

Abra/crie pessoas.txt.
Peça o nome e a idade de 3 pessoas.
A cada pessoa, grave no arquivo:
Joao 22
Maria 19
Carlos 25*/

#include <stdio.h>

typedef struct {
    char nome[10];
    int idade;
} bebes;

int main () {
    FILE* arquivos;

    arquivos = fopen("bebesofia.txt", "w");

    for (int i = 0; i < 2; i++) {
        bebes p;
        printf("Nome do bebe ");
        scanf("%s", p.nome);

        printf("Idade do bebe ");
        scanf("%d", &p.idade);

        fprintf(arquivos, "%s %d", p.nome, p.idade);
    }

    fclose(arquivos);

    return 0;
}