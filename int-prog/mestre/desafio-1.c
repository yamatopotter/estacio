//
// Created by matheus on 4/8/25.
//
#include<stdio.h>

struct Card {
    char state;
    char code[3];
    char city[51];
    int population;
    float area;
    float gdp;
    float populationDensity;
    float gdpPerCapita;
    int tourismPoints;
    float superPower;
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
    scanf(" %f", &card1.gdp);
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &card1.tourismPoints);
    card1.populationDensity = (float) card1.population/card1.area;
    card1.gdpPerCapita = (float) card1.gdp/card1.population;
    card1.superPower = (float) card1.population+
                       card1.area+
                       card1.gdp+
                       card1.gdpPerCapita+
                       card1.tourismPoints-
                       card1.populationDensity;

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
    scanf(" %f", &card2.gdp);
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &card2.tourismPoints);
    card2.populationDensity = (float) card2.population/card2.area;
    card2.gdpPerCapita = (float)card2.gdp/card2.population;
    card2.superPower = (float) card2.population+
                       card2.area+
                       card2.gdp+
                       card2.gdpPerCapita+
                       card2.tourismPoints-
                       card2.populationDensity;

    printf("\n\nCarta 1: \n");
    printf("Estado: %c\n", card1.state);
    printf("Codigo: %c%s \n", card1.state,card1.code);
    printf("Nome da cidade: %s\n", card1.city);
    printf("População: %d\n", card1.population);
    printf("Area da cidade: %.2f km²\n", card1.area);
    printf("PIB: R$%.2f\n", card1.gdp);
    printf("Número de pontos turísticos: %d\n", card1.tourismPoints);
    printf("Densidade populacional: %.2f hab/km²\n", card1.populationDensity);
    printf("PIB per Capita: R$%.2f", card1.gdpPerCapita);

    printf("\n\nCarta 2: \n");
    printf("Estado: %c \n", card2.state);
    printf("Codigo: %c%s \n", card2.state,card2.code);
    printf("Nome da cidade: %s\n", card2.city);
    printf("População: %d\n", card2.population);
    printf("Area da cidade: %.2f km²\n", card2.area);
    printf("PIB: R$%.2f\n", card2.gdp);
    printf("Número de pontos turísticos: %d\n", card2.tourismPoints);
    printf("Densidade populacional: %.2f hab/km²\n", card2.populationDensity);
    printf("PIB per Capita: R$%.2f", card2.gdpPerCapita);

    printf("\n\nComparação de cartas: \n");

    printf("População: %s\n", card1.population > card2.population ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("Área: %s\n", card1.area > card2.area ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("PIB: %s\n", card1.gdp > card2.gdp ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("Pontos Turísticos: %s\n", card1.tourismPoints > card2.tourismPoints ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("Densidade Populacional: %s\n", card1.populationDensity < card2.populationDensity ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("PIB per Capita: %s\n", card1.gdpPerCapita > card2.gdpPerCapita ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
    printf("Super Poder: %s\n", card1.superPower > card2.superPower ? "Carta 1 venceu (1)" : "Carta 2 venceu (0)");
}