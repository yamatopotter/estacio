#include <stdio.h>

struct Card {
    char state;
    char code[3];
    char city[50];
    int population;
    float area;
    float pib;
    int tourismPoints;
};

struct Card addCard() {
    struct Card carta;

    printf("\nCadastrar carta\n");
    printf("Digite a letra referente ao estado (A até H): ");
    scanf(" %c", &carta.state);
    printf("Digite o código da carta: ");
    scanf(" %s", &carta.code);
    printf("Digite o nome da cidade: ");
    scanf(" %s", &carta.city);
    printf("Digite o número de habitantes da cidade: ");
    scanf(" %d", &carta.population);
    printf("Digite a área em m2 da cidade: ");
    scanf(" %f", &carta.area);
    printf("Digite o PIB da cidade: ");
    scanf(" %f", &carta.pib);
    printf("Digite a quantidade de pontos turisticos da cidade: ");
    scanf(" %d", &carta.tourismPoints);

    return carta;
}

void showCard(struct Card carta, int index) {
    printf("\n\nCarta %d: \n", index);
    printf("Estado: %c\n", carta.state);
    printf("Codigo: %c%s\n", carta.state, carta.code);
    printf("Nome da cidade: %s\n", carta.city);
    printf("População: %d\n", carta.population);
    printf("Area da cidade: %.2f km²\n", carta.area);
    printf("PIB: R$%.2f\n", carta.pib);
    printf("Número de pontos turísticos: %d", carta.tourismPoints);
}

int main(void) {
    struct Card card[2];

    printf("Cadastro de cartas - SuperTrunfo");
    for (int i = 0; i < 2; i++) {
        card[i]=addCard();
    }

    for (int i = 0; i < 2; i++) {
        showCard(card[i], i+1);
    }
}