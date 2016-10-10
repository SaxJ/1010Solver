#include "Solver.h"

/*
A list of possible pieces.
*/
static const Piece PIECES[16] = {
  {
    {
      {1,1,0,0,0},
      {1,0,0,0,0},
      {0},
      {0},
      {0}
    },
    2,
    2
  },

  {
    {
      {1,1,0,0,0},
      {0,1,0,0,0},
      {0},
      {0},
      {0}
    },
    2,
    2
  },

  {
    {
      {0,1,0,0,0},
      {1,1,0,0,0},
      {0},
      {0},
      {0}
    },
    2,
    2
  },

  {
    {
      {1,0,0,0,0},
      {1,1,0,0,0},
      {0},
      {0},
      {0}
    },
    2,
    2
  },

  {
    {
      {1,1,1,0,0},
      {0},
      {0},
      {0},
      {0}
    },
    3,
    1
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0},
      {0}
    },
    1,
    3
  },

  {
    {
      {1,1,0,0,0},
      {1,1,0,0,0},
      {0,0,0,0,0},
      {0},
      {0}
    },
    2,
    2
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0}
    },
    1,
    4
  },

  {
    {
      {1,1,1,1,0},
      {0},
      {0},
      {0},
      {0}
    },
    4,
    1
  },

  {
    {
      {1,1,1,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0},
      {0}
    },
    3,
    3
  },

  {
    {
      {0,0,1,0,0},
      {0,0,1,0,0},
      {1,1,1,0,0},
      {0},
      {0}
    },
    3,
    3
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,1,1,0,0},
      {0},
      {0}
    },
    3,
    3
  },

  {
    {
      {1,1,1,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0},
      {0},
      {0}
    },
    3,
    3
  },

  {
    {
      {1,1,1,0,0},
      {1,1,1,0,0},
      {1,1,1,0,0},
      {0},
      {0}
    },
    3,
    3
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0}
    },
    1,
    5
  },

  {
    {
      {1,1,1,1,1},
      {0},
      {0},
      {0},
      {0}
    },
    5,
    1
  }
};

/**
 * Prints the piece to stdout.
*/
void printPiece(Piece piece) {
  for (int y = 0; y < PIECE_SIZE; y++) {
    for (int x = 0; x < PIECE_SIZE; x++) {
      if (piece.grid[x][y] == 1)
        printf("x");
      else
        printf(" ");
    }
    printf("\n");
  }
}

void displayPieces(const Piece *pieces, int length) {
  for (int i = 0; i < NUM_PIECES; i++) {
    printf("%d)\n", i + 1);
    printPiece(pieces[i]);
    printf("===============\n");
  }
}

void prettyPrintPieces(const Piece *pieces) {
    for (int y = 0; y < PIECE_SIZE; y++) {
        for (int p = 0; p < NUM_PIECES; p++) {
            for (int x = 0; x < PIECE_SIZE; x++) {
                if (pieces[p].grid[x][y] == 1)
                    printf("x");
                else
                    printf(" ");
            }
            if (y == 0)
                printf("%-2d|  ", p);
            else
                printf("  |  ");
        }
        printf("\n");
    }
}

void clearBoard(Board *board) {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            board->grid[x][y] = 0;
        }
    }
}

void copyBoard(Board *from, Board *to) {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            to->grid[x][y] = from->grid[x][y];
        }
    }
}

int placePiece(Board *board, Board *nextBoard, int pieceNumber, Point *pos) {
    copyBoard(board, nextBoard);
    Piece piece = PIECES[pieceNumber % NUM_PIECES];
    for (int x = 0; x < PIECE_SIZE; x++) {
        for (int y = 0; y < PIECE_SIZE; y++) {
            int xp = pos->x + x;
            int yp = pos->y + y;
            if (xp < BOARD_SIZE && yp < BOARD_SIZE)
                nextBoard->grid[xp][yp] += piece.grid[x][y];
            
            if (nextBoard->grid[xp][yp] > 1)
                return -1;
        }
    }
    return 0;
}

