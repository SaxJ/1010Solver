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
      {0,0,0,0,0}
    },
    1,
    4
  },

  {
    {
      {1,1,1,1,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
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
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    3,
    3
  },

  {
    {
      {0,0,1,0,0},
      {0,0,1,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    3,
    3
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    3,
    3
  },

  {
    {
      {1,1,1,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    3,
    3
  },

  {
    {
      {1,1,1,0,0},
      {1,1,1,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
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
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
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

int placePiece(Board *board, Board *nextBoard, Piece piece, Point pos) {
    copyBoard(board, nextBoard);
    for (int x = 0; x < PIECE_SIZE; x++) {
        for (int y = 0; y < PIECE_SIZE; y++) {
            int xp = pos.x + x;
            int yp = pos.y + y;
            if (xp < BOARD_SIZE && yp < BOARD_SIZE)
                nextBoard->grid[xp][yp] += piece.grid[x][y];
            
            if (nextBoard->grid[xp][yp] > 1)
                return -1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
  prettyPrintPieces(PIECES);
}
