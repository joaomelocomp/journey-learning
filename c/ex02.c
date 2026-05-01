// 01. Escreva um programa que pede o raio de um círculo, e em seguida exiba o perímetro e área do círculo.

#include <stdio.h>

int perimetro(int raio){
    double pi = 3.14;
    return (2*pi)*raio;
}

int main(){
    int r = 0;
    printf("digite o raio ");
    scanf("%d", &r);

    int resultado = perimetro(r);
    printf("%d", resultado);

    return 0;
}