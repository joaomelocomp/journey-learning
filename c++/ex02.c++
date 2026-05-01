// 01. Escreva um programa que pede o raio de um círculo, e em seguida exiba o perímetro e área do círculo.

#include <iostream>
using namespace std;

int perimetro(int raio)
{
    double pi = 3.14;
    return (2 * pi) * raio;
}

int main()
{
    int r= 0;
    cout << "digite o raio ";
    cin >> r;

    cout << perimetro(r);
    
    return 0;
}