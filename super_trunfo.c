#include <stdio.h>
#include <string.h>

int main() {
    
    char estado1[3];
    char nome_cidade1[50];
    long int populacao1;
    float area1;
    float pib1;
    float densidade_pop1;
    float pib_capita1;

    char estado2[3];
    char nome_cidade2[50];
    long int populacao2;
    float area2;
    float pib2;
    float densidade_pop2;
    float pib_capita2;
    
    const double BILHAO = 1000000000.0;
    
    int atributo_escolhido = 1; 

    // DADOS DAS CARTAS
    
    // CARTA 1
    strcpy(estado1, "SP");
    strcpy(nome_cidade1, "Sao Paulo");
    populacao1 = 12300000;
    area1 = 1521.11;
    pib1 = 699.28;
    
    // CARTA 2
    strcpy(estado2, "RJ");
    strcpy(nome_cidade2, "Rio de Janeiro");
    populacao2 = 6700000;
    area2 = 1200.25;
    pib2 = 300.50;
    
    // CÁLCULOS
    
    // CARTA 1
    densidade_pop1 = (float)populacao1 / area1;
    pib_capita1 = (pib1 * BILHAO) / populacao1; 
    
    // CARTA 2
    densidade_pop2 = (float)populacao2 / area2;
    pib_capita2 = (pib2 * BILHAO) / populacao2; 

    // COMPARAÇÃO
    
    printf("\n\n=== RESULTADO DA BATALHA ===\n");
    
    if (atributo_escolhido == 1) {
        
        // COMPARAÇÃO POPULAÇÃO (MAIOR VENCE)
        printf("Comparacao de cartas (Atributo: População):\n");
        printf("Carta 1 - %s (%s): %ld\n", nome_cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %ld\n", nome_cidade2, estado2, populacao2);
        
        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: EMPATE!\n");
        }
    } 
    else if (atributo_escolhido == 4) {
        
        // COMPARAÇÃO DENSIDADE POPULACIONAL (MENOR VENCE)
        printf("Comparacao de cartas (Atributo: Densidade Populacional):\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", nome_cidade1, estado1, densidade_pop1);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", nome_cidade2, estado2, densidade_pop2);
        
        if (densidade_pop1 < densidade_pop2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nome_cidade1);
        } else if (densidade_pop2 < densidade_pop1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nome_cidade2);
        } else {
            printf("Resultado: EMPATE!\n");
        }
    } 
    else {
         printf("Atributo escolhido não está configurado para comparacao neste codigo.\n");
    }

    printf("==========================================\n");
    
    return 0;
}