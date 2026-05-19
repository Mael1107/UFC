#include <stdio.h>

int totalEstoque(int quantidades[6]) {
    int total = 0;
    int maior = quantidades[0];

    for (int i = 0; i < 6; i++) {
        total += quantidades[i];

        if (quantidades[i] > maior) {
            maior = quantidades[i];
        }
    }
    return total;

} 

int maiorEstoque(int quantidades[6]) {
    int maior = quantidades[0];

    for (int i = 0; i < 6; i++) {
        if (quantidades[i] > maior) {
            maior = quantidades[i];
        }
    }

    return maior;
}

int main () {
    int quantidades_produtos[6];
    
    for(int i = 0; i < 6; i++) {
        printf("Digite a quantidade em estoque do %dº produto:\n", i + 1);
        scanf("%d", &quantidades_produtos[i]);
    }

    int total_estoque = totalEstoque(quantidades_produtos);
    int maior = maiorEstoque(quantidades_produtos);

    printf("Total em estoque:%d\n", total_estoque);
    printf("Maior estoque: %d\n", maior);
}