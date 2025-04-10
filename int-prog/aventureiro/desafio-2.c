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
    card1.populationDensity = (float) card1.population/card1.area;
    scanf(" %f", &card1.gdp);
    card1.gdpPerCapita = (float) card1.gdp/card1.population;

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
    card2.populationDensity = (float) card2.population/card2.area;
    printf("Digite o PIB da cidade: ");
    scanf(" %f", &card2.gdp);
    card2.gdpPerCapita = (float)card2.gdp/card2.population;
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &card2.tourismPoints);

//    printf("\n\nCarta 1: \n");
//    printf("Estado: %c\n", card1.state);
//    printf("Codigo: %c%s\n", card1.state, card1.code);
//    printf("Nome da cidade: %s\n", card1.city);
//    printf("População: %d\n", card1.population);
//    printf("Area da cidade: %.2f km²\n", card1.area);
//    printf("PIB: R$%.2f\n", card1.gdp);
//    printf("Número de pontos turísticos: %d", card1.tourismPoints);
//    printf("Densidade populacional: %.2f hab/km²\n", card1.populationDensity);
//    printf("PIB per Capita: R$%.2f", card1.gdpPerCapita);
//
//    printf("\n\nCarta 2: \n");
//    printf("Estado: %c\n", card2.state);
//    printf("Codigo: %c%s\n", card2.state, card2.code);
//    printf("Nome da cidade: %s\n", card2.city);
//    printf("População: %d\n", card2.population);
//    printf("Area da cidade: %.2f km²\n", card2.area);
//    printf("PIB: R$%.2f\n", card2.gdp);
//    printf("Número de pontos turísticos: %d", card2.tourismPoints);
//    printf("Densidade populacional: %.2f hab/km²", card2.populationDensity);
//    printf("PIB per Capita: R$%.2f", card2.gdpPerCapita);

    printf("\n\nÉ hora da batalha! Escolha uma das opções para comparar entre as cartas\n");
    battleOption = showOptionsToCompare();

    printf("\n\n");
    switch(battleOption){
        case 1:
            printf("Batalha de cartas: Tamanho da população\n");
            printf("Carta 1: %s: %d\n", card1.city, card1.population);
            printf("Carta 2: %s: %d\n", card2.city, card2.population);
            printf("Resultado :");
            card1.population>card2.population ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                card1.population == card2.population?
                    printf("Opa, houve um empate!"):
                    printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 2:
            printf("Batalha de cartas: Tamanho da área\n");
            printf("Carta 1: %s: %.2f\n", card1.city, card1.area);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.area);
            printf("Resultado :");
            card1.area>card2.area ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                card1.area == card2.area?
                    printf("Opa, houve um empate!") :
                    printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 3:
            printf("Batalha de cartas: Tamanho do PIB\n");
            printf("Carta 1: %s: %.2f\n", card1.city, card1.gdp);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.gdp);
            printf("Resultado :");
            card1.gdp>card2.gdp ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                card1.gdp == card2.gdp?
                    printf("Opa, houve um empate!") :
                    printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 4:
            printf("Batalha de cartas: Densidade populacional\n");
            printf("Carta 1: %s: %.2f\n", card1.city, card1.populationDensity);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.populationDensity);
            printf("Resultado :");
            card1.populationDensity<card2.populationDensity ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                card1.populationDensity == card2.populationDensity?
                    printf("Opa, houve um empate!") :
                    printf("Carta 2 (%s) venceu!", card2.city);
        break;

        case 5:
            printf("Batalha de cartas: PIB per capita\n");
            printf("Carta 1: %s: %.2f\n", card1.city, card1.gdpPerCapita);
            printf("Carta 2: %s: %.2f\n", card2.city, card2.gdpPerCapita);
            printf("Resultado :");
            card1.gdpPerCapita>card2.gdpPerCapita ?
                printf("Carta 1 (%s) venceu!", card1.city) :
                card1.gdpPerCapita == card2.gdpPerCapita ?
                    printf("Opa, houve um empate!") :
                    printf("Carta 2 (%s) venceu!", card2.city);
        break;

        default:
          printf("Ops, houve um erro na seleção da opção...");
         break;
    }
}