// Playground: Programação em C aplicada a Sistemas
// 3. Tratamento de erros

#include <stdio.h>

int main() {
    int erro_number;

    printf("------------------------------\n");
    printf("1 - Falha na conexão\n");
    printf("2 - Erro de autenticação\n");
    printf("3 - Erro de Operação\n");
    printf("------------------------------\n");
    scanf("%d", &erro_number);

    switch(erro_number) {
        case 1:
            printf("Reinicie a conexão com a internet e tente novamente!\n");
            break;
        case 2:
            printf("Reinicie a página e tente novamente!\n");
            break;
        case 3:
            printf("Reinicie a página e tente novamente!\n");
            break;
        default:
            printf("Erro 404! Página não encontrada\n");
    }
}