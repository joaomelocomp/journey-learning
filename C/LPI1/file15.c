/*15) O Departamento de trânsito do estado anotou dados de acidentes de trânsito no último ano. Para cada
motorista envolvido no acidente, tem-se as seguintes informações:
- Ano de nascimento;
- Sexo (M - Masculino, F - Feminino)
- Procedência ( 0 - Capital, 1 - Interior, 2 - Outro estado);
Faça um programa em C que :
a) Calcule a porcentagem de motoristas com menos de 21 anos;
b) Calcule quantas mulheres são da capital;
c) Calcule quantos motoristas do interior do estado tem idade maior que 60 anos;
d) Verifique se existe alguma mulher com idade maior que 60 anos;*/

#include <stdio.h>

int main () {

    int quantidade;
    int anoNascimento;
    int idade;

    int menores21 = 0;
    int mulheresCapital = 0;
    int interiorMais60 = 0;
    int mulherMais60 = 0;

    printf("Quantidade de motoristas: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {

        char sexo;
        int procedencia;

        printf("\nAno de nascimento: ");
        scanf("%d", &anoNascimento);

        printf("Sexo (M/F): ");
        scanf(" %c", &sexo);

        printf("Procedencia (0-Capital, 1-Interior, 2-Outro estado): ");
        scanf("%d", &procedencia);

        idade = 2026 - anoNascimento;

        if (idade < 21) {
            menores21++;
        }

        if (sexo == 'F' && procedencia == 0) {
            mulheresCapital++;
        }

        if (procedencia == 1 && idade > 60) {
            interiorMais60++;
        }

        if (sexo == 'F' && idade > 60) {
            mulherMais60 = 1;
        }
    }

    printf("\nPorcentagem com menos de 21 anos: %.2f%%\n",
           (menores21 * 100.0) / quantidade);

    printf("Mulheres da capital: %d\n", mulheresCapital);

    printf("Motoristas do interior com mais de 60 anos: %d\n",
           interiorMais60);

    if (mulherMais60 == 1) {
        printf("Existe mulher com mais de 60 anos.\n");
    } else {
        printf("Nao existe mulher com mais de 60 anos.\n");
    }

    return 0;
}