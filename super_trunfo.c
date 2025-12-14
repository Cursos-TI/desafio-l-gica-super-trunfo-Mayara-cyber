#include <stdio.h>
#include <string.h>

typedef long int long_int;

typedef struct {
    char nome_cidade[50];
    long_int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para obter a escolha do atributo (Simplificada)
int obter_escolha(const char* mensagem) {
    int escolha;
    printf("%s", mensagem);
    while (scanf("%d", &escolha) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        while (getchar() != '\n');
    }
    return escolha;
}

// Função principal de obtenção do valor
float obter_valor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        default: return 0.0;
    }
}

// Função para obter o nome do atributo (Simplificada)
char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "INVALIDO";
    }
}

int main() {
    
    Carta carta1;
    Carta carta2;
    const double BILHAO = 1000000000.0;
    int escolha1, escolha2;

    // DADOS DAS CARTAS
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699.28;
    carta1.pontos_turisticos = 50;

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

    // MENU INTERATIVO (2 ESCOLHAS)
    printf("\n>>> BATALHA FINAL DE SUPER TRUNFO <<<\n");
    printf("Escolha 2 atributos para a comparacao (1-6):\n");
    printf("1 - Populacao (Maior vence)\n");
    printf("2 - Area (Maior vence)\n");
    printf("3 - PIB (Maior vence)\n");
    printf("4 - Pontos Turisticos (Maior vence)\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per Capita (Maior vence)\n");
    printf("--------------------------------------\n");

    // ESCOLHA 1
    escolha1 = obter_escolha("Digite o 1º atributo (1-6): ");
    
    // TRATAMENTO SIMPLIFICADO DE ESCOLHA REPETIDA/INVÁLIDA
    do {
        escolha2 = obter_escolha("Digite o 2º atributo (1-6, diferente do 1º): ");
        if (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 6) {
            printf("Erro: Escolha invalida ou repetida. Tente novamente.\n");
        }
    } while (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 6);


    // VALORES E SOMA
    float c1_val1 = obter_valor(carta1, escolha1);
    float c2_val1 = obter_valor(carta2, escolha1);
    
    float c1_val2 = obter_valor(carta1, escolha2);
    float c2_val2 = obter_valor(carta2, escolha2);
    
    float soma1 = c1_val1 + c1_val2;
    float soma2 = c2_val1 + c2_val2;
    
    char *vencedor;

    // COMPARAÇÃO FINAL E EXIBIÇÃO
    
    printf("\n\n################ RESULTADO ################\n");
    printf("CARTA 1: %s\n", carta1.nome_cidade);
    printf("CARTA 2: %s\n", carta2.nome_cidade);
    printf("-------------------------------------------\n");
    
    printf("1º Atributo (%s):\n", nome_atributo(escolha1));
    printf("  C1: %.2f | C2: %.2f\n", c1_val1, c2_val1);
    
    printf("2º Atributo (%s):\n", nome_atributo(escolha2));
    printf("  C1: %.2f | C2: %.2f\n", c1_val2, c2_val2);
    
    printf("-------------------------------------------\n");
    printf("SOMA TOTAL:\n");
    printf("  C1 (%s): %.2f\n", carta1.nome_cidade, soma1);
    printf("  C2 (%s): %.2f\n", carta2.nome_cidade, soma2);
    
    printf("-------------------------------------------\n");

    // OPERADOR TERNÁRIO PARA O VENCEDOR (Requisito Mestre)
    vencedor = (soma1 > soma2) ? carta1.nome_cidade : 
               (soma2 > soma1) ? carta2.nome_cidade : "EMPATE";
               
    printf("VENCEDOR GERAL: %s\n", vencedor);

    printf("###########################################\n");
    
    return 0;
}
