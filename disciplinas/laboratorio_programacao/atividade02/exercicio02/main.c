// Playground: Programação em C aplicada a Sistemas
// 2.Modulo de Operações

#include <stdio.h>

int main() {
    int operacao;
    float num1, num2;

    printf("------------------------------\n");
    printf("Escolha uma operação abaixo:\n\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("------------------------------\n");
    scanf("%d", &operacao);

    printf("-------------NÚMEROS--------------\n");
    printf("Digite o 1º número:\n");
    scanf("%f", &num1);

    printf("Digite o 2º número:\n");
    scanf("%f", &num2);

    switch(operacao) {
        case 1:
            printf("-------------SOMA--------------\n");
            printf("O resultado da operação é: %.1f\n", num1 + num2);
            printf("------------------------------\n");
            break;
        case 2:
            printf("-------------SUBTRAÇÃO-------------\n");
            printf("O resultado da operação é: %.1f\n", num1 - num2);
            printf("------------------------------\n");
            break;
        case 3:
            printf("-------------MULTIPLICAÇÃO-------------\n");
            printf("O resultado da operação é: %.1f\n", num1 * num2);
            printf("------------------------------\n");
            break;
        case 4:
            printf("-------------DIVISÃO-------------\n");
            printf("O resultado da operação é: %.1f\n", num1 / num2);
            printf("------------------------------\n");
            break;
    }
    
}

