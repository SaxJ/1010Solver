#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Piece {
  bool grid[5][5];
} Piece;

void makePieceList(Piece* array);
void printPiece(Piece* piece);
void printPieceArray(Piece* pieceList, int length);
