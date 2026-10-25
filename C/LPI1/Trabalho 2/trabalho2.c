#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int codigo;
    char nome[50];
} Garcom;

typedef struct Pedido {
    int codigo;
    int quantidade;
    struct Pedido *prox;
} Pedido;

typedef struct Mesa {
    int numero;
    int codigoGarcom;
    float total;
    Pedido *pedidos;
    struct Mesa *ant;
    struct Mesa *prox;
} Mesa;

void inserirProduto() {
    FILE *arquivo;
    Produto p;

    arquivo = fopen("produtos.dat", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Codigo: ");
    scanf("%d", &p.codigo);

    printf("Nome: ");
    scanf(" %49[^\n]", p.nome);

    printf("Preco: ");
    scanf("%f", &p.preco);

    fwrite(&p, sizeof(Produto), 1, arquivo);

    fclose(arquivo);
}

void consultarProdutos() {
    FILE *arquivo;
    Produto p;

    arquivo = fopen("produtos.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fread(&p, sizeof(Produto), 1, arquivo) == 1) {
        printf("\nCodigo: %d", p.codigo);
        printf("\nNome: %s", p.nome);
        printf("\nPreco: %.2f\n", p.preco);
    }

    fclose(arquivo);
}

void inserirGarcom() {
    FILE *arquivo;
    Garcom g;

    arquivo = fopen("garcons.dat", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Codigo do garcom: ");
    scanf("%d", &g.codigo);

    printf("Nome do garcom: ");
    scanf(" %49[^\n]", g.nome);

    fwrite(&g, sizeof(Garcom), 1, arquivo);

    fclose(arquivo);
}

void consultarGarcons() {
    FILE *arquivo;
    Garcom g;

    arquivo = fopen("garcons.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fread(&g, sizeof(Garcom), 1, arquivo) == 1) {
        printf("\nCodigo: %d", g.codigo);
        printf("\nNome: %s\n", g.nome);
    }

    fclose(arquivo);
}

void inserirMesa(Mesa **inicio) {
    Mesa *nova;
    Mesa *aux;

    nova = malloc(sizeof(Mesa));

    if (nova == NULL) {
        printf("Erro de memoria.\n");
        return;
    }

    printf("Numero da mesa: ");
    scanf("%d", &nova->numero);

    printf("Codigo do garcom: ");
    scanf("%d", &nova->codigoGarcom);

    nova->total = 0;
    nova->pedidos = NULL;
    nova->ant = NULL;
    nova->prox = NULL;

    if (*inicio == NULL) {
        *inicio = nova;
        return;
    }

    aux = *inicio;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = nova;
    nova->ant = aux;
}

Mesa *buscarMesa(Mesa *inicio, int numero) {
    Mesa *aux;

    aux = inicio;

    while (aux != NULL) {
        if (aux->numero == numero) {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}

float buscarPreco(int codigo) {
    FILE *arquivo;
    Produto p;

    arquivo = fopen("produtos.dat", "rb");

    if (arquivo == NULL) {
        return 0;
    }

    while (fread(&p, sizeof(Produto), 1, arquivo) == 1) {
        if (p.codigo == codigo) {
            fclose(arquivo);
            return p.preco;
        }
    }

    fclose(arquivo);

    return 0;
}

void inserirPedido(Mesa *inicio) {
    int numero;
    int codigo;
    int quantidade;
    float preco;

    Mesa *mesa;
    Pedido *novo;
    Pedido *aux;

    printf("Numero da mesa: ");
    scanf("%d", &numero);

    mesa = buscarMesa(inicio, numero);

    if (mesa == NULL) {
        printf("Mesa nao encontrada.\n");
        return;
    }

    printf("Codigo do pedido: ");
    scanf("%d", &codigo);

    preco = buscarPreco(codigo);

    if (preco == 0) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    novo = malloc(sizeof(Pedido));

    if (novo == NULL) {
        printf("Erro de memoria.\n");
        return;
    }

    novo->codigo = codigo;
    novo->quantidade = quantidade;
    novo->prox = NULL;

    if (mesa->pedidos == NULL) {
        mesa->pedidos = novo;
    } else {
        aux = mesa->pedidos;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    mesa->total = mesa->total + preco * quantidade;

    printf("Pedido inserido.\n");
}

void consultarMesas(Mesa *inicio) {
    Mesa *m;
    Pedido *p;

    for (m = inicio; m != NULL; m = m->prox) {
        printf("\nMesa: %d | Garcom: %d | Total: %.2f", m->numero, m->codigoGarcom, m->total);

        for (p = m->pedidos; p != NULL; p = p->prox) {
            printf("\n   Produto: %d | Qtd: %d", p->codigo, p->quantidade);
        }

        printf("\n");
    }
}

void liberarMesas(Mesa *inicio) {
    Mesa *m;
    Pedido *p;

    while (inicio != NULL) {
        m = inicio;
        inicio = inicio->prox;

        while (m->pedidos != NULL) {
            p = m->pedidos;
            m->pedidos = p->prox;
            free(p);
        }

        free(m);
    }
}

int main() {
    Mesa *inicio = NULL;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir produto\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Inserir garcom\n");
        printf("4 - Consultar garcons\n");
        printf("5 - Inserir mesa\n");
        printf("6 - Inserir pedido\n");
        printf("7 - Consultar mesas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcao = -1;
        }

        switch (opcao) {
            case 1: inserirProduto(); break;
            case 2: consultarProdutos(); break;
            case 3: inserirGarcom(); break;
            case 4: consultarGarcons(); break;
            case 5: inserirMesa(&inicio); break;
            case 6: inserirPedido(inicio); break;
            case 7: consultarMesas(inicio); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberarMesas(inicio);

    return 0;
}