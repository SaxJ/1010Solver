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
    int ret = placePiece(board, &next, piece, &positions[i]);
    if (ret < 0) continue;
    
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

int getPermutations(Board *startBoard, int *pieces, Turn *possibleTurns) {
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
  
  return turnNumber;
}

int turnScore(Turn *turn) {
    int totalScore = 0;
    for (int i = 0; i < TURN_SIZE; i++) {
        totalScore += turn->moves[i].score;
    }
    
    return totalScore;
}

int getMaxTurnIndex(Turn *turns, int size) {
    int max = turnScore(&turns[0]);
    int idx = 0;
    for (int i = 1; i < size; i++) {
        int score = turnScore(&turns[i]);
        if (score > max) {
            max = score;
            idx = i;
        }
    }
    
    return idx;
}

void removeNewLine(char *string, size_t length) {
    for (int i = 0; i < length; i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
            return;
        }
    }
}

void printTurn(Turn *turn) {
    for (int i = 0; i < TURN_SIZE; i++) {
        Move m = turn->moves[i];
        printf("Piece: %d, (%d, %d)\n", m.pieceId, m.position.x, m.position.y);
    }
}

int main(int argc, char **argv) {
    char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
  
    printf("To get started, whos score do you want to beat?\n");
    getline(&buffer, &bufsize, stdin);
    removeNewLine(buffer, bufsize);
    printf("Ok! Time to beat %s!\n", buffer);
    
    /////////////////////////////////////
    Board board = {0};
    Board nextBoard = {0};
    
    while (true) {
        printBoard(&board);
        prettyPrintPieces(PIECES);
        
        printf("Enter 3 piece numbers:\n");

        int pieces[3];
        scanf("%d %d %d", &pieces[0], &pieces[1], &pieces[2]);
        Turn turns[20];
        int nTurns = getPermutations(&board, pieces, turns);
        int t = getMaxTurnIndex(turns, nTurns);
        
        printf(">>>>>>>\n");
        printTurn(&turns[t]);
        
        executeMove(&board, &nextBoard, &(turns[t].moves[0]));
        executeMove(&nextBoard, &board, &(turns[t].moves[1]));
        executeMove(&board, &nextBoard, &(turns[t].moves[2]));
    }
}
