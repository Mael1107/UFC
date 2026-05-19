// Playground: Programação em C aplicada a Sistemas
// 1. Classificação de usuário

#include <stdio.h>

int main() {
    int opcao;

    printf("------------------------------\n");
    printf("Qual seu tipo de usuário?\n");
    printf("1 - Administrador\n");
    printf("2 - Operador\n");
    printf("3 - Cliente\n");
    printf("------------------------------\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Bem-vindo, ADM.\n");
            break;
        case 2:
            printf("Bem-vindo, Operador.\n");
            break;
        case 3: 
            printf("Bem-vindo, Cliente.\n");
            break;
        default: 
            printf("Usuário não encontrado!");
    }
}