#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PIECE_SIZE 5
#define NUM_PIECES 16
#define ROW_WIDTH 3
#define BOARD_SIZE 10
#define TURN_SIZE 3
#define PIECE_SET_SIZE 3

typedef struct Piece {
    int grid[PIECE_SIZE][PIECE_SIZE];
    int width, height;
} Piece;

typedef struct Board {
    int grid[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct Point {
    int x, y;
} Point;

typedef struct Move {
    int pieceId;
    Point position;
    int score;
} Move;

typedef struct Turn {
    Move moves[TURN_SIZE];
} Turn;

typedef struct PieceSet {
    Piece pieces[PIECE_SET_SIZE];
} PieceSet;

void printPiece(Piece piece);
void displayPieces(const Piece *pieces, int length);
void prettyPrintPieces(const Piece *pieces);
void clearBoard(Board *board);
int placePiece(Board *board, Board *nextBoard, int piece, Point *pos);
void copyBoard(Board *from, Board *to);
void printBoard(Board *board);
int countBoardScore(Board *board);
int getPiecePlacements(Board *board, int pieceId, Point *positions);
int turnScore(Turn *turn);
void getPermutations(Board *startBoard);
