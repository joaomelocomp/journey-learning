#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int contarClientes() {
    FILE *arquivo = fopen("Cliente.dat", "rb");

    if (arquivo == NULL)
        return 0;

    Cliente c;
    int contador = 0;

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        contador++;
    }

    fclose(arquivo);

    return contador;
}

int contarPedidos() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
        return 0;

    Pedido p;
    int contador = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        contador++;
    }

    fclose(arquivo);

    return contador;
}

int converterData(char data[]) {
    int dia, mes, ano;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    return ano * 10000 + mes * 100 + dia;
}

Endereco inserirEndereco() {
    Endereco x;

    printf("Logradouro: ");
    scanf(" %98[^\n]", x.rua);

    printf("Cidade: ");
    scanf(" %48[^\n]", x.cidade);

    printf("Estado: ");
    scanf("%2s", x.estado);

    printf("CEP: ");
    scanf("%8s", x.cep);

    return x;
}

int existeCliente(char cnpj[]) {
    FILE *arquivo = fopen("Cliente.dat", "rb");

    if (arquivo == NULL)
        return 0;

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        if (strcmp(c.cnpj, cnpj) == 0)
        {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);

    return 0;
}

void inserirCliente() {
    FILE *arquivo = fopen("Cliente.dat", "ab");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir Cliente.dat!\n");
        return;
    }

    Cliente c;

    printf("\n### CADASTRAR CLIENTE ###\n");

    printf("Digite seu CNPJ: ");
    scanf("%14s", c.cnpj);

    if (existeCliente(c.cnpj))
    {
        printf("Esse CNPJ ja esta cadastrado!\n");
        fclose(arquivo);
        return;
    }

    printf("Digite seu Nome: ");
    scanf(" %98[^\n]", c.nomeDoCliente);

    printf("Razao Social: ");
    scanf(" %98[^\n]", c.razaoSocial);

    printf("\n### ENDERECO ###\n");
    c.endereco = inserirEndereco();

    printf("Inscricao Estadual: ");
    scanf(" %98[^\n]", c.insEst);

    printf("Digite seu Telefone: ");
    scanf("%10s", c.telefone);

    printf("Digite seu email: ");
    scanf("%98s", c.email);

    printf("Nome para contato: ");
    scanf(" %98[^\n]", c.contato);

    c.id = contarClientes() + 1;

    fwrite(&c, sizeof(Cliente), 1, arquivo);

    fclose(arquivo);

    printf("\nCliente cadastrado com sucesso!\n");
}

void consultarCliente() {
    FILE *arquivo = fopen("Cliente.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    Cliente c;

    printf("\n### LISTA DE CLIENTES ###\n");

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        printf("ID #%d | CNPJ: %s | Nome: %s\n",
               c.id,
               c.cnpj,
               c.nomeDoCliente);
    }

    fclose(arquivo);
}

void consultarClienteDois() {
    FILE *arquivo = fopen("Cliente.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        printf("\n====================================\n");

        printf("ID -> %d\n", c.id);
        printf("CNPJ -> %s\n", c.cnpj);
        printf("Nome do cliente -> %s\n", c.nomeDoCliente);
        printf("Razao Social -> %s\n", c.razaoSocial);

        printf("Rua -> %s\n", c.endereco.rua);
        printf("Cidade -> %s\n", c.endereco.cidade);
        printf("Estado -> %s\n", c.endereco.estado);
        printf("CEP -> %s\n", c.endereco.cep);

        printf("Inscricao E. -> %s\n", c.insEst);
        printf("Telefone -> %s\n", c.telefone);
        printf("Email -> %s\n", c.email);
        printf("Contato -> %s\n", c.contato);
    }

    fclose(arquivo);
}

