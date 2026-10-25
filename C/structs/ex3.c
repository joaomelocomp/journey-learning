#include <stdio.h>

FILE* banco;

typedef struct 
{
    char cpf[11];
    char senha[4];
    float saldo;
} contas;

void cadastrar() {
    contas conta;

    conta.saldo = 0;

    printf("Digite seu CPF: ");
    scanf("%s", conta.cpf);

    printf("Crie sua senha: ");
    scanf("%s", conta.senha);

    banco = fopen("banco.txt", "w");

    fprintf(banco, "CPF: %s SENHA: %s SALDO: %.2f\n", conta.cpf, conta.senha, conta.saldo);

    fclose(banco);

    printf("Cadastrado com sucesso\n");
}

void atualizaSaldo() {
    contas conta;
    float valor = 0;

    banco = fopen("banco.txt", "r");

    fscanf(banco, "%f", &conta.saldo);

    fclose(banco);

    banco = fopen("banco.txt", "w");

    printf("Quanto deseja adicionar? (Em caso de retirada adicione (-) antes do primeiro número)");
    scanf("%f", &valor);

    fprintf(banco, "%.2f", (conta.saldo) + (valor));

    fclose(banco);

    printf("Valor atualizado");
}

void verificar () {
    contas conta;
    banco = fopen("banco.txt", "r");

    while (fscanf(banco, "%s", conta.cpf) != )
}

int main () {
    int opcao = 0;

    while (opcao != 3) {
        printf("1 - Entrar\n"
                "2 - Cadastrar\n"
                "3 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 2) {
            cadastrar();
        } 
    }

    return 0;
}