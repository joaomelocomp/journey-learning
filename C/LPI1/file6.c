/*6) Um motorista acaba de retornar de um feriado prolongado. Em cada parada de reabastecimento ele
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados relativos à compra de
gasolina e calcular :
a) a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento;
b) a quilometragem obtida por litro de gasolina em toda a viagem
c) custo do combustível por quilometro rodado em toda a viagem */

#include <stdio.h>

int main() {
    int n;
    
    printf("Quantos reabastecimentos foram feitos? ");
    scanf("%d", &n);

    float odometro = 0;
    float gasolina = 0;
    float preco = 0;

    float odometroAnterior = 0;
    float totalGasolina = 0;
    float totalPreco = 0;
    float totalKm = 0;

    for (int i = 1; i <= n; i++) {
        printf("\nReabastecimento %d\n", i);

        printf("Odometro: ");
        scanf("%f", &odometro);

        printf("Gasolina comprada: ");
        scanf("%f", &gasolina);

        printf("Preco pago: ");
        scanf("%f", &preco);

        if (i > 1) {
            float km = odometro - odometroAnterior;
            float kmPorLitro = km / gasolina;

            printf("Quilometragem por litro: %.2f km/l\n", kmPorLitro);

            totalKm += km;
        }

        totalGasolina += gasolina;
        totalPreco += preco;

        odometroAnterior = odometro;
    }

    printf("\nQuilometragem total: %.2f km\n", totalKm);
    printf("Quilometragem por litro na viagem: %.2f km/l\n",
           totalKm / totalGasolina);
    printf("Custo por quilometro: R$ %.2f/km\n",
           totalPreco / totalKm);

    return 0;
}