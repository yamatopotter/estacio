#include<stdio.h>

//Aproveitando o conceito de OO, montei uma estrutura de dados para facilitar a gerencia dos dados
struct Card {
    char state;
    char code[3];
    char city[51];
    int population;
    float area;
    float pib;
    int tourismPoints;
};

int main() {
    struct Card card1, card2;

    printf("\nCadastrar carta 1\n");
    printf("Digite a letra referente ao estado (A até H): ");
    scanf(" %c", &card1.state);
    printf("Digite o código da carta: ");
    scanf(" %s", &card1.code);
    printf("Digite o nome da cidade: ");
    scanf(" %s", &card1.city);
    printf("Digite o número de habitantes da cidade: ");
    scanf(" %d", &card1.population);
    printf("Digite a área em m2 da cidade: ");
    scanf(" %f", &card1.area);
    printf("Digite o PIB da cidade: ");
    scanf(" %f", &card1.pib);
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &card1.tourismPoints);

    printf("\nCadastrar carta 2\n");
    printf("Digite a letra referente ao estado (A até H): ");
    scanf(" %c", &card2.state);
    printf("Digite o código da carta: ");
    scanf(" %s", &card2.code);
    printf("Digite o nome da cidade: ");
    scanf(" %s", &card2.city);
    printf("Digite o número de habitantes da cidade: ");
    scanf(" %d", &card2.population);
    printf("Digite a área em m2 da cidade: ");
    scanf(" %f", &card2.area);
    printf("Digite o PIB da cidade: ");
    scanf(" %f", &card2.pib);
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &card2.tourismPoints);

    printf("\n\nCarta 1: \n");
    printf("Estado: %c\n", card1.state);
    printf("Codigo: %c%s\n", card1.state, card1.code);
    printf("Nome da cidade: %s\n", card1.city);
    printf("População: %d\n", card1.population);
    printf("Area da cidade: %.2f km²\n", card1.area);
    printf("PIB: R$%.2f\n", card1.pib);
    printf("Número de pontos turísticos: %d", card1.tourismPoints);

    printf("\n\nCarta 2: \n");
    printf("Estado: %c\n", card2.state);
    printf("Codigo: %c%s\n", card2.state, card2.code);
    printf("Nome da cidade: %s\n", card2.city);
    printf("População: %d\n", card2.population);
    printf("Area da cidade: %.2f km²\n", card2.area);
    printf("PIB: R$%.2f\n", card2.pib);
    printf("Número de pontos turísticos: %d", card2.tourismPoints);
}