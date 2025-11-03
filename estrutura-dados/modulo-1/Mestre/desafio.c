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

// --- Protótipos ---
void limparBufferEntrada();

void exibirTerritorios(int totalTerritorios, Territorio *territorios);

void atacarTerritorio(Territorio *territorios, int qtdTerritorios);

void liberarMemoria(Territorio *territorios, char **missoes, int qtdJogadores);

void atribuirMissao(char *destino, char *missoes[], int totalMissoes);

int verificarMissao(char *missao, Territorio *mapa, int tamanho);

void cadastrarTerritorios(Territorio *territorios, int *totalTerritoriosCadastrados, const int qtdTerritorios);

void exibirMenu();

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
            printf("Nome: %s\n", territorios[i].nome);
            printf("Cor: %s\n", territorios[i].cor);
            printf("Tropas: %d\n", territorios[i].tropas);
        }
        printf("---------------------\n");
    }

    printf("Pressione Enter para continuar\n");
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

    printf("Digite qual território irá iniciar o ataque: ");
    scanf("%d", &territorioAtacante);
    limparBufferEntrada();

    printf("Digite qual território irá se defender: ");
    scanf("%d", &territorioDefensor);
    limparBufferEntrada();

    // Impede atacar território da mesma cor
    while (strcmp(territorios[territorioAtacante - 1].cor, territorios[territorioDefensor - 1].cor) == 0) {
        printf("ERRO - Você não pode se atacar.\n\n");
        printf("Digite outro território defensor: ");
        scanf("%d", &territorioDefensor);
        limparBufferEntrada();
    }

    printf("\nDado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDef);

    if (dadoAtacante > dadoDef) {
        printf("Defensor perdeu.\n");
        strcpy(territorios[territorioDefensor - 1].cor, territorios[territorioAtacante - 1].cor);
        territorios[territorioDefensor - 1].tropas /= 2;
    } else if (dadoDef > dadoAtacante) {
        printf("Defensor ganhou.\n");
        territorios[territorioAtacante - 1].tropas--;
    } else {
        printf("Empate.\n");
    }

    printf("Pressione Enter para continuar\n");
    getchar();
}

void liberarMemoria(Territorio *territorios, char **missoes, int qtdJogadores) {
    free(territorios);

    for (int i = 0; i < qtdJogadores; i++) {
        free(missoes[i]);
    }
    free(missoes);

    printf("\nMemória liberada com sucesso.\n");
}

// Função para sortear e atribuir uma missão ao jogador
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes; // sorteia índice
    strcpy(destino, missoes[indice]); // copia missão sorteada
}

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio *territorios, int *totalTerritoriosCadastrados, const int qtdTerritorios) {
    int indice = 0;
    printf("--------- CADASTRO DE TERRITÓRIOS ---------\n");

    do {
        printf("Cadastro do território %d\n", indice + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[indice].nome, TAM_NOME, stdin);

        printf("Digite a cor do território: ");
        fgets(territorios[indice].cor, TAM_COR, stdin);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[indice].tropas);

        territorios[indice].nome[strcspn(territorios[indice].nome, "\n")] = '\0';
        territorios[indice].cor[strcspn(territorios[indice].cor, "\n")] = '\0';

        limparBufferEntrada();
        indice++;

        printf("\nTerritório cadastrado com sucesso!\n\n");
    } while (indice < qtdTerritorios);

    *totalTerritoriosCadastrados = indice;
}

// Verifica se a missão foi cumprida (lógica simples)
int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
    if (strstr(missao, "CONQUISTAR") != NULL) {
        // exemplo: se todos os territórios são da mesma cor
        char corInicial[TAM_COR];
        strcpy(corInicial, mapa[0].cor);
        for (int i = 1; i < tamanho; i++) {
            if (strcmp(corInicial, mapa[i].cor) != 0)
                return 0; // ainda não venceu
        }
        return 1; // missão cumprida
    }
    return 0; // padrão: missão ainda não cumprida
}

void exibirMenu() {
    printf("-------- COMEÇO DO JOGO --------\n");
    printf("1 - Atacar território\n");
    printf("2 - Exibir mapa\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção\n");
}

// --- Função principal ---
int main() {
    srand(time(NULL)); // inicializa o gerador de aleatórios

    int qtdTerritorios, qtdJogadores;
    int totalTerritoriosCadastrados = 0;
    int opcao;

    printf("--------- WAR ---------\n\n");
    printf("Quantos territórios serão utilizados? ");
    scanf("%d", &qtdTerritorios);
    printf("Quantos jogadores participarão? ");
    scanf("%d", &qtdJogadores);
    limparBufferEntrada();

    // Aloca memória
    Territorio *territorios = (Territorio *) calloc(qtdTerritorios, sizeof(Territorio));
    char **missoesJogadores = (char **) calloc(qtdJogadores, sizeof(char *));

    if (territorios == NULL || missoesJogadores == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }

    // Define vetor de missões fixas
    char *todasMissoes[] = {
        "CONQUISTAR 3 TERRITÓRIOS",
        "ELIMINAR TODAS AS TROPAS DA COR VERMELHA",
        "ELIMINAR TODAS AS TROPAS DA COR AZUL",
        "ELIMINAR TODAS AS TROPAS DA COR VERDE",
        "ELIMINAR TODAS AS TROPAS DA COR AMARELA"
    };
    int totalMissoes = 5;

    // Aloca e sorteia missão para cada jogador
    for (int i = 0; i < qtdJogadores; i++) {
        missoesJogadores[i] = (char *) malloc(100 * sizeof(char));
        atribuirMissao(missoesJogadores[i], todasMissoes, totalMissoes);
        printf("Missão do Jogador %d: %s\n", i + 1, missoesJogadores[i]);
    }

    cadastrarTerritorios(territorios, &totalTerritoriosCadastrados, qtdTerritorios);

    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                atacarTerritorio(territorios, qtdTerritorios);
                break;
            case 2:
                exibirTerritorios(qtdTerritorios, territorios);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

        // Verifica vitória
        for (int i = 0; i < qtdJogadores; i++) {
            if (verificarMissao(missoesJogadores[i], territorios, qtdTerritorios)) {
                printf("\n🎉 O Jogador %d venceu! Missão cumprida: %s 🎉\n", i + 1, missoesJogadores[i]);
                opcao = 0;
            }
        }
    } while (opcao != 0);

    liberarMemoria(territorios, missoesJogadores, qtdJogadores);
    return 0;
}
