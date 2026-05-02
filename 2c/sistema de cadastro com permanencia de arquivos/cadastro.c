#include <stdio.h>

typedef struct
{
    int id;
    char nome[10];
    int idade;
} Usuario;

void cadastrar()
{
    FILE *f = fopen("dados.bin", "ab");

    Usuario u;

    printf("ID: ");
    scanf("%d", &u.id);

    printf("Nome: ");
    scanf("%9s", u.nome);

    printf("Idade: ");
    scanf("%d", &u.idade);

    fwrite(&u, sizeof(Usuario), 1, f);

    fclose(f);
}


void listar()
{
    FILE *f = fopen("dados.bin", "rb");

    if (f == NULL){
        printf("Arquivo vazio!\n");
        return;
    }

    Usuario u;
    int encontrou = 0;

    while (fread(&u, sizeof(Usuario), 1, f) == 1){
        if (!encontrou) {
            printf("Lista de usuários:\n");
        }

        encontrou = 1;

        printf("Nome: %s\n", u.nome);
        printf("Idade: %d\n", u.idade);
    }

    if (!encontrou) {
        printf("Arquivo vazio!\n");
    }

    fclose(f);
}


int main()
{
    int opcao;

    do {
        printf(
        "1 - Cadastrar\n"
        "2 - Listar\n"
        "3 - Sair\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            cadastrar();
            break;
            
            case 2:
            listar();
            break;

            case 3:
            break;
        }   
    } while(opcao != 3);

    return 0;
}