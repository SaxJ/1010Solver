#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PIECE_SIZE 5
#define NUM_PIECES 17
#define ROW_WIDTH 3
#define BOARD_SIZE 10
#define TURN_SIZE 3
#define PIECE_SET_SIZE 3

typedef struct Piece {
    int grid[PIECE_SIZE][PIECE_SIZE];
    int width;
    int height;
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

/**
 * Print a single piece to visually show it's shape.
 */
void printPiece(Piece piece);

/**
 * List all possible pieces one after the other really ugly.
 */
void displayPieces(const Piece *pieces, int length);

/**
 * List all possible pieces and their index number side by side.
 */
void prettyPrintPieces(const Piece *pieces);

/**
 * Clear all squares on a board.
 * board - A pointer to the board to clear.
 */
void clearBoard(Board *board);

/**
 * Place a piece on the board, and copy the copy the resultant board to nextBoard.
 * board - The board to place a piece on.
 * nextBoard - The board to show the resultant board on.
 * piece - The index of the piece to place.
 * pos - THe position of the piece on the board.
 */
int placePiece(Board *board, Board *nextBoard, int piece, Point *pos);

/**
 * Copy a board from one buffer to another.
 * from - The board state to copy.
 * to - The board to copy state to.
 */
void copyBoard(Board *from, Board *to);

/**
 * Prints the board.
 * board - The board to visually display in stdout.
 */
void printBoard(Board *board);

/**
 * Scores the given board. The score is the sum of the number of completed rows and columns.
 * board - The board to score.
 * 
 * Returns the board score.
 */
int countBoardScore(Board *board);

/**
 * Updates the given Point array with the posible positions that the given
 * piece may be places on the given board.
 * board - The board to place the piece on.
 * pieceId - The ID of the piece to place.
 * positions - The array to update with possible piece locations.
 * 
 * Returns the number of possible piece placements.
 */
int getPiecePlacements(Board *board, int pieceId, Point *positions);

/**
 * Gets the max scoring placement for a give board and piece.
 */
void getPiecePlacement(Board *board, int piece, Move *turn);

/**
 * Returns the score of a turn. The turn score is the sum of the scores of each move in a turn.
 * turn - The turn to score.
 */
int turnScore(Turn *turn);

/**
 * Updates the array of turns with all possible purmutations of moves that the player could make.
 * Returns the number of permutations.
 */
int getPermutations(Board *startBoard, int *pieces, Turn *turns);

/**
 * Execute a move
 */
int executeMove( Board *board, Board *nextBoard, Move *move);

/**
 * Gets the maximum scoring turn.
 */
int getMaxTurnIndex(Turn *turns, int size);

/**
 * Replaces a newline with a terminating character.
 */
void removeNewLine(char *string, size_t length);

/**
 * Prints a turn.
 */
 void printTurn(Turn *turn);
