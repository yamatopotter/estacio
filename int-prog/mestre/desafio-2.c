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
    int touristAttractions;
    float superPower;
};

void printOption(int option){
    switch(option){
        case 1:
            printf("1 - População\n");
            break;
        case 2:
            printf("2 - Área\n");
            break;
        case 3:
            printf("3 - PIB\n");
            break;
        case 4:
            printf("4 - Densidade populacional\n");
            break;
        case 5:
            printf("5 - PIB per capita\n");
            break;
        case 6:
            printf("6 - Pontos Turísticos\n");
        break;
        case 7:
            printf("7 - Super Poder\n");
        break;
        default:
            printf("Opção inválida de menu");
    }
}

float getValueFromCard(int option, struct Card card){
    switch(option){
        case 1:
            return card.population;
        break;
        case 2:
            return card.area;
        break;
        case 3:
            return card.gdp;
        break;
        case 4:
            return card.populationDensity;
        break;
        case 5:
            return card.gdpPerCapita;
        break;
        case 6:
            return card.touristAttractions;
        break;
        case 7:
           return card.superPower;
        break;
        default:
            printf("Opção inválida de menu");
    }
}

void compareOption(int option, struct Card card1, struct Card card2){
  switch(option){
      case 1:
          printf("Batalha de população:\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %d\n", card1.city, card1.population);
          printf("%s: %d\n", card2.city, card2.population);
          printf("Resultado: ");
          card1.population>card2.population ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.population == card2.population?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 2:
          printf("Batalha de área:\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %.2f\n", card1.city, card1.area);
          printf("%s: %.2f\n", card2.city, card2.area);
          printf("Resultado: ");
          card1.area>card2.area ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.area == card2.area?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 3:
          printf("Batalha de PIB\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %.2f\n", card1.city, card1.gdp);
          printf("%s: %.2f\n", card2.city, card2.gdp);
          printf("Resultado: ");
          card1.gdp>card2.gdp ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.gdp == card2.gdp?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 4:
          printf("Batalha de Densidade populacional\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %.2f\n", card1.city, card1.populationDensity);
          printf("%s: %.2f\n", card2.city, card2.populationDensity);
          printf("Resultado: ");
          card1.populationDensity<card2.populationDensity ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.populationDensity == card2.populationDensity?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 5:
          printf("Batalha de PIB per capita\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %.2f\n", card1.city, card1.gdpPerCapita);
          printf("%s: %.2f\n", card2.city, card2.gdpPerCapita);
          printf("Resultado: ");
          card1.gdpPerCapita>card2.gdpPerCapita ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.gdpPerCapita == card2.gdpPerCapita?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 6:
          printf("Batalha de Pontos Turísticos\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %d\n", card1.city, card1.touristAttractions);
          printf("%s: %d\n", card2.city, card2.touristAttractions);
          printf("Resultado: ");
          card1.touristAttractions>card2.touristAttractions ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.touristAttractions == card2.touristAttractions?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      case 7:
          printf("Batalha de Super Poderes\n");
          printf("%s vs. %s\n", card1.city, card2.city);
          printf("%s: %d\n", card1.city, card1.superPower);
          printf("%s: %d\n", card2.city, card2.superPower);
          printf("Resultado: ");
          card1.superPower>card2.superPower ?
              printf("Carta 1 (%s) venceu!\n", card1.city) :
              card1.superPower == card2.superPower?
                  printf("Opa, houve um empate!\n") :
                  printf("Carta 2 (%s) venceu!\n", card2.city);
      break;

      default:
          printf("Opção inválida de batalha");

  }
}

int repeatOption(){
    int option=8;

    while(option<1 || option>7){
        printf("Opção inválida. Escolha uma das opções disponibilizadas acima.\n");
        printf("Digite sua opção: ");
        scanf("%d", &option);
    }

    return option;
}

void showOptionsToCompare(int* option1, int* option2){
    for(int i=1; i<8; i++){
        printOption(i);
    }
    printf("Escolha sua opção: ");
    scanf("%d", option1);

    if(*option1<1 || *option1>7){
        *option1 = repeatOption();
    }

    printf("\nEscolha a segunda opção da batalha:\n");
    for(int i=1;i<8;i++){
        if(*option1 != i){
            printOption(i);
        }
    }

    printf("Escolha sua opção: ");
    scanf("%d", option2);

    if(*option2<1 || *option2>7){
      *option2 = repeatOption();
    }

    while(*option1 == *option2){
      printf("Opções iguais para batalha não é possível.\n");
      *option2 = repeatOption();
    }
}

int main() {
    struct Card card1, card2;
    int option1, option2;
    float totalCard1=0, totalCard2=0;

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
    scanf(" %d", &card1.touristAttractions);
    card1.populationDensity = (float) card1.population/card1.area;
    card1.gdpPerCapita = (float) card1.gdp/card1.population;
    card1.superPower = (float) card1.population+
                       card1.area+
                       card1.gdp+
                       card1.gdpPerCapita+
                       card1.touristAttractions-
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
    scanf(" %d", &card2.touristAttractions);
    card2.populationDensity = (float) card2.population/card2.area;
    card2.gdpPerCapita = (float)card2.gdp/card2.population;
    card2.superPower = (float) card2.population+
                       card2.area+
                       card2.gdp+
                       card2.gdpPerCapita+
                       card2.touristAttractions-
                       card2.populationDensity;

    printf("\n\nÉ hora da batalha! Escolha uma das opções para comparar entre as cartas\n");

//    Foi enviado para a função o ponteiro como parametro devido a limitação do C em retornar multiplos valores, poderia usar outro struct, mas resolvi por optar por outra abordagem
    showOptionsToCompare(&option1, &option2);
    printf("\n\nComparação de cartas: \n");
    printf("Comparação 1: \n");
    compareOption(option1, card1, card2);
    printf("Comparação 2: \n");
    compareOption(option2, card1, card2);
    printf("Comparação final: \n");
    totalCard1 += getValueFromCard(option1, card1);
    totalCard2 += getValueFromCard(option1, card2);
    totalCard1 += getValueFromCard(option2, card1);
    totalCard2 += getValueFromCard(option2, card2);
    printf("Carta 1 %s: %.2f vs. Carta 2 %s: %.2f", card1.city, totalCard1, card2.city, totalCard2);

    totalCard1 > totalCard2 ?
          printf("Carta 1 (%s) venceu!", card1.city) :
          totalCard1 == totalCard2 ?
              printf("Opa, houve um empate!") :
              printf("Carta 2 (%s) venceu!", card2.city) ;
}