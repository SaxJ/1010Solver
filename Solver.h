#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PIECE_SIZE 5
#define NUM_PIECES 16
#define ROW_WIDTH 3
#define BOARD_SIZE 10

typedef struct Piece {
    int grid[PIECE_SIZE][PIECE_SIZE];
    int width, height;
} Piece;

typedef struct Board {
    int grid[BOARD_SIZE][BOARD_SIZE];
} Board;

void printPiece(Piece piece);
void displayPieces(const Piece *pieces, int length);
void prettyPrintPieces(const Piece *pieces);
