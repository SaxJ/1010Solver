#include "Solver.h"
const int PIECE_A[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,0,0,0},
    {1,0,0,0,0},
    {0},
    {0},
    {0}
};

const int PIECE_B[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,0,0,0},
    {0,1,0,0,0},
    {0},
    {0},
    {0}
};

const int PIECE_C[PIECE_SIZE][PIECE_SIZE] = {
    {0,1,0,0,0},
    {1,1,0,0,0},
    {0},
    {0},
    {0}
};

const int PIECE_D[PIECE_SIZE][PIECE_SIZE] = {
    {1,0,0,0,0},
    {1,1,0,0,0},
    {0},
    {0},
    {0}
};

const int PIECE_E[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,0,0},
    {0},
    {0},
    {0},
    {0}
};

const int PIECE_F[PIECE_SIZE][PIECE_SIZE] = {
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0},
    {0}
};

const int PIECE_G[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,0,0,0},
    {1,1,0,0,0},
    {0,0,0,0,0},
    {0},
    {0}
};

const int PIECE_H[PIECE_SIZE][PIECE_SIZE] = {
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_I[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,1,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0},
    {0}
};
const int PIECE_J[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_K[PIECE_SIZE][PIECE_SIZE] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_L[PIECE_SIZE][PIECE_SIZE] = {
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_M[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_N[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,0,0},
    {1,1,1,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int PIECE_O[PIECE_SIZE][PIECE_SIZE] = {
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0}
};

const int PIECE_P[PIECE_SIZE][PIECE_SIZE] = {
    {1,1,1,1,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

const int[PIECE_SIZE][PIECE_SIZE] PIECES[16] = {
    PIECE_A,
    PIECE_B,
    PIECE_C,
    PIECE_D,
    PIECE_E,
    PIECE_F,
    PIECE_G,
    PIECE_H,
    PIECE_I,
    PIECE_J,
    PIECE_K,
    PIECE_L,
    PIECE_M,
    PIECE_N,
    PIECE_O,
    PIECE_P
};

void printPiece(const int piece[PIECE_SIZE][PIECE_SIZE]) {
  for (int y = 0; y < PIECE_SIZE; y++) {
    for (int x = 0; x < PIECE_SIZE; x++) {
      if (piece[x][y] == 1)
        printf("x");
      else
        printf(" ");
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
    printPiece(PIECE_A);
}
