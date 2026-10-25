#include <stdio.h>
#include <string.h>

typedef struct {
    char rua[99];
    char cidade[49];
    char estado[3];
    char cep[9];
} Endereco;

typedef struct {
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

typedef struct {
    char descricaoItem[21];
    int quantidadePedido;
    float valorItem;
} Descricao;

typedef struct {
    char numeroPedido[10];
    char cnpj[15];
    char data[11];
    char dataEntrega[11];
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

int contarClientes() {
    FILE *arquivo = fopen("Cliente.dat", "rb");
    Cliente c;
    int contador = 0;

    if (arquivo == NULL) {
        return 0;
    }

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}

void inserirCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "ab");
    Cliente c;

    if (arquivoUm == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n### Cadastrar Cliente ###\n");

    printf("Digite seu CNPJ: ");
    scanf("%s", c.cnpj);

    printf("Digite seu Nome: ");
    scanf("%s", c.nomeDoCliente);

    printf("Razao Social: ");
    scanf("%s", c.razaoSocial);

    printf("Digite seu Endereco\n");
    c.endereco = inserirEndereco();

    printf("Inscricao Estadual: ");
    scanf("%s", c.insEst);

    printf("Digite seu Telefone: ");
    scanf("%s", c.telefone);

    printf("Digite seu email: ");
    scanf("%s", c.email);

    printf("Nome para contato: ");
    scanf("%s", c.contato);

    c.id = contarClientes() + 1;

    fwrite(&c, sizeof(Cliente), 1, arquivoUm);

    fclose(arquivoUm);

    printf("Cliente cadastrado!\n");
}

void consultarCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "rb");
    Cliente c;

    if (arquivoUm == NULL) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    printf("\n### Lista de clientes ###\n");

    while (fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        printf("ID #%d | %s | %s\n", c.id, c.cnpj, c.nomeDoCliente);
    }

    fclose(arquivoUm);
}

void alterarCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "r+b");
    Cliente c;
    int n;
    int opcao;

    if (arquivoUm == NULL) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }

    consultarCliente();

    printf("Qual cliente voce deseja alterar? ");
    scanf("%d", &n);

    while (fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
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
            printf("11 - CEP\n");
            printf("12 - Voltar\n");

            printf("Qual campo deseja alterar? ");
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
                    fclose(arquivoUm);
                    return;
                default:
                    printf("Opcao invalida!\n");
                    fclose(arquivoUm);
                    return;
            }

            fseek(arquivoUm, -sizeof(Cliente), SEEK_CUR);
            fwrite(&c, sizeof(Cliente), 1, arquivoUm);

            printf("Cliente alterado!\n");
            fclose(arquivoUm);
            return;
        }
    }

    printf("Cliente nao encontrado!\n");
    fclose(arquivoUm);
}

