#include <stdio.h>
#include <string.h>

void consultarCliente();

typedef struct
{
    char rua[99];
    char cidade[49];
    char estado[3];
    char cep[9];
} Endereco;

typedef struct
{
    char cnpj[15];
    char nomeDoCliente[99];
    char razaoSocial[99];
    Endereco endereco;
    char insEst[99];
    char telefone[11];
    char email[99];
    char contato[99];
    int id;
} Cliente;

typedef struct
{
    char numeroPedido[10];
    char cnpj[15];
    char data[7];
    char dataEntrega[7];
    int previsao;

    Descricao itens[6];

    float totalPedido;
    char formaPagamento[20];

} Pedido;

Endereco inserirEndereco() {
    Endereco x;
    printf("Logradouro: ");
    scanf("%s", x.rua);
    printf("Cidade: ");
    scanf("%s", x.cidade);
    printf("Estado: ");
    scanf("%s", x.estado);
    printf("CEP: ");
    scanf("%s", x.cep);

    return x;
}

int contar() {
    FILE *arquivoUm = fopen("Cliente.dat", "rb");

    Cliente c;

    int contador = 0;

    while(fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        contador++;
    }

    fclose(arquivoUm);

    return contador;
}

void inserirCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "ab");

    Cliente c;
    printf("Digite seu CNPJ: ");
    scanf("%s", c.cnpj);

    printf("Digite seu Nome: ");
    scanf("%s", c.nomeDoCliente);

    printf("Razão Social: ");
    scanf("%s", c.razaoSocial);

    printf("Digite seu Endereco\n");
    c.endereco = inserirEndereco();

    printf("Inscrição EStadual: ");
    scanf("%s", c.insEst);

    printf("Digite seu Telefone: ");
    scanf("%s", c.telefone);

    printf("Digite seu email: ");
    scanf("%s", c.email);

    printf("Nome para contato: ");
    scanf("%s", c.contato);

    if (c.id == contar() + 1) {
        c.id = contar() + 2;
    } else {
        c.id = contar() + 1;
    }

    fwrite(&c, sizeof(Cliente), 1, arquivoUm);

    fclose(arquivoUm);
}

void alterarCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "r+b");
    
    int n = 0;
    int opcao = 0;

    Cliente c;

    consultarCliente();
    printf("Qual cliente você deseja alterar? ");
    scanf("%d", &n);

    while(fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        if (c.id == n) {
            printf("\n1 - CNPJ\n");
            printf("2 - Nome\n");
            printf("3 - Razao Social\n");
            printf("4 - Inscricao Estadual\n");
            printf("5 - Telefone\n");
            printf("6 - Email\n");
            printf("7 - Contato\n");
            printf("8 - Rua\n");
            printf("9 - Cidade\n");
            printf("10 - Estado\n");
            printf("11 - CEP   12 - ### Voltar ###\n");

            printf("Qual campo você deseja alterar? ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Novo CNPJ: ");
                    scanf("%s", c.cnpj);
                    break;

                case 2:
                    printf("Novo nome: ");
                    scanf("%s", c.nomeDoCliente);
                    break;

                case 3:
                    printf("Nova razao social: ");
                    scanf("%s", c.razaoSocial);
                    break;

                case 4:
                    printf("Nova inscricao estadual: ");
                    scanf("%s", c.insEst);
                    break;

                case 5:
                    printf("Novo telefone: ");
                    scanf("%s", c.telefone);
                    break;

                case 6:
                    printf("Novo email: ");
                    scanf("%s", c.email);
                    break;

                case 7:
                    printf("Novo contato: ");
                    scanf("%s", c.contato);
                    break;

                case 8:
                    printf("Nova rua: ");
                    scanf("%s", c.endereco.rua);
                    break;

                case 9:
                    printf("Nova cidade: ");
                    scanf("%s", c.endereco.cidade);
                    break;

                case 10:
                    printf("Novo estado: ");
                    scanf("%s", c.endereco.estado);
                    break;

                case 11:
                    printf("Novo CEP: ");
                    scanf("%s", c.endereco.cep);
                    break;

                case 12:
                    break;

                default:
                    printf("Opcao invalida!\n");
                    fclose(arquivoUm);
                    return;
            }
            }
        }

        fclose(arquivoUm);
    }

void consultarCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "rb");

    Cliente c;

    printf("\n### Lista de clientes ###\n");
    while(fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        printf("ID #%d | %s\n", c.id, c.cnpj);
    }
    fclose(arquivoUm);
}

void consultarClienteDois() {
    FILE *arquivoUm = fopen("Cliente.dat", "rb");

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        printf("\nCNPJ -> %s\n", c.cnpj);
        printf("Nome do cliente -> %s\n", c.nomeDoCliente);
        printf("Razao Social -> %s\n", c.razaoSocial);

        printf("Rua -> %s\n", c.endereco.rua);
        printf("Cidade -> %s\n", c.endereco.cidade);
        printf("Estado -> %s\n", c.endereco.estado);
        printf("CEP -> %s\n", c.endereco.cep);

        printf("Inscrição E. -> %s\n", c.insEst);
        printf("Telefone -> %s\n", c.telefone);
        printf("Email -> %s\n", c.email);
        printf("Contato -> %s\n", c.contato);
    }

    fclose(arquivoUm);
}

typedef struct {
    char descricaoItem[21];
    int quantidadePedido;
} Descricao;

void descricao(Descricao itens[]) {

    printf("### Cadastrar Itens ###\n");

    for (int i = 0; i < 6; i++) {

        printf("\nItem %d\n", i + 1);

        printf("Descricao do item: ");
        scanf("%20s", itens[i].descricaoItem);

        printf("Quantidade do item: ");
        scanf("%d", &itens[i].quantidadePedido);
    }
}

void inserirPedido () {
    FILE *arquivoDois = fopen("Pedidos.dat", "ab");

    Pedido p;

    printf("### Cadastrar pedidos ###\n");
    printf("Número do pedido: ");
    scanf("%s", p.numeroPedido);
    printf("CNPJ do cliente: ");
    scanf("%s", p.cnpj);
    printf("Data da compra: ");
    scanf("%s", p.data);
    printf("Data da entrega: ");
    scanf("%s", p.dataEntrega);
    printf("Previsão estimada: ");
    scanf("%d", &p.numeroPedido);
    
    descricao(p.itens);

    printf("Total do pedido: ");
    scanf("%f", &p.totalPedido);
    printf("Forma de pagamento: ");
    scanf("%s", p.formaPagamento);

    fwrite(&p, sizeof(Pedido), 1, arquivoDois);

    fclose(arquivoDois);

    printf("\nPedido cadastrado com sucesso!\n");

}

int main() {
    alterarCliente();
    return 0;
}