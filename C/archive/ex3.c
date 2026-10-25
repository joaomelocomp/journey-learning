/*
Faça um programa em C que:
a) Leia e escreva o nome e a altura das moças inscritas em um concurso de beleza,
até que seja digitada o nome ‘MARIA’,
 que marca o final da lista, mas é para ser computada no concurso.
b) Calcule e grave em um arquivo binário chamado “beleza2024.dat” o nome e altura
das duas candidatas mais altas do concurso.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[20];
    float altura;
} modelo;

int main () {
    bool x = false;
    int i = 0;

    FILE* arquivos;

    arquivos = fopen("estudo.txt", "w");

    while (x == false) {
        modelo mulher;

        printf("Nome: ");
        scanf("%s", mulher.nome);

        printf("Altura: ");
        scanf("%f", &mulher.altura);

        fprintf(arquivos, "%s %.2f\n", mulher.nome, mulher.altura);

        i++;
    }
    fclose(arquivos);
    return 0;
}