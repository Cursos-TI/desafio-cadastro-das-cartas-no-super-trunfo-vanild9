#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];           // Estado da carta (ex: SP, RJ)
    char codigo[10];          // Código da carta
    char cidade[50];          // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área em km²
    float pib;                // PIB em milhões
    int pontos_turisticos;    // Número de pontos turísticos
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade(Carta carta) {
    return (float)carta.populacao / carta.area; // População dividida pela área
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(Carta carta) {
    return carta.pib / carta.populacao; // PIB dividido pela população
}

// Função para comparar as cartas pelo atributo população
void comparar_cartas(Carta carta1, Carta carta2) {
    // Exibe a comparação pelo atributo população
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - São Paulo (SP): %d\n", carta1.populacao);
    printf("Carta 2 - Rio de Janeiro (RJ): %d\n", carta2.populacao);

    // Determina a carta vencedora (maior população vence)
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!.\n", carta1.cidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!.\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!.\n");
    }
}

int main() {
    // Declaração das duas cartas
    Carta carta1, carta2;

    // Dados da Carta 1 - São Paulo
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "SP001");
    strcpy(carta1.cidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699000.0;
    carta1.pontos_turisticos = 50;

    // Dados da Carta 2 - Rio de Janeiro
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "RJ001");
    strcpy(carta2.cidade, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1182.30;
    carta2.pib = 337000.0;
    carta2.pontos_turisticos = 45;

    // Exibição dos dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f milhões\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", calcular_densidade(carta1));
    printf("PIB per capita: %.2f milhões/hab\n", calcular_pib_per_capita(carta1));

    // Exemplo de como formatar a saída para corresponder exatamente à fornecida
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f milhões\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", calcular_densidade(carta2));
    printf("PIB per capita: %.2f milhões/hab\n", calcular_pib_per_capita(carta2));

    // Compara as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}