void excluirCliente() {
    FILE *arquivoUm = fopen("Cliente.dat", "rb");
    FILE *temporario = fopen("temp.dat", "wb");
    Cliente c;
    int n;
    int encontrou = 0;

    if (arquivoUm == NULL || temporario == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    consultarCliente();

    printf("Qual cliente deseja excluir? ");
    scanf("%d", &n);

    while (fread(&c, sizeof(Cliente), 1, arquivoUm) == 1) {
        if (c.id == n) {
            encontrou = 1;
        } else {
            fwrite(&c, sizeof(Cliente), 1, temporario);
        }
    }

    fclose(arquivoUm);
    fclose(temporario);

    remove("Cliente.dat");
    rename("temp.dat", "Cliente.dat");

    if (encontrou) {
        printf("Cliente excluido!\n");
    } else {
        printf("Cliente nao encontrado!\n");
    }
}

void descricao(Descricao itens[]) {
    for (int i = 0; i < 6; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Descricao: ");
        scanf("%s", itens[i].descricaoItem);
        printf("Quantidade: ");
        scanf("%d", &itens[i].quantidadePedido);
        printf("Valor: ");
        scanf("%f", &itens[i].valorItem);
    }
}

float calcularTotal(Descricao itens[]) {
    float total = 0;

    for (int i = 0; i < 6; i++) {
        total += itens[i].quantidadePedido * itens[i].valorItem;
    }

    return total;
}

void inserirPedido() {
    FILE *arquivoDois = fopen("Pedidos.dat", "ab");
    Pedido p;

    if (arquivoDois == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n### Cadastrar Pedido ###\n");

    printf("Numero do pedido: ");
    scanf("%s", p.numeroPedido);

    printf("CNPJ do cliente: ");
    scanf("%s", p.cnpj);

    printf("Data do pedido: ");
    scanf("%s", p.data);

    printf("Data da entrega: ");
    scanf("%s", p.dataEntrega);

    printf("Previsao de entrega: ");
    scanf("%d", &p.previsao);

    descricao(p.itens);

    p.totalPedido = calcularTotal(p.itens);

    printf("Total do pedido: %.2f\n", p.totalPedido);

    printf("Forma de pagamento: ");
    scanf("%s", p.formaPagamento);

    fwrite(&p, sizeof(Pedido), 1, arquivoDois);

    fclose(arquivoDois);

    printf("Pedido cadastrado!\n");
}

void consultarPedido(Pedido p) {
    printf("\nNumero: %s\n", p.numeroPedido);
    printf("CNPJ: %s\n", p.cnpj);
    printf("Data: %s\n", p.data);
    printf("Data de entrega: %s\n", p.dataEntrega);
    printf("Previsao: %d dias\n", p.previsao);

    for (int i = 0; i < 6; i++) {
        printf("Item %d: %s | Quantidade: %d | Valor: %.2f\n",
               i + 1,
               p.itens[i].descricaoItem,
               p.itens[i].quantidadePedido,
               p.itens[i].valorItem);
    }

    printf("Total: %.2f\n", p.totalPedido);
    printf("Pagamento: %s\n", p.formaPagamento);
}

void consultarPedidosCliente() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;
    char cnpj[15];

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("CNPJ do cliente: ");
    scanf("%s", cnpj);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.cnpj, cnpj) == 0) {
            consultarPedido(p);
        }
    }

    fclose(arquivo);
}

void consultarTodosPedidos() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        consultarPedido(p);
    }

    fclose(arquivo);
}

void alterarPedido() {
    FILE *arquivo = fopen("Pedidos.dat", "r+b");
    Pedido p;
    char numero[10];
    int opcao;

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("Numero do pedido: ");
    scanf("%s", numero);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.numeroPedido, numero) == 0) {
            printf("\n1 - CNPJ\n");
            printf("2 - Data do pedido\n");
            printf("3 - Data da entrega\n");
            printf("4 - Previsao\n");
            printf("5 - Itens\n");
            printf("6 - Forma de pagamento\n");
            printf("7 - Voltar\n");

            printf("Opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Novo CNPJ: ");
                    scanf("%s", p.cnpj);
                    break;
                case 2:
                    printf("Nova data: ");
                    scanf("%s", p.data);
                    break;
                case 3:
                    printf("Nova data de entrega: ");
                    scanf("%s", p.dataEntrega);
                    break;
                case 4:
                    printf("Nova previsao: ");
                    scanf("%d", &p.previsao);
                    break;
                case 5:
                    descricao(p.itens);
                    p.totalPedido = calcularTotal(p.itens);
                    break;
                case 6:
                    printf("Nova forma de pagamento: ");
                    scanf("%s", p.formaPagamento);
                    break;
                case 7:
                    fclose(arquivo);
                    return;
                default:
                    printf("Opcao invalida!\n");
                    fclose(arquivo);
                    return;
            }

            fseek(arquivo, -sizeof(Pedido), SEEK_CUR);
            fwrite(&p, sizeof(Pedido), 1, arquivo);

            printf("Pedido alterado!\n");
            fclose(arquivo);
            return;
        }
    }

    printf("Pedido nao encontrado!\n");
    fclose(arquivo);
}

