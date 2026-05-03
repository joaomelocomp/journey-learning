// Peça um número N e calcule a soma de 1 até N.

#include <stdio.h>

int main(){
    int n = 0;
    int soma = 0;

    printf("Digite um número ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        soma = soma + i;
    }

    printf("%d", soma);

    return 0;
}