#include "Solver.h"

static const Piece PIECES[16] = {
  {
    {
      {1,1,0,0,0},
      {1,0,0,0,0},
      {0},
      {0},
      {0}
    }
  },

  {
    {
      {1,1,0,0,0},
      {0,1,0,0,0},
      {0},
      {0},
      {0}
    }
  },

  {
    {
      {0,1,0,0,0},
      {1,1,0,0,0},
      {0},
      {0},
      {0}
    }
  },

  {
    {
      {1,0,0,0,0},
      {1,1,0,0,0},
      {0},
      {0},
      {0}
    }
  },

  {
    {
      {1,1,1,0,0},
      {0},
      {0},
      {0},
      {0}
    }
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0},
      {0}
    }
  },

  {
    {
      {1,1,0,0,0},
      {1,1,0,0,0},
      {0,0,0,0,0},
      {0},
      {0}
    }
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {1,1,1,1,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0},
      {0}
    }
  },

  {
    {
      {1,1,1,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {0,0,1,0,0},
      {0,0,1,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {1,1,1,0,0},
      {0,0,1,0,0},
      {0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {1,1,1,0,0},
      {1,1,1,0,0},
      {1,1,1,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },

  {
    {
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0},
      {1,0,0,0,0}
    }
  },

  {
    {
      {1,1,1,1,1},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  }
};

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

int main(int argc, char **argv) {
  prettyPrintPieces(PIECES);
}
