// Playground: Programação em C aplicada a Sistemas
// Menu

#include <stdio.h>

int main() {
    int opcao;

    printf("------------------------------\n");
    printf("Escolha uma das opções abaixo:\n");
    printf("1 - Login\n");
    printf("2 - Operações\n");
    printf("3 - Sair\n");
    printf("------------------------------\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Modulo de Login\n");
            break;
        case 2:
            printf("Modulo de Operações\n");
            break;
        case 3:
            printf("Encerrando...\n");
            break;
        default: 
            printf("Operação Inválida!\n");
    }
}