/*12)Escrever um programa em C que leia um valor inteiro (limite na casa do milhar), e o imprima em forma de
caracteres, ou seja, por extenso. Ex. : 98 = noventa e oito.*/

#include <stdio.h>

void unidade(int numero) {

    if (numero == 1) printf("um");
    if (numero == 2) printf("dois");
    if (numero == 3) printf("tres");
    if (numero == 4) printf("quatro");
    if (numero == 5) printf("cinco");
    if (numero == 6) printf("seis");
    if (numero == 7) printf("sete");
    if (numero == 8) printf("oito");
    if (numero == 9) printf("nove");
}

void dezena(int numero) {

    if (numero == 10) printf("dez");
    if (numero == 11) printf("onze");
    if (numero == 12) printf("doze");
    if (numero == 13) printf("treze");
    if (numero == 14) printf("quatorze");
    if (numero == 15) printf("quinze");
    if (numero == 16) printf("dezesseis");
    if (numero == 17) printf("dezessete");
    if (numero == 18) printf("dezoito");
    if (numero == 19) printf("dezenove");
    if (numero == 20) printf("vinte");
    if (numero == 30) printf("trinta");
    if (numero == 40) printf("quarenta");
    if (numero == 50) printf("cinquenta");
    if (numero == 60) printf("sessenta");
    if (numero == 70) printf("setenta");
    if (numero == 80) printf("oitenta");
    if (numero == 90) printf("noventa");
}

int main () {

    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("zero");
    }

    else if (numero < 10) {
        unidade(numero);
    }

    else if (numero < 20) {
        dezena(numero);
    }

    else if (numero < 100) {

        dezena((numero / 10) * 10);

        if (numero % 10 != 0) {
            printf(" e ");
            unidade(numero % 10);
        }
    }

    return 0;
}