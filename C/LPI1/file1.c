/*1) Escreva um programa em C que encontre o menor inteiro positivo n que atenda as seguintes condições :
n / 3 = x inteiro e resto 2
n / 5 = y inteiro e resto 3
n / 7 = z inteiro e resto 4 
*/

#include <stdio.h>
#include <stdbool.h>

void menorInteiro () {
    bool busca = false;
    int i = 0;
    while (busca == false) {
        i++;

        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 4) {
            busca = true;
        }  
    }
    printf("%d", i);
}

int main () {
    menorInteiro();

    return 0;
}