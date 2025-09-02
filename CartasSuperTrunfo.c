#include <stdio.h>
#include <string.h>

int main() {
   char codigo1[4], codigo2[4];
   int populacao1, populacao2;
   float area1, area2, pib1, pib2;
   int pontos_turisticos1, pontos_turisticos2;

   // Cadastro da primeira carta
   printf("digite o codigo da primeira carta (ex: A01): ");
   scanf("%s", codigo1);
   printf("digite a populção da primeira carta: ");
   scanf("%d", &populacao1);
   printf("digite a area da primeira carta (em km²): ");
   scanf("%f", &area1);
   printf("digite o PIB da primeira carta (em bilhoes): ");
   scanf("%f", &pib1);
   printf("digite o numero de pontos turisticos da primeira carta: ");
   scanf("%d", &pontos_turisticos1);

   // Cadastro da segunda carta
   printf("\nDigite o codigo da segunda carta (ex: A01): ");
   scanf("%s", &codigo2);
   printf("digite a populacao da segunda carta: ");
   scanf("%d", &populacao2);
   printf("digite a area da segunda carta (em km²): ");
   scanf("%f", &area2);
   printf("digite o PIB da segunda carta (em bilhoes): ");
   scanf("%f", &pib2);
   printf("digite o numero de pontos turisticos da sefunda carta: ");
   scanf("%d", &pontos_turisticos2);
   
   // Exibicao dos dados da primeira carta
   printf("\nDados da primeira carta:\n");
   printf("Codigo: %s\n", codigo1);
   printf("Populacao: %d\n", populacao1);
   printf("Area: %.2f km²\n", area1);
   printf("PIB: %.2f bilhoes\n", pib1);
   printf("Pontos turisticos: %d\n", pontos_turisticos1);

   //Exibicao dos dados da segunda carta
   printf("\nDados da segunda carta: \n");
   printf("Codigo: %s\n", codigo2);
   printf("Populacao: %d\n", populacao2);
   printf("Area: %.2f km²\n", area2);
   printf("PIB: %.2f bilhoes\n", pib2);
   printf("Pontos turisticos: %d\n", pontos_turisticos2);
   
   return 0;
}