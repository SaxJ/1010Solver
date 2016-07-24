#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PIECE_SIZE 5
#define NUM_PIECES 16
#define ROW_WIDTH 3

typedef struct Piece {
  int grid[5][5];
} Piece;

void printPiece(Piece piece);
void displayPieces(const Piece *pieces, int length);
void prettyPrintPieces(const Piece *pieces);
