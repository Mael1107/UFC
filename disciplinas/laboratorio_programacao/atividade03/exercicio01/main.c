// 1 Exercícios avançados propostos - 
// Bloco avançado — switch-case e while em cenários de Segurança da Informação

#include <stdio.h>

int main() {
    int opcao = 0;
    int quant_falhas_auth = 0, quant_pico_traf = 0, quant_indipos_serv = 0;
    int score = 0;

    while (opcao != 5) {

        printf("------------------------------\n");
        printf("Escolha uma opção abaixo:\n");
        printf("1 - Registrar falha de autenticação\n");
        printf("2 - Registrar pico de tráfego\n");
        printf("3 - Registrar indisponibildade de serviço\n");
        printf("4 - Exibir resumo parcial\n");
        printf("5 - Encerrar análise\n");
        printf("------------------------------\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                quant_falhas_auth += 1;
                printf("Falha de autenticação registrada.\n");
                break;
            case 2:
                quant_pico_traf += 1;
                printf("Pico de tráfego registrado.\n");
                break;
            case 3:
                quant_indipos_serv += 1;
                printf("Indisponibilidade do servço registrada.\n");
                break;
            case 4:
                printf("Resumo parcial:\n");
                printf("Falhas de autenticação: %d\n", quant_falhas_auth);
                printf("Picos de tráfego: %d\n", quant_pico_traf);
                printf("Indisponibilidades: %d\n", quant_indipos_serv);
                score = (quant_falhas_auth * 2) + (quant_pico_traf * 3) + (quant_indipos_serv * 5);
                printf("Score de risco: %d\n", score);
                break;
            case 5:
                printf("Encerrado...\n");
                break;

        }
    }
}