#include <stdio.h>

int main(){
    int numero = 0;
    int ultimo_digito = 0;
    int numero_novo = 0;

    printf("numero ");
    scanf("%d", &numero);

    while (numero > 0){
        ultimo_digito = numero % 10;
        numero_novo = numero_novo * 10 + ultimo_digito;
        numero = numero / 10;
    }
    
    printf("%d", numero_novo);

    return 0;
}