void alterarCliente() {
    FILE *arquivo = fopen("Cliente.dat", "r+b");

    if (arquivo == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    int n;
    int opcao;

    Cliente c;

    consultarCliente();

    printf("\nQual cliente voce deseja alterar? ");
    scanf("%d", &n);

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        if (c.id == n)
        {
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

            printf("\nQual campo deseja alterar? ");
            scanf("%d", &opcao);

            switch (opcao)
            {
                case 1:
                    printf("Novo CNPJ: ");
                    scanf("%14s", c.cnpj);
                    break;

                case 2:
                    printf("Novo nome: ");
                    scanf(" %98[^\n]", c.nomeDoCliente);
                    break;

                case 3:
                    printf("Nova razao social: ");
                    scanf(" %98[^\n]", c.razaoSocial);
                    break;

                case 4:
                    printf("Nova inscricao estadual: ");
                    scanf(" %98[^\n]", c.insEst);
                    break;

                case 5:
                    printf("Novo telefone: ");
                    scanf("%10s", c.telefone);
                    break;

                case 6:
                    printf("Novo email: ");
                    scanf("%98s", c.email);
                    break;

                case 7:
                    printf("Novo contato: ");
                    scanf(" %98[^\n]", c.contato);
                    break;

                case 8:
                    printf("Nova rua: ");
                    scanf(" %98[^\n]", c.endereco.rua);
                    break;

                case 9:
                    printf("Nova cidade: ");
                    scanf(" %48[^\n]", c.endereco.cidade);
                    break;

                case 10:
                    printf("Novo estado: ");
                    scanf("%2s", c.endereco.estado);
                    break;

                case 11:
                    printf("Novo CEP: ");
                    scanf("%8s", c.endereco.cep);
                    break;

                case 12:
                    fclose(arquivo);
                    return;

                default:
                    printf("Opcao invalida!\n");
                    fclose(arquivo);
                    return;
            }

            fseek(arquivo, -(long)sizeof(Cliente), SEEK_CUR);

            fwrite(&c, sizeof(Cliente), 1, arquivo);

            printf("\nCliente alterado com sucesso!\n");

            fclose(arquivo);
            return;
        }
    }

    printf("Cliente nao encontrado!\n");

    fclose(arquivo);
}

void excluirCliente() {
    FILE *arquivo = fopen("Cliente.dat", "rb");
    FILE *temporario = fopen("Cliente.tmp", "wb");

    if (arquivo == NULL || temporario == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    int id;
    int encontrado = 0;

    Cliente c;

    consultarCliente();

    printf("\nDigite o ID do cliente que deseja excluir: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1)
    {
        if (c.id == id)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&c, sizeof(Cliente), 1, temporario);
        }
    }

    fclose(arquivo);
    fclose(temporario);

    remove("Cliente.dat");
    rename("Cliente.tmp", "Cliente.dat");

    if (encontrado)
        printf("Cliente excluido com sucesso!\n");
    else
        printf("Cliente nao encontrado!\n");
}

void cadastrarItens(Descricao itens[]) {
    printf("\n### CADASTRAR ITENS ###\n");

    for (int i = 0; i < 6; i++)
    {
        printf("\nItem %d\n", i + 1);

        printf("Descricao do item: ");
        scanf(" %20[^\n]", itens[i].descricaoItem);

        printf("Quantidade do item: ");
        scanf("%d", &itens[i].quantidadePedido);

        printf("Valor unitario: R$ ");
        scanf("%f", &itens[i].valorItem);
    }
}

float calcularTotal(Descricao itens[]) {
    float total = 0;

    for (int i = 0; i < 6; i++)
    {
        total += itens[i].quantidadePedido *
                 itens[i].valorItem;
    }

    return total;
}

int existePedido(char numero[]) {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
        return 0;

    Pedido p;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        if (strcmp(p.numeroPedido, numero) == 0)
        {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);

    return 0;
}


void inserirPedido() {
    FILE *arquivo = fopen("Pedidos.dat", "ab");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir Pedidos.dat!\n");
        return;
    }

    Pedido p;

    printf("\n### CADASTRAR PEDIDO ###\n");

    printf("Numero do pedido: ");
    scanf("%9s", p.numeroPedido);

    if (existePedido(p.numeroPedido))
    {
        printf("Esse pedido ja existe!\n");
        fclose(arquivo);
        return;
    }

    printf("CNPJ do cliente: ");
    scanf("%14s", p.cnpj);

    if (!existeCliente(p.cnpj))
    {
        printf("Cliente nao encontrado!\n");
        fclose(arquivo);
        return;
    }

    printf("Data da compra (DD/MM/AAAA): ");
    scanf("%10s", p.data);

    printf("Data da entrega (DD/MM/AAAA): ");
    scanf("%10s", p.dataEntrega);

    printf("Previsao estimada (dias): ");
    scanf("%d", &p.previsao);

    cadastrarItens(p.itens);

    p.totalPedido = calcularTotal(p.itens);

    printf("\nTotal do pedido: R$ %.2f\n", p.totalPedido);

    printf("Forma de pagamento (a vista/duplicata): ");
    scanf("%19s", p.formaPagamento);

    fwrite(&p, sizeof(Pedido), 1, arquivo);

    fclose(arquivo);

    printf("\nPedido cadastrado com sucesso!\n");
}

