// Program to multiply two matrices

#include <stdio.h>

// Function to multiply two matrices
void Multiply(int matr1[][10], int matr2[][10], int row1, int col1, int row2,
              int col2, int ans[][10]) {
  // Iterate over each row of the first matrix
  for (int i = 0; i < row1; i++) {
    // Iterate over each column of the second matrix
    for (int j = 0; j < col2; j++) {
      int sum = 0; // Initialize sum for the current element
      // Perform the dot product of the row and column
      for (int k = 0; k < col1; k++) {
        sum += matr1[i][k] * matr2[k][j];
      }
      ans[i][j] = sum; // Store the result in the answer matrix
    }
  }
}

int main() {
  int row1, col1, row2, col2;

  // Input dimensions of the first matrix
  printf("Enter the dimensions of the matrix 1 (rows and columns): ");
  scanf("%d %d", &row1, &col1);

  // Input dimensions of the second matrix
  printf("Enter the dimensions of the matrix 2 (rows and columns): ");
  scanf("%d %d", &row2, &col2);

  // Check if matrix multiplication is possible
  if (col1 != row2) {
    printf("Multiplication cannot be performed\n");
    return 1;
  }

  // Declare matrices with a maximum size of 10x10
  int matr1[10][10], matr2[10][10], ans[10][10];

  // Input elements of the first matrix
  printf("For Matrix 1:\n");
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      printf("Enter the element at (%d,%d): ", i, j);
      scanf("%d", &matr1[i][j]);
    }
  }

  // Input elements of the second matrix
  printf("For Matrix 2:\n");
  for (int i = 0; i < row2; i++) {
    for (int j = 0; j < col2; j++) {
      printf("Enter the element at (%d,%d): ", i, j);
      scanf("%d", &matr2[i][j]);
    }
  }

  // Call the function to multiply the matrices
  Multiply(matr1, matr2, row1, col1, row2, col2, ans);

  // Output the resulting matrix
  printf("The answer matrix is:\n");
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
