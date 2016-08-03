#include "Solver.h"

void makePieceList(Piece* array) {

  /*
   * x
   */
  array[0].grid[0][0] = true;

  /*
   * xx
   * x
   */
  array[1].grid[0][0] = true;
  array[1].grid[0][1] = true;
  array[1].grid[1][0] = true;

  /*
   * xx
   *  x
   */
  array[2].grid[0][0] = true;
  array[2].grid[1][0] = true;
  array[2].grid[1][1] = true;

  /*
   *  x
   * xx
   */
  array[2].grid[1][0] = true;
  array[2].grid[1][1] = true;
  array[2].grid[0][1] = true;

  /*
   * x
   * xx
   */
  array[2].grid[0][0] = true;
  array[2].grid[0][1] = true;
  array[2].grid[1][1] = true;

  /*
   * xxx
   */
  for (int i = 0; i < 3; i++) array[3].grid[i][0] = true;

  /*
   * x
   * x
   * x
   */
  for (int i = 0; i < 3; i++) array[4].grid[0][i] = true;


  /*
   * xx
   * xx
   */
  array[5].grid[0][0] = true;
  array[5].grid[1][0] = true;
  array[5].grid[0][1] = true;
  array[5].grid[1][1] = true;

  /*
   * xxxx
   */
  for (int i = 0; i < 4; i++) array[6].grid[i][0] = true;

  /*
   * x
   * x
   * x
   * x
   */
  for (int i = 0; i < 4; i++) array[7].grid[0][i] = true;


}

void printPiece(Piece* piece) {
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      if (piece->grid[x][y])
        printf("x");
      else
        printf(" ");
    }
    printf("\n");
  }
}

void printPieceArray(Piece* pieceList, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d)\n", i + 1);
    printPiece(&pieceList[i]);
  }
}

int main(int argc, char **argv) {
  printf("Do nothing\n");
  Piece possiblePieces[10];
  makePieceList(possiblePieces);
  printPieceArray(possiblePieces, 10);
}