void excluirPedido() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    FILE *temporario = fopen("temp.dat", "wb");
    Pedido p;
    char numero[10];
    int encontrou = 0;

    if (arquivo == NULL || temporario == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Numero do pedido: ");
    scanf("%s", numero);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.numeroPedido, numero) == 0) {
            encontrou = 1;
        } else {
            fwrite(&p, sizeof(Pedido), 1, temporario);
        }
    }

    fclose(arquivo);
    fclose(temporario);

    remove("Pedidos.dat");
    rename("temp.dat", "Pedidos.dat");

    if (encontrou) {
        printf("Pedido excluido!\n");
    } else {
        printf("Pedido nao encontrado!\n");
    }
}

void pedidosEntreDatas() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;
    char inicio[11];
    char fim[11];

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("Data inicial (AAAA-MM-DD): ");
    scanf("%s", inicio);

    printf("Data final (AAAA-MM-DD): ");
    scanf("%s", fim);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.data, inicio) >= 0 && strcmp(p.data, fim) <= 0) {
            consultarPedido(p);
        }
    }

    fclose(arquivo);
}

void pedidosEntregues() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;
    char data[11];

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("A partir de qual data? (AAAA-MM-DD): ");
    scanf("%s", data);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.dataEntrega, data) >= 0) {
            consultarPedido(p);
        }
    }

    fclose(arquivo);
}

void pedidosAbertos() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("\n### PEDIDOS EM ABERTO ###\n");

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.dataEntrega, "") == 0 || strcmp(p.dataEntrega, "0000-00-00") == 0) {
            consultarPedido(p);
        }
    }

    fclose(arquivo);
}

void mediaMensal() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    Pedido p;
    char cnpj[15];
    float total = 0;
    int quantidade = 0;

    if (arquivo == NULL) {
        printf("Nenhum pedido cadastrado!\n");
        return;
    }

    printf("CNPJ do cliente: ");
    scanf("%s", cnpj);

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1) {
        if (strcmp(p.cnpj, cnpj) == 0) {
            total += p.totalPedido;
            quantidade++;
        }
    }

    fclose(arquivo);

    if (quantidade > 0) {
        printf("Media mensal: %.2f\n", total / quantidade);
    } else {
        printf("Nenhum pedido encontrado!\n");
    }
}

void menuCliente() {
    int opcao;

    do {
        printf("\n### CLIENTES ###\n");
        printf("1 - Inserir\n");
        printf("2 - Alterar\n");
        printf("3 - Excluir\n");
        printf("4 - Consultar\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirCliente();
                break;
            case 2:
                alterarCliente();
                break;
            case 3:
                excluirCliente();
                break;
            case 4:
                consultarCliente();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuPedido() {
    int opcao;

    do {
        printf("\n### PEDIDOS ###\n");
        printf("1 - Inserir\n");
        printf("2 - Alterar\n");
        printf("3 - Excluir\n");
        printf("4 - Pedidos de um cliente\n");
        printf("5 - Todos os pedidos\n");
        printf("6 - Pedidos entre duas datas\n");
        printf("7 - Pedidos entregues a partir de uma data\n");
        printf("8 - Pedidos em aberto\n");
        printf("9 - Media mensal\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPedido();
                break;
            case 2:
                alterarPedido();
                break;
            case 3:
                excluirPedido();
                break;
            case 4:
                consultarPedidosCliente();
                break;
            case 5:
                consultarTodosPedidos();
                break;
            case 6:
                pedidosEntreDatas();
                break;
            case 7:
                pedidosEntregues();
                break;
            case 8:
                pedidosAbertos();
                break;
            case 9:
                mediaMensal();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main() {
    int opcao;

    do {
        printf("\n### SISTEMA ###\n");
        printf("1 - Clientes\n");
        printf("2 - Pedidos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuCliente();
                break;
            case 2:
                menuPedido();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}