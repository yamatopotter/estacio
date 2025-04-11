//
// Created by matheus on 4/10/25.
//
#include <stdio.h>

void inicializaTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionaNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int podePosicionarNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, char direcao) {
    if (direcao == 'H') {
        if (coluna + tamanho > 10) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } else if (direcao == 'V') {
        if (linha + tamanho > 10) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    } else {
        return 0;
    }
    return 1;
}


void exibeTabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tabuleiro[10][10];

    //    inicializando o tabuleiro com todas as posições em zero
    inicializaTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 1; // Horizontal
    int linha2 = 5, coluna2 = 4; // Vertical

    if (podePosicionarNavio(tabuleiro, linha1, coluna1, 3, 'H')) {
        posicionaNavio(tabuleiro, linha1, coluna1, 3, 'H');
    }
    else {
        printf("Não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    if (podePosicionarNavio(tabuleiro, linha2, coluna2, 3, 'V')) {
        posicionaNavio(tabuleiro, linha2, coluna2, 3, 'V');
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro final
    exibeTabuleiro(tabuleiro);
}