void printBoard(Board *board) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%d ", board->grid[x][y]);
        }
        printf("\n");
    }
    printf("=============\n");
}

int countBoardScore(Board *board) {
    int score = 0;
    for (int x = 0; x < BOARD_SIZE; x++) {
        bool full = true;
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (board->grid[x][y] == 0) {
                full = false;
                break;
            }
        }
        if (full) score++;
    }
    
    for (int y = 0; y < BOARD_SIZE; y++) {
        bool full = true;
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (board->grid[x][y] == 0) {
                full = false;
                break;
            }
        }
        if (full) score++;
    }
    
    return score;
}

/**
 * Populates the array of Points with the possible positions that the piece can be places.
 * Returns the numbers of possible positions.
 */
int getPiecePlacements(Board *board, int pieceId, Point *positions) {
    Piece piece = PIECES[pieceId];
    int numPositions = 0;

    for (int x = 0; x < BOARD_SIZE - piece.width; x++) {
        for (int y = 0; y < BOARD_SIZE - piece.height; y++) {
            bool invalid = false;
            
            for (int w = 0; w < piece.width && !invalid; w++) {
                for (int h = 0; h < piece.height; h++) {
                    if (board->grid[x + w][y + h] > 0) {
                        invalid = true;
                        break;
                    }
                }
            }
            
            if (!invalid) {
                numPositions++;
                positions[numPositions - 1].x = x;
                positions[numPositions - 1].y = y;
            }
        }
    }
    
    return numPositions;
}

void getPiecePlacement(Board *board, int piece, Move *move) {
  Point positions[100];
  Board next;
  int maxScore = 0;
  int bestPos = 0;
  int nPositions = getPiecePlacements(board, piece, positions);
  
  for (int i = 0; i < nPositions; i++) {
    placePiece(board, &next, piece, &positions[i]);
    int score = countBoardScore(&next);
    if (score > maxScore) {
      maxScore = score;
      bestPos = i;
    }
  }
  
  move->pieceId = piece;
  move->position.x = positions[bestPos].x;
  move->position.y = positions[bestPos].y;
  move->score = maxScore;
}

int executeMove(Board *board, Board *nextBoard, Move *move) {
    return placePiece(board, nextBoard, move->pieceId, &(move->position));
}

void getPermutations(Board *startBoard, const int *pieces, Turn *possibleTurns) {
  int turnNumber = 0;

  Board board;
  Board nextBoard;

  for (int a = 0; a <=2; a++) {
    for (int b = 0; b <= 2; b++) {
      if (a == b) continue;
      
      for (int c = 0; c <= 2; c++) {
        if (c == b || c == a) continue;
        
        // initialise board back to start state
        copyBoard(startBoard, &board);
        
        // execute moves, recording moves to the turn
        getPiecePlacement(&board, pieces[a], &(possibleTurns[turnNumber].moves[0]));
        executeMove(&board, &nextBoard, &(possibleTurns[turnNumber].moves[0]));
        
        getPiecePlacement(&board, pieces[b], &(possibleTurns[turnNumber].moves[1]));
        executeMove(&nextBoard, &board, &(possibleTurns[turnNumber].moves[1]));
        
        getPiecePlacement(&board, pieces[c], &(possibleTurns[turnNumber].moves[2]));
        executeMove(&board, &nextBoard, &(possibleTurns[turnNumber].moves[2]));
        
        turnNumber++;
      }
    }
  }
}

int main(int argc, char **argv) {
  prettyPrintPieces(PIECES);
  int selected, x, y;
  Board a, b;
  clearBoard(&a); clearBoard(&b);
  
  Point p = {0};
  placePiece(&a, &b, 0, &p);
  printBoard(&b);
  
  Point positions[100] = {0};
  int sz = getPiecePlacements(&b, 13, positions);
  printf("Can place peice 13 in %d positions.\n", sz);
}
