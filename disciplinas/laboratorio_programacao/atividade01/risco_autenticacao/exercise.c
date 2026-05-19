// Playground if / else
#include <stdio.h>

int main() {
    float falhas, tentativas, taxa, risco;

    printf("Digite o número de falhas: ");
    scanf("%f", &falhas);

    printf("Digite o número de tentativas: ");
    scanf("%f", &tentativas);

    taxa = (falhas / tentativas) * 100;
    risco = (taxa * 0.3) + (falhas * 2);

    if (tentativas == 0) {
        printf("Erro: tentativas nao pode ser 0\n");
        return 1;
    }

    if (risco < 10) {
        printf("Normal\n");
    } else if (risco >= 10 && risco <= 25) {
        printf("Suspeito\n");
    } else if (risco > 25){
        printf("Ataque\n");
    }
}