void mostrarPedido(Pedido p) {
    printf("\n========================================\n");

    printf("Numero do pedido: %s\n", p.numeroPedido);
    printf("CNPJ: %s\n", p.cnpj);
    printf("Data do pedido: %s\n", p.data);
    printf("Data da entrega: %s\n", p.dataEntrega);
    printf("Previsao: %d dias\n", p.previsao);

    printf("\nItens:\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d - %s | Qtd: %d | Valor: R$ %.2f\n",
               i + 1,
               p.itens[i].descricaoItem,
               p.itens[i].quantidadePedido,
               p.itens[i].valorItem);
    }

    printf("\nTotal: R$ %.2f\n", p.totalPedido);
    printf("Forma de pagamento: %s\n", p.formaPagamento);
}


void consultarPedidosCliente() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    char cnpj[15];

    printf("Digite o CNPJ do cliente: ");
    scanf("%14s", cnpj);

    Pedido p;
    int encontrado = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        if (strcmp(p.cnpj, cnpj) == 0)
        {
            mostrarPedido(p);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum pedido encontrado para esse cliente.\n");

    fclose(arquivo);
}


void consultarTodosPedidos() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    Pedido p;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        mostrarPedido(p);
    }

    fclose(arquivo);
}

void consultarPedidosEntreDatas() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    char dataInicial[11];
    char dataFinal[11];

    printf("Data inicial (DD/MM/AAAA): ");
    scanf("%10s", dataInicial);

    printf("Data final (DD/MM/AAAA): ");
    scanf("%10s", dataFinal);

    int inicial = converterData(dataInicial);
    int final = converterData(dataFinal);

    Pedido p;
    int encontrado = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        int dataPedido = converterData(p.data);

        if (dataPedido >= inicial && dataPedido <= final)
        {
            mostrarPedido(p);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum pedido encontrado nesse intervalo.\n");

    fclose(arquivo);
}

void consultarPedidosEntregues() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    char dataEntrada[11];

    printf("Mostrar pedidos entregues a partir de: ");
    scanf("%10s", dataEntrada);

    int dataInicial = converterData(dataEntrada);

    Pedido p;
    int encontrado = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        int dataEntrega = converterData(p.dataEntrega);

        if (dataEntrega >= dataInicial)
        {
            mostrarPedido(p);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum pedido encontrado.\n");

    fclose(arquivo);
}

void consultarPedidosAbertos() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    Pedido p;

    time_t agora = time(NULL);
    struct tm *dataAtual = localtime(&agora);

    int hoje =
        (dataAtual->tm_year + 1900) * 10000 +
        (dataAtual->tm_mon + 1) * 100 +
        dataAtual->tm_mday;

    int encontrado = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        int entrega = converterData(p.dataEntrega);

        if (entrega == 0 || entrega > hoje)
        {
            mostrarPedido(p);

            if (entrega > hoje)
                printf("STATUS: EM ABERTO - DENTRO DO PRAZO\n");
            else
                printf("STATUS: EM ABERTO\n");

            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("Nenhum pedido em aberto.\n");

    fclose(arquivo);
}

void mediaMensalCliente() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    char cnpj[15];

    printf("CNPJ do cliente: ");
    scanf("%14s", cnpj);

    float soma = 0;
    int quantidadePedidos = 0;

    Pedido p;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        if (strcmp(p.cnpj, cnpj) == 0)
        {
            soma += p.totalPedido;
            quantidadePedidos++;
        }
    }

    fclose(arquivo);

    if (quantidadePedidos == 0)
    {
        printf("Nenhum pedido encontrado para esse cliente.\n");
        return;
    }

    printf("\n### MEDIA DE COMPRAS ###\n");
    printf("Cliente: %s\n", cnpj);
    printf("Total comprado: R$ %.2f\n", soma);
    printf("Quantidade de pedidos: %d\n", quantidadePedidos);

    printf("Media por pedido: R$ %.2f\n",
           soma / quantidadePedidos);
}

