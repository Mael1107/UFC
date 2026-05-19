#include <stdio.h>

float calcularMedia(float soma) {
    return soma / 5;
}

int main() {
    float notas[5], soma = 0, media;
    int tamanho = 0 , aprovados = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite a nota do %dº aluno:\n", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];

        if (notas[i] >= 6) {
            aprovados++;
        }
    }

    media = calcularMedia(soma);

    printf("Média geral: %.1f\n", media);
    printf("Quantidade de aprovados: %d\n", aprovados);
}