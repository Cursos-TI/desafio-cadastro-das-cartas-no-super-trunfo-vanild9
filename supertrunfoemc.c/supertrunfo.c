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

// Função para obter o valor de um atributo com base na escolha
float obter_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return calcular_densidade(carta);
        case 5: return calcular_pib_per_capita(carta);
        default: return 0.0; // Caso inválido
    }
}

// Função para obter o nome do atributo
const char* obter_nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Populacional";
        case 5: return "PIB per capita";
        default: return "Desconhecido";
    }
}

// Função para exibir o menu de atributos
void exibir_menu_atributos(int atributo_excluido) {
    printf("\nEscolha um atributo:\n");
    if (atributo_excluido != 1) printf("1 - População\n");
    if (atributo_excluido != 2) printf("2 - Área\n");
    if (atributo_excluido != 3) printf("3 - PIB\n");
    if (atributo_excluido != 4) printf("4 - Densidade Populacional\n");
    if (atributo_excluido != 5) printf("5 - PIB per capita\n");
    printf("Digite o número do atributo: ");
}

// Função para validar a escolha do atributo
int validar_atributo(int escolha, int atributo_excluido) {
    if (escolha < 1 || escolha > 5 || escolha == atributo_excluido) {
        printf("Escolha inválida! Tente novamente.\n");
        return 0;
    }
    return 1;
}

// Função para comparar as cartas com base em dois atributos
void comparar_cartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    // Obtém os valores dos atributos
    float valor1_carta1 = obter_valor_atributo(carta1, atributo1);
    float valor2_carta1 = obter_valor_atributo(carta1, atributo2);
    float valor1_carta2 = obter_valor_atributo(carta2, atributo1);
    float valor2_carta2 = obter_valor_atributo(carta2, atributo2);

    // Calcula a soma dos atributos
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Exibe os resultados da comparação
    printf("\nComparação de cartas:\n");
    printf("Atributo 1: %s\n", obter_nome_atributo(atributo1));
    printf("  %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor1_carta1);
    printf("  %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor1_carta2);
    printf("Atributo 2: %s\n", obter_nome_atributo(atributo2));
    printf("  %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor2_carta1);
    printf("  %s (%s): %.2f\n", carta2.cidade, carta2.estado, valor2_carta2);
    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.cidade, soma_carta1);
    printf("  %s: %.2f\n", carta2.cidade, soma_carta2);

    // Determina o vencedor usando operador ternário
    const char* resultado = (soma_carta1 > soma_carta2) ? "Carta 1 venceu!" :
                            (soma_carta1 < soma_carta2) ? "Carta 2 venceu!" : "Empate!";
    printf("Resultado: %s (%s) %s\n", 
           soma_carta1 > soma_carta2 ? carta1.cidade : 
           soma_carta1 < soma_carta2 ? carta2.cidade : "Nenhuma",
           soma_carta1 > soma_carta2 ? carta1.estado : 
           soma_carta1 < soma_carta2 ? carta2.estado : "",
           resultado);
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

    // Exibição dos dados da Carta 2
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

    // Escolha dos atributos
    int atributo1, atributo2;
    do {
        exibir_menu_atributos(0); // Primeiro atributo, nenhum excluído
        scanf("%d", &atributo1);
    } while (!validar_atributo(atributo1, 0));

    do {
        exibir_menu_atributos(atributo1); // Segundo atributo, exclui o primeiro
        scanf("%d", &atributo2);
    } while (!validar_atributo(atributo2, atributo1));

    // Compara as cartas com base nos atributos escolhidos
    comparar_cartas(carta1, carta2, atributo1, atributo2);

    return 0;
}