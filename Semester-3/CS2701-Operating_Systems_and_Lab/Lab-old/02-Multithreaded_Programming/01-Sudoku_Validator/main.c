#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// clang-format off
int sudoku[9][9] = {
                    {6, 2, 4, 5, 3, 9, 1, 8, 7},
                    {5, 1, 9, 7, 2, 8, 6, 3, 4},
                    {8, 3, 7, 6, 1, 4, 2, 9, 5},
                    {1, 4, 3, 8, 6, 5, 7, 2, 9},
                    {9, 5, 8, 2, 4, 7, 3, 6, 1},
                    {7, 6, 2, 3, 9, 1, 4, 5, 8},
                    {3, 7, 1, 9, 5, 6, 8, 4, 2},
                    {4, 9, 6, 1, 8, 2, 5, 7, 3},
                    {2, 8, 5, 4, 7, 3, 9, 1, 6}
};

// clang-format on

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int is_valid = 1; // shared

void exit_if_invalid(int condition) {
  if (!condition) {
    pthread_mutex_lock(&lock);
    if (is_valid) {
      is_valid = 0;
      pthread_mutex_unlock(&lock);
      printf("Sudoku solution is invalid\n");
      exit(EXIT_FAILURE);
    }
    pthread_mutex_unlock(&lock);
  }
}

void *check_rows(void *arg) {
  for (int i = 0; i < SIZE; i++) {
    int seen[SIZE] = {0};
    for (int j = 0; j < SIZE; j++) {
      int num = sudoku[i][j];
      if (num < 1 || num > 9 || seen[num - 1]++) {
        exit_if_invalid(0);
      }
    }
  }
  return NULL;
}

void *check_cols(void *arg) {
  for (int j = 0; j < SIZE; j++) {
    int seen[SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
      int num = sudoku[i][j];
      if (num < 1 || num > 9 || seen[num - 1]++) {
        exit_if_invalid(0);
      }
    }
  }
  return NULL;
}

typedef struct {
  int startRow;
  int startCol;
} SubgridArgs;

void *check_subgrid(void *arg) {
  SubgridArgs *args = (SubgridArgs *)arg;
  int seen[SIZE] = {0};
  for (int i = args->startRow; i < args->startRow + 3; i++) {
    for (int j = args->startCol; j < args->startCol + 3; j++) {
      int num = sudoku[i][j];
      if (num < 1 || num > 9 || seen[num - 1]++) {
        exit_if_invalid(0);
      }
    }
  }
  free(arg);
  return NULL;
}

int main() {
  pthread_t threads[11];

  // rows
  pthread_create(&threads[0], NULL, check_rows, NULL);

  // columns
  pthread_create(&threads[1], NULL, check_cols, NULL);

  // 3x3 subgrid
  int thread_index = 2;
  for (int row = 0; row < SIZE; row += 3) {
    for (int col = 0; col < SIZE; col += 3) {
      SubgridArgs *args = malloc(sizeof(SubgridArgs));
      args->startRow = row;
      args->startCol = col;
      pthread_create(&threads[thread_index++], NULL, check_subgrid, args);
    }
  }

  // Join all threads
  for (int i = 0; i < 11; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("Sudoku solution is valid\n");
  return EXIT_SUCCESS;
}
