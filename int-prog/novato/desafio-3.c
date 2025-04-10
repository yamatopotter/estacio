//
// Created by matheus on 4/10/25.
//
// Dicionário de movimentos
// 1 - up
// 2 - up right
// 3 - right
// 4 - down right
// 5 - down
// 6 - down left
// 7 - left
// 8 - up left

#include <stdio.h>

void moveUp(){
    printf("Cima\n");
}

void moveDown(){
  printf("Baixo\n");
}

void moveLeft(){
  printf("Esquerda\n");
}

void moveRight(){
  printf("Direita\n");
}

void moveUpDiagonalRight(){
  printf("Cima, Direita\n");
}

void moveDownDiagonalRight(){
  printf("Baixo, Direita\n");
}

void moveUpDiagonalLeft(){
  printf("Cima, Esquerda\n");
}

void moveDownDiagonalLeft(){
  printf("Baixo, Esquerda\n");
}

void moveTower(int movement, int direction) {
  switch (direction) {
    case 1:
      for (int i=1; i<=movement; i++) {
        moveUp();
      }
    break;

    case 3:
      for (int i=1; i<=movement; i++) {
        moveRight();
      }
    break;

    case 5:
      for (int i=1; i<=movement; i++) {
        moveDown();
      }
    break;

    case 7:
      for (int i=1; i<=movement; i++) {
        moveLeft();
      }
    break;

    default:
      printf("Movimento inválido");
  }
}

void moveBishop(int movement, int direction) {
  switch (direction){
    case 2:
      for (int i=1; i<=movement; i++) {
        moveUpDiagonalRight();
      }
    break;

    case 4:
      for (int i=1; i<=movement; i++) {
        moveDownDiagonalRight();
      }
    break;

    case 6:
      for (int i=1; i<=movement; i++) {
        moveDownDiagonalLeft();
      }
    break;

    case 8:
      for (int i=1; i<=movement; i++) {
        moveUpDiagonalLeft();
      }
    break;

    default:
      printf("Movimento inválido");
  }
}

void moveQueen(int movement, int direction) {
  switch (direction) {
    case 1:
      for (int i=1; i<=movement; i++) {
        moveUp();
      }
    break;

    case 2:
      for (int i=1; i<=movement; i++) {
        moveUpDiagonalRight();
      }
    break;

    case 3:
      for (int i=1; i<=movement; i++) {
        moveRight();
      }
    break;

    case 4:
      for (int i=1; i<=movement; i++) {
        moveDownDiagonalRight();
      }
    break;

    case 5:
      for (int i=1; i<=movement; i++) {
        moveDown();
      }
    break;

    case 6:
      for (int i=1; i<=movement; i++) {
        moveDownDiagonalLeft();
      }
    break;

    case 7:
      for (int i=1; i<=movement; i++) {
        moveLeft();
      }
    break;

    case 8:
      for (int i=1; i<=movement; i++) {
        moveUpDiagonalLeft();
      }
    break;

    default:
      printf("Movimento inválido");
  }
}

int main(){
  int movimentoTorre=5, movimentoBispo=5, movimentoRainha=8;

  printf("Movimento da torre %d casas para a direita: \n", movimentoTorre);
  moveTower(movimentoTorre, 3);

  printf("\nMovimento do bispo %d casas na diagonal para cima e direita: \n", movimentoBispo);
  moveBishop(movimentoBispo,2);

  printf("\nMovimento da rainha %d casas para esquerda:\n", movimentoRainha);
  moveQueen(movimentoRainha, 7);
}