// Playground if / else
#include <stdio.h>

int main() {
    float taxa, cpu_base, cpu_final, requisicoes, tempo;
    
    printf("Digite o numero de requisições: ");
    scanf("%f", &requisicoes);

    printf("Digite o tempo: ");
    scanf("%f", &tempo);

    if (tempo == 0) {
        printf("Tempo não pode ser igual a zero!\n");
        return 1;
    }

    printf("Digite a CPU base: ");
    scanf("%f", &cpu_base);

    taxa = requisicoes / tempo;
    cpu_final = cpu_base + (taxa * 0.2);

    if (cpu_final < 60) {
        printf("Estavel\n");
    } else if (cpu_final >= 60 && cpu_final <= 85) {
        printf("Alerta\n");
    } else if (cpu_final > 85) {
        printf("Crítico\n");
    }
}