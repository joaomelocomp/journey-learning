// 01. Escreva um programa que pede o raio de um círculo, e em seguida exiba o perímetro e área do círculo.

#include <stdio.h>

int perimetro(int raio){
    double pi = 3.14;
    return (2*pi)*raio;
}

int area(int raio){
    double pi = 3.14;
    return pi * raio * raio;
}
int main(){
    int r = 0;
    printf("digite o raio ");
    scanf("%d", &r);

    int p = perimetro(r);
    int a = area(r);

    printf("resultado: P %d A %d\n", p, a);

    return 0;
}