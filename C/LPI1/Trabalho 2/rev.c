#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int dado;
    struct Celula *ponteiro;
} Celula;

void insere (int d, Celula *p) {
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->dado = d;
    nova->ponteiro = p->ponteiro;
    p-> ponteiro = nova;
}

void imprime (Celula *prox) {
    Celula *c;

    for (c = prox->ponteiro; c != NULL; c = c->ponteiro) {
        printf("%d", c->dado);
    }
}

int main () {
    Celula *teste;

    teste = malloc(sizeof(Celula));
    teste->ponteiro = NULL;

    insere(10, teste);
    imprime(teste);
    return 0;
}