void alterarPedido() {
    FILE *arquivo = fopen("Pedidos.dat", "r+b");

    if (arquivo == NULL)
    {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    char numero[10];

    printf("Numero do pedido que deseja alterar: ");
    scanf("%9s", numero);

    Pedido p;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        if (strcmp(p.numeroPedido, numero) == 0)
        {
            printf("\n1 - CNPJ\n");
            printf("2 - Data do pedido\n");
            printf("3 - Data da entrega\n");
            printf("4 - Previsao\n");
            printf("5 - Itens\n");
            printf("6 - Forma de pagamento\n");
            printf("7 - Voltar\n");

            int opcao;

            printf("O que deseja alterar? ");
            scanf("%d", &opcao);

            switch (opcao)
            {
                case 1:
                    printf("Novo CNPJ: ");
                    scanf("%14s", p.cnpj);
                    break;

                case 2:
                    printf("Nova data: ");
                    scanf("%10s", p.data);
                    break;

                case 3:
                    printf("Nova data de entrega: ");
                    scanf("%10s", p.dataEntrega);
                    break;

                case 4:
                    printf("Nova previsao: ");
                    scanf("%d", &p.previsao);
                    break;

                case 5:
                    cadastrarItens(p.itens);
                    p.totalPedido = calcularTotal(p.itens);
                    break;

                case 6:
                    printf("Nova forma de pagamento: ");
                    scanf("%19s", p.formaPagamento);
                    break;

                case 7:
                    fclose(arquivo);
                    return;

                default:
                    printf("Opcao invalida!\n");
                    fclose(arquivo);
                    return;
            }

            fseek(arquivo, -(long)sizeof(Pedido), SEEK_CUR);

            fwrite(&p, sizeof(Pedido), 1, arquivo);

            printf("Pedido alterado com sucesso!\n");

            fclose(arquivo);
            return;
        }
    }

    printf("Pedido nao encontrado!\n");

    fclose(arquivo);
}

void excluirPedido() {
    FILE *arquivo = fopen("Pedidos.dat", "rb");
    FILE *temporario = fopen("Pedidos.tmp", "wb");

    if (arquivo == NULL || temporario == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    char numero[10];

    printf("Numero do pedido que deseja excluir: ");
    scanf("%9s", numero);

    Pedido p;
    int encontrado = 0;

    while (fread(&p, sizeof(Pedido), 1, arquivo) == 1)
    {
        if (strcmp(p.numeroPedido, numero) == 0)
        {
            encontrado = 1;
        }
        else
        {
            fwrite(&p, sizeof(Pedido), 1, temporario);
        }
    }

    fclose(arquivo);
    fclose(temporario);

    remove("Pedidos.dat");
    rename("Pedidos.tmp", "Pedidos.dat");

    if (encontrado)
        printf("Pedido excluido com sucesso!\n");
    else
        printf("Pedido nao encontrado!\n");
}

void menuClientes() {
    int opcao;

    do
    {
        printf("\n====================================\n");
        printf("           MENU CLIENTES\n");
        printf("====================================\n");

        printf("1 - Inserir cliente\n");
        printf("2 - Alterar cliente\n");
        printf("3 - Excluir cliente\n");
        printf("4 - Consultar clientes\n");
        printf("5 - Consultar detalhes\n");
        printf("0 - Voltar\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
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

            case 5:
                consultarClienteDois();
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}

void menuPedidos() {
    int opcao;

    do
    {
        printf("\n====================================\n");
        printf("           MENU PEDIDOS\n");
        printf("====================================\n");

        printf("1 - Inserir pedido\n");
        printf("2 - Alterar pedido\n");
        printf("3 - Excluir pedido\n");
        printf("4 - Todos os pedidos de um cliente\n");
        printf("5 - Todos os pedidos\n");
        printf("6 - Pedidos entre duas datas\n");
        printf("7 - Pedidos entregues a partir de uma data\n");
        printf("8 - Pedidos em aberto\n");
        printf("9 - Media de compras do cliente\n");
        printf("0 - Voltar\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
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
                consultarPedidosEntreDatas();
                break;

            case 7:
                consultarPedidosEntregues();
                break;

            case 8:
                consultarPedidosAbertos();
                break;

            case 9:
                mediaMensalCliente();
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

    do
    {
        printf("\n\n====================================\n");
        printf("       CONTROLE DE CLIENTES\n");
        printf("====================================\n");

        printf("1 - Clientes\n");
        printf("2 - Pedidos\n");
        printf("0 - Sair\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                menuClientes();
                break;

            case 2:
                menuPedidos();
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}