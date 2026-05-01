#include <iostream>
using namespace std;

int soma(int a, int b){
    return a + b;
}

int main(){
    int x = 0;
    int y = 0;

    cout << "Digite um numero: ";
    cin >> x;
    cout << "Digite outro numero: ";
    cin >> y;

    cout << soma(x, y);

    return 0;
}