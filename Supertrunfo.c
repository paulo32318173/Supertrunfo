#include <stdio.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcular_dados(Carta* carta) {
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar duas cartas
void comparar_cartas(Carta carta1, Carta carta2) {
    // Escolha do atributo para comparação (neste caso, população)
    printf("Comparando cartas...\n");
    printf("Atributo: População\n");

    // Determinar a carta vencedora
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    // Exibir os valores das duas cartas para o atributo escolhido
    printf("Carta 1 - %s: %d\n", carta1.nome, carta1.populacao);
    printf("Carta 2 - %s: %d\n", carta2.nome, carta2.populacao);
}

int main() {
    // Cadastro das cartas
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.1, 123456789, 10};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.5, 987654321, 5};

    // Calcular densidade populacional e PIB per capita
    calcular_dados(&carta1);
    calcular_dados(&carta2);

    // Exibir os dados das cartas
    printf("Carta 1:\n");
    printf("Nome: %s\n", carta1.nome);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Densidade Populacional: %.2f\n", carta1.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta1.pib_per_capita);

    printf("\nCarta 2:\n");
    printf("Nome: %s\n", carta2.nome);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Densidade Populacional: %.2f\n", carta2.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta2.pib_per_capita);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}