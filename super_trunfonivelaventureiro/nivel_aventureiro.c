#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura (struct) para a Carta de País
typedef struct {
    char nome[50];
    int populacao; // Em milhões de habitantes (para simplificar)
    float area;    // Em km² (para simplificar)
    float pib;     // Em trilhões de dólares (para simplificar)
    int pontosTuristicos;
    float densidadeDemografica; // Populacao / Area
} CartaPais;

// Função para exibir o menu e obter a escolha do jogador
int exibirMenu() {
    int escolha;
    printf("\n--- Escolha o Atributo de Comparação ---\n");
    printf("1. População (Vence o MAIOR)\n");
    printf("2. Área (Vence o MAIOR)\n");
    printf("3. PIB (Vence o MAIOR)\n");
    printf("4. Pontos Turísticos (Vence o MAIOR)\n");
    printf("5. Densidade Demográfica (Vence o MENOR!)\n");
    printf("6. Sair\n");
    printf("-------------------------------------------\n");
    printf("Digite sua escolha (1-6): ");
    
    // Verifica se a leitura foi bem-sucedida
    if (scanf("%d", &escolha) != 1) {
        // Limpa o buffer de entrada em caso de erro (ex: usuário digitou texto)
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // Retorna 0 para indicar uma escolha inválida/erro
    }
    return escolha;
}

// Função principal de comparação com lógica aninhada
void compararCartas(CartaPais carta1, CartaPais carta2, int atributo) {
    float valor1 = 0;
    float valor2 = 0;
    char nomeAtributo[50] = "";
    int regraInversa = 0; // 0 para Maior Ganha, 1 para Menor Ganha

    // Usando switch para selecionar o atributo e definir os valores a serem comparados
    switch (atributo) {
        case 1: // População
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            strcpy(nomeAtributo, "População (em milhões)");
            break;
        case 2: // Área
            valor1 = carta1.area;
            valor2 = carta2.area;
            strcpy(nomeAtributo, "Área (em km²)");
            break;
        case 3: // PIB
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            strcpy(nomeAtributo, "PIB (em trilhões)");
            break;
        case 4: // Pontos Turísticos
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            strcpy(nomeAtributo, "Pontos Turísticos");
            break;
        case 5: // Densidade Demográfica (Regra Inversa!)
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            strcpy(nomeAtributo, "Densidade Demográfica");
            regraInversa = 1; // Ativa a regra inversa: Menor valor ganha
            break;
        default:
            printf("Erro: Opção de atributo inválida.\n");
            return;
    }

    // --- Exibição de Resultados e Lógica de Comparação Aninhada ---
    printf("\n*** Resultado da Comparação ***\n");
    printf("Atributo Comparado: %s\n", nomeAtributo);
    printf("  %s: %.2f\n", carta1.nome, valor1);
    printf("  %s: %.2f\n", carta2.nome, valor2);

    // Estrutura de Decisão Aninhada:
    // Nível 1: Verifica a regra de comparação (Normal ou Inversa)
    if (regraInversa == 0) { // Regra NORMAL: O MAIOR valor VENCE
        // Nível 2: Compara os valores
        if (valor1 > valor2) {
            printf("-> Vencedor: %s\n", carta1.nome);
        } else if (valor2 > valor1) {
            printf("-> Vencedor: %s\n", carta2.nome);
        } else {
            printf("-> Empate!\n");
        }
    } else { // Regra INVERSA (Densidade Demográfica): O MENOR valor VENCE
        // Nível 2: Compara os valores (com a lógica invertida)
        if (valor1 < valor2) {
            printf("-> Vencedor: %s\n", carta1.nome);
        } else if (valor2 < valor1) {
            printf("-> Vencedor: %s\n", carta2.nome);
        } else {
            printf("-> Empate!\n");
        }
    }
    printf("*********************************\n");
}

int main() {
    // --- CADASTRO DE CARTAS (Simplificado e Pré-definido) ---
    // Usando dados simplificados para teste
    CartaPais cartaA = {
        .nome = "Brasil",
        .populacao = 214, // milhões
        .area = 8515767.0, // km²
        .pib = 1.9, // trilhões
        .pontosTuristicos = 250,
        .densidadeDemografica = 25.13 // 214 / 8515767 * 1000000 (simplificado para 25.13 hab/km²)
    };

    CartaPais cartaB = {
        .nome = "Alemanha",
        .populacao = 83, // milhões
        .area = 357588.0, // km²
        .pib = 4.3, // trilhões
        .pontosTuristicos = 180,
        .densidadeDemografica = 232.09 // 83 / 357588 * 1000000 (simplificado para 232.09 hab/km²)
    };
    
    // Exibição inicial das cartas
    printf("Bem-vindo ao Super Trunfo de Países!\n");
    printf("Cartas em jogo:\n");
    printf("  [CARTA 1] %s\n", cartaA.nome);
    printf("  [CARTA 2] %s\n", cartaB.nome);
    
    int escolha;
    
    // Loop principal para o Menu Interativo
    while (1) {
        escolha = exibirMenu();
        
        if (escolha == 6) {
            printf("\nObrigado por jogar! Encerrando o programa.\n");
            break; // Sai do loop e encerra o programa
        }
        
        // --- Estrutura switch para processar a escolha do menu ---
        switch (escolha) {
            case 1: // População
            case 2: // Área
            case 3: // PIB
            case 4: // Pontos Turísticos
            case 5: // Densidade Demográfica
                compararCartas(cartaA, cartaB, escolha);
                break;
            case 0: // Captura erros de entrada não numérica (tratados em exibirMenu)
                printf("Entrada inválida. Por favor, digite apenas números de 1 a 6.\n");
                break;
            default: // Tratamento de opção inválida (Requisito Não Funcional - Segurança/Usabilidade)
                printf("Opção inválida. Por favor, escolha um número de 1 a 6.\n");
                break;
        }
    }

    return 0;
}