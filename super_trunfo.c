#include <stdio.h>
#include <string.h>

typedef long int long_int;

typedef struct {
    char estado[3];
    char nome_cidade[50];
    long_int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    
    float densidade_populacional;
    float pib_per_capita;
} Carta;

void exibir_resultado(char *atributo, float valor1, float valor2, Carta c1, Carta c2, int venceu_c1) {
    
    printf("\n--- RESULTADO DA RODADA ---\n");
    printf("Atributo escolhido: %s\n", atributo);
    printf("Carta 1 (%s): %.2f\n", c1.nome_cidade, valor1);
    printf("Carta 2 (%s): %.2f\n", c2.nome_cidade, valor2);

    if (valor1 == valor2) {
        printf("Resultado: EMPATE!\n");
    } else if (venceu_c1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome_cidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome_cidade);
    }
    printf("---------------------------\n");
}


int main() {
    
    Carta carta1;
    Carta carta2;
    const double BILHAO = 1000000000.0;
    int escolha_menu;

    // DADOS DAS CARTAS
    
    // CARTA 1
    strcpy(carta1.estado, "SP");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699.28;
    carta1.pontos_turisticos = 50;

    // CARTA 2
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6700000;
    carta2.area = 1200.25;
    carta2.pib = 300.50;
    carta2.pontos_turisticos = 30;

    // CÁLCULOS
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * BILHAO) / carta1.populacao; 

    carta2.densidade_populacional = (float)carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * BILHAO) / carta2.populacao; 


    // MENU INTERATIVO
    
    printf("\n>>> BATALHA DE SUPER TRUNFO <<<\n");
    printf("Escolha o atributo para a comparacao entre %s e %s:\n", carta1.nome_cidade, carta2.nome_cidade);
    printf("1 - Populacao (Maior vence)\n");
    printf("2 - Area (Maior vence)\n");
    printf("3 - PIB (Maior vence)\n");
    printf("4 - Pontos Turisticos (Maior vence)\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per Capita (Maior vence)\n");
    printf("--------------------------------------\n");
    printf("Digite sua escolha (1-6): ");
    
    if (scanf("%d", &escolha_menu) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    // LÓGICA DE COMPARAÇÃO
    
    float valor1, valor2;
    char atributo_nome[50];
    int carta1_vence = 0; 

    switch (escolha_menu) {
        
        case 1: 
            strcpy(atributo_nome, "Populacao");
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            
            if (valor1 > valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;
            
        case 2: 
            strcpy(atributo_nome, "Area");
            valor1 = carta1.area;
            valor2 = carta2.area;
            
            if (valor1 > valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;

        case 3: 
            strcpy(atributo_nome, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            
            if (valor1 > valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;
            
        case 4: 
            strcpy(atributo_nome, "Pontos Turisticos");
            valor1 = (float)carta1.pontos_turisticos;
            valor2 = (float)carta2.pontos_turisticos;
            
            if (valor1 > valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;

        case 5: 
            strcpy(atributo_nome, "Densidade Demografica");
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            
            // REGRA INVERTIDA: MENOR VALOR VENCE
            if (valor1 < valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;

        case 6: 
            strcpy(atributo_nome, "PIB per Capita");
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;

            if (valor1 > valor2) {
                carta1_vence = 1;
            } else {
                carta1_vence = 0;
            }
            break;
            
        default:
            printf("\nOpcao invalida! Escolha um numero entre 1 e 6.\n");
            return 1;
    }

    if (escolha_menu >= 1 && escolha_menu <= 6) {
        exibir_resultado(atributo_nome, valor1, valor2, carta1, carta2, carta1_vence);
    }
    
    return 0;
}
