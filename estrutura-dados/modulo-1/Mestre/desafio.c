//
// Created by Matheus Barreto on 02/11/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10
#define MISSOES = ["CONQUISTAR 3 TERRITÓRIOS", "ELIMINAR TODAS AS TROPAS DA COR VERMELHA", "ELIMINAR TODAS AS TROPAS DA COR AZUL", "ELIMINAR TODAS AS TROPAS DA COR VERDE", "ELIMINAR TODAS AS TROPAS DA COR AMARELA"]

// Definição de território
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

//Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função para exibir território
void exibirTerritorios(int totalTerritorios, Territorio *territorios) {
    printf("-------- EXIBIÇÃO DO MAPA --------\n");

    if (totalTerritorios == 0) {
        printf("Nenhum território cadastrado ainda.\n");
    } else {
        for (int i = 0; i < totalTerritorios; i++) {
            printf("---------------------\n");
            printf("TERRITÓRIO %d\n", i + 1);
            printf("Nome %s\n", territorios[i].nome);
            printf("Cor %s\n", territorios[i].cor);
            printf("Tropas %d\n", territorios[i].tropas);
        }
        printf("---------------------\n");
    }

    printf("Pressione enter para continuar\n");
    getchar();
}

//Função para atacar territorio
void atacarTerritorio(Territorio *territorios, int qtdTerritorios) {
    int territorioAtacante, territorioDefensor;
    const int min = 1, max = 6;
    int dadoAtacante = (rand() % (max - min + 1)) + min;
    int dadoDef = (rand() % (max - min + 1)) + min;

    printf("-------- ATAQUE DE TERRITÓRIO --------\n");
    exibirTerritorios(qtdTerritorios, territorios);
    printf("Digite qual território irá iniciar o ataque\n");
    scanf("%d", &territorioAtacante);
    limparBufferEntrada();

    printf("Digite qual território irá se defender\n");
    scanf("%d", &territorioDefensor);
    limparBufferEntrada();

    //Comparação entre os territórios escolhidos para saber se a cor é a mesma
    while (strcmp(territorios[territorioAtacante - 1].cor, territorios[territorioDefensor - 1].cor) == 0) {
        printf("ERRO - Você não pode se atacar.\n\n");
        printf("Digite qual território irá se defender\n");
        scanf("%d", &territorioDefensor);
    }

    printf("\nDado do atacante: %d\n", dadoAtacante);
    printf("\nDado do defensor: %d\n", dadoDef);

    if (dadoAtacante > dadoDef) {
        printf("Defensor perdeu.\n");
        strcpy(territorios[territorioDefensor - 1].cor, territorios[territorioAtacante - 1].cor);
        territorios[territorioDefensor - 1].tropas = territorios[territorioDefensor - 1].tropas / 2;
    } else if (dadoDef > dadoAtacante) {
        printf("Defensor ganhou.\n");
        territorios[territorioAtacante - 1].tropas--;
    } else {
        printf("Empate.\n");
    }

    printf("Pressione enter para continuar\n");
    getchar();
}

void liberarMemoria(Territorio *territorio) {
    free(territorio);

    printf("Memória liberada com sucesso.\n");
}

void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
}

void cadastrarTerritorios(Territorio *territorios, int *totalTerritoriosCadastrados, const int qtdTerritorios) {
    int indice = 0;
    printf("--------- CADASTRO DE TERRITORIOS ---------\n");
    //Laço principal do cadastro de territorios
    do {
        printf("Cadastro do território %d\n", indice + 1);
        printf("Digite o nome do território\n");
        fgets(territorios[indice].nome, TAM_NOME, stdin);

        printf("Digite a cor do território\n");
        fgets(territorios[indice].cor, TAM_COR, stdin);

        printf("Digite a quantidade de tropas\n");
        scanf("%d", &territorios[indice].tropas);

        territorios[indice].nome[strcspn(territorios[indice].nome, "\n")] =
                '\0';
        territorios[indice].cor[strcspn(territorios[indice].cor, "\n")] =
                '\0';

        limparBufferEntrada();

        indice++;

        printf("\nTerritório cadastrado com sucesso!\n\n");
    } while (indice < qtdTerritorios);

    *totalTerritoriosCadastrados = indice;
}

void exibirMenu() {
    printf("-------- COMEÇO DO JOGO --------\n");
    printf("1 - Atacar território\n");
    printf("2 - Exibir mapa\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção\n");
}

int verificarMissao() {
}

//Função principal
int main() {
    int qtdTerritorios, qtdJogadores;
    int totalTerritoriosCadastrados = 0;
    int opcao;
    Territorio *territorios;

    //Quantidade de territórios a ser utilizado
    printf("--------- WAR ---------\n\n");
    printf("Quantos territórios serão utilizados?\n");
    scanf("%d", &qtdTerritorios);
    printf("Quantos jogadores participarão?\n");
    scanf("%d", &qtdJogadores);
    limparBufferEntrada();

    territorios = (Territorio *) calloc(qtdTerritorios, sizeof(Territorio));
    char *missoes = (char *) calloc(qtdJogadores, sizeof(char *));

    //Verifica se houve erro na alocação de memória
    if (territorios == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }


    do {
        exibirMenu();

        //escolha da opção
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            //Atacar território na lista
            case 1:
                atacarTerritorio(territorios, qtdTerritorios);
                break;

            //Listagem de territórios cadastrados
            case 2:
                exibirTerritorios(qtdTerritorios, territorios);
                break;

            case 0:
                printf("\nSaindo do sistema\n");
                break;

            //Opção caso o usuário escolha a opção errada
            default:
                printf("\nOpcao invalida!\n");
                printf("Pressione enter para continuar");
                getchar();
                break;
        }
    } while (opcao != 0);

    free(territorios);
    printf("\nMemória liberada com sucesso.\n");

    return 0;
}
