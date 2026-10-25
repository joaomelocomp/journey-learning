#include <stdio.h>

typedef struct {
    char nome[10];
    int idade;
    float nota;
} aluno ;

void exibir (aluno x) {
    printf("Nome %s Idade %d Nota %2.f", x.nome, x.idade, x.nota);
}

int main () {
    aluno a1;

    printf("Nome: ");
    scanf("%s", &a1.nome);
    printf("Idade: ");
    scanf("%d", &a1.idade);
    printf("Nota: ");
    scanf("%f", &a1.nota);

    exibir(a1);

    return 0;
} 