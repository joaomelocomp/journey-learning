/*2. Cadastro de vários alunos 📚

Usando a mesma struct Aluno, faça um programa que cadastre 5 alunos em um vetor.

Depois, mostre:

Nome de cada aluno
Nota de cada aluno
A maior nota entre eles*/

#include <stdio.h>

typedef struct {
    char nome[99];
    float nota;
} aluno;

void imprimir (aluno *x, int size) {
    for (int i = 0; i < size; i++) {
        printf("Aluno %d -> Nome: %s Nota: %2.f ### \n", i, x[i].nome, x[i].nota);
    }
}

float maior (aluno *x, int size) {
    int auxiliar = 0;
    for (int i = 0; i < size; i++) {
        if (auxiliar < x[i].nota) {
            auxiliar = x[i].nota;
        }
    }
    return auxiliar;
}

int main () {
    aluno ficha[5];

    int tamanho = sizeof(ficha) / sizeof(ficha[0]);

    for (int i = 0; i < 5; i++) {

        printf("Nome: ");
        scanf("%s", ficha[i].nome);

        printf("Nota: ");
        scanf("%f", &ficha[i].nota);
    }

    imprimir(ficha, tamanho);
    printf("%f", maior(ficha, tamanho));

    return 0;
}