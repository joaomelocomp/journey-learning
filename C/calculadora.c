#include <stdio.h>

int somar(int a, int b)
{
    return a + b;
}

int subtrair(int a, int b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    return a * b;
}

int dividir (int a, int b)
{
    return a / b;
}

int main()
{
    int escolha = 0;
    int x, y = 0;

    printf("Digite um número: ");
    scanf("%d", &x);
    printf("Digite um número: ");
    scanf("%d", &y);

    printf
    (
        "Selecione seu operador!\n"
        "1 - Somar\n"
        "2 - Subtrair\n"
        "3 - Multiplicar\n"
        "4 - Dividir\n"
    );

    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        int q = somar(x, y);
        printf("%d", q);
        break;

    case 2:
        int w = subtrair(x, y);
        printf("%d", w);
        break;

    case 3:
        int e = multiplicar(x, y);
        printf("%d", e);
        break;

    case 4:
        int r = subtrair(x, y);
        printf("%d", r);
        break;
    
    default:
        break;
    }

    return 0;
}