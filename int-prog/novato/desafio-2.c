//
// Created by matheus on 4/8/25.
//
#include<stdio.h>

//Aproveitando o conceito de OO, montei uma estrutura de dados para facilitar a gerencia dos dados
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

int showOptionsToCompare(){
  int option;
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade populacional\n");
    printf("5 - PIB per capita\n");
    printf("Escolha sua opção: ");
    scanf("%d", &option);

    while(option<1 || option>5){
      printf("Opção inválida. Escolha uma das opções de 1 à 5.\n");
      printf("Digite sua opção: ");
      scanf("%d", &option);
    }

    return option;
}

int main() {
    struct Card card1, card2;
    int battleOption;

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

    printf("\n\nÉ hora da batalha! Escolha uma das opções para comparar entre as cartas\n");
    battleOption = showOptionsToCompare();

    printf("\n\n");
    switch(battleOption){
        case 1:
            printf("Carta 1: %s: %d\n", card1.city, card1.population);
            printf("Carta 2: %s: %d\n", card2.city, card2.population);
            printf("Resultado :");
            card1.population>card2.population ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 2:
            printf("Carta 1: %s: %.2f\n", card1.city, card1.area);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.area);
            printf("Resultado :");
            card1.area>card2.area ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 3:
            printf("Carta 1: %s: %.2f\n", card1.city, card1.gdp);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.gdp);
            printf("Resultado :");
            card1.gdp>card2.gdp ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 4:
            printf("Carta 1: %s: %.2f\n", card1.city, card1.populationDensity);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.populationDensity);
            printf("Resultado :");
            card1.populationDensity<card2.populationDensity ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 5:
            printf("Carta 1: %s: %.2f\n", card1.city, card1.gdpPerCapita);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.gdpPerCapita);
            printf("Resultado :");
            card1.gdpPerCapita>card2.gdpPerCapita ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                printf("Carta 2 (%s) venceu!", card2.city);
        break;

        default:
          printf("Ops, houve um erro na seleção da opção...");
         break;
    }

}