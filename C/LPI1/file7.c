/*7) Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da
universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas acima
da média da turma. Considerar que a turma tenha 50 alunos. Usar a estrutura multivalorada vista em sala de
aula.*/

#include <stdio.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno alunos[50];

    float soma = 0;
    float media;

    for (int i = 0; i < 50; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        soma += alunos[i].nota;
    }

    media = soma / 50;

    printf("\nMedia da turma: %.2f\n", media);

    printf("\nCinco maiores notas acima da media:\n");

    for (int j = 0; j < 5; j++) {
        int maior = -1;

        for (int i = 0; i < 50; i++) {
            if (alunos[i].nota > media) {
                if (maior == -1 || alunos[i].nota > alunos[maior].nota) {
                    maior = i;
                }
            }
        }

        if (maior != -1) {
            printf("%s - %.2f\n",
                   alunos[maior].nome,
                   alunos[maior].nota);

            alunos[maior].nota = -1;
        }
    }

    return 0;
}

