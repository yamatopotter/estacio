//
// Created by matheus on 4/10/25.
//
#include <stdio.h>
#define TAMANHO 10
#define NAVIO 3

void inicializaTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionaNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H') {
        if (coluna + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (direcao == 'V') {
        if (linha + tamanho > TAMANHO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    } else if(direcao == 'A'){

    }else if(direcao == 'B'){

    }
    else if(direcao == 'C'){

    }
    else if(direcao == 'D'){

    }

    else {
        return 0;
    }
    return 1;
}

void exibeTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tabuleiro[TAMANHO][TAMANHO];

    //    inicializando o tabuleiro com todas as posições em zero
    inicializaTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 1; // Horizontal
    int linha2 = 5, coluna2 = 4; // Vertical

    if (podePosicionarNavio(tabuleiro, linha1, coluna1, NAVIO, 'H')) {
        posicionaNavio(tabuleiro, linha1, coluna1, NAVIO, 'H');
    }
    else {
        printf("Não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    if (podePosicionarNavio(tabuleiro, linha2, coluna2, NAVIO, 'V')) {
        posicionaNavio(tabuleiro, linha2, coluna2, NAVIO, 'V');
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro final
    exibeTabuleiro(tabuleiro);
}