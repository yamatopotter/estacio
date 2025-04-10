/*
Created by matheus on 4/10/25.

Dicionário de movimentos básicos
1 - up
2 - up right
3 - right
4 - down right
5 - down
6 - down left
7 - left
8 - up left
*/

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
    for (int i=1; i<2; i++) {
        moveUp();
        for (int j=1; j<2; j++) {
            moveRight();
        }
    }
}

void moveDownDiagonalRight(){
    for (int i=1; i<2; i++) {
        moveUp();
        for (int j=1; j<2; j++) {
            moveRight();
        }
    }
}

void moveUpDiagonalLeft(){
    for (int i=1; i<2; i++) {
        moveUp();
        for (int j=1; j<2; j++) {
            moveLeft();
        }
    }
}

void moveDownDiagonalLeft(){
    for (int i=1; i<2; i++) {
        moveDown();
        for (int j=1; j<2; j++) {
            moveRight();
        }
    }
}

void moveTower(int movement, int direction) {
  if(movement > 0){
    switch (direction) {
      case 1:
          moveUp();
      break;

      case 3:
          moveRight();
      break;

      case 5:
          moveDown();
      break;

      case 7:
          moveLeft();
      break;

      default:
        printf("Movimento inválido");
    }

    moveTower(movement-1, direction);
  }
}

void moveBishop(int movement, int direction) {
  if(movement > 0){
    switch (direction){
      case 2:
          moveUpDiagonalRight();
      break;

      case 4:
          moveDownDiagonalRight();
      break;

      case 6:
          moveDownDiagonalLeft();
      break;

      case 8:
          moveUpDiagonalLeft();
      break;

      default:
        printf("Movimento inválido");
    }

    moveBishop(movement-1, direction);
  }
}

void switchMovementHorse(int direction){
  switch (direction) {
    case 1:
      moveUp();
    break;

    case 3:
      moveRight();
    break;

    case 5:
      moveDown();
    break;

    case 7:
      moveLeft();
    break;

    default:
      printf("Movimento inválido");
  }
}

void moveHorse(int direction1, int movement1, int direction2, int movement2) {
//  Validação para movimentação inválida do cavalo
//  Desnecessário a criação do movimento com nested loop no cavalo, mas a ordem de impressão fica impactada por conta do loop em algumas condições

  if (!((movement1 == 2 && movement2 == 1) || (movement1 == 1 && movement2 == 2))) {
    printf("Movimento inválido");
  }
  else{
    for(int i=1; i<=movement1; i++) {
        switchMovementHorse(direction1);
        if (movement1==2 && i==1) {
            continue;
        }

        while(movement2>0){
        switchMovementHorse(direction2);
        movement2--;
        }
    }
  }
}

void moveQueen(int movement, int direction) {
  if(movement > 0){
    switch (direction) {
      case 1:
          moveUp();
      break;

      case 2:
          moveUpDiagonalRight();
      break;

      case 3:
          moveRight();
      break;

      case 4:
          moveDownDiagonalRight();
      break;

      case 5:
          moveDown();
      break;

      case 6:
          moveDownDiagonalLeft();
      break;

      case 7:
          moveLeft();
      break;

      case 8:
          moveUpDiagonalLeft();
      break;

      default:
        printf("Movimento inválido");
    }

    moveQueen(movement-1, direction);
  }

}

int main(){
  int movimentoTorre=5, movimentoBispo=5, movimentoRainha=8;

  printf("Movimento do cavalo duas para baixo, uma para esquerda:\n");
  moveHorse(1, 2, 3, 1);

  printf("\nMovimento da torre %d casas para a direita: \n", movimentoTorre);
  moveTower(movimentoTorre, 3);

  printf("\nMovimento do bispo %d casas na diagonal para cima e direita: \n", movimentoBispo);
  moveBishop(movimentoBispo,2);

  printf("\nMovimento da rainha %d casas para esquerda:\n", movimentoRainha);
  moveQueen(movimentoRainha, 7);
}