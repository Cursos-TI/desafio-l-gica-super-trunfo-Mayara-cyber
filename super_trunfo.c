#include <stdio.h>

int main() {
    // Desafio Super Trunfo - Países
    // Cadastro das Cartas e Comparacao

    // Declaracao das variaveis da Carta 1
    char estado1;
    char codigo1[20];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;

    // Declaracao das variaveis da Carta 2
    char estado2;
    char codigo2[20];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    // --- Cadastro da Carta 1 ---
    printf("Digite os dados da Carta 1:\n");
    
    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf("%s", nomeCidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Calculos da Carta 1
    densidade1 = (float) populacao1 / area1;
    pibPerCapita1 = pib1 / (float) populacao1;


    // --- Cadastro da Carta 2 ---
    printf("\nDigite os dados da Carta 2:\n");
    
    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf("%s", nomeCidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Calculos da Carta 2
    densidade2 = (float) populacao2 / area2;
    pibPerCapita2 = pib2 / (float) populacao2;


    // --- Comparacao das Cartas ---
    // O atributo escolhido para comparar foi a Populacao
    
    printf("\n--- Comparacao de Cartas ---\n");
    printf("Atributo: Populacao\n");
    printf("Carta 1 - %s: %d\n", nomeCidade1, populacao1);
    printf("Carta 2 - %s: %d\n", nomeCidade2, populacao2);

    // Se a populacao da carta 1 for maior, ela vence
    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    }

    return 0;
}