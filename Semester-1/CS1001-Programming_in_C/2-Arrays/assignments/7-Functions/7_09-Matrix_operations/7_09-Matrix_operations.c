// Program to perform matrix addition or subtraction based on user input

#include <stdio.h>

// Main function
int main() {
  int row, col;

  // Prompt user for matrix dimensions
  printf("Enter the dimensions of the matrix: ");
  scanf("%d %d", &row, &col);

  // Declare matrices and result matrix
  int matr1[row][col];
  int matr2[row][col];
  int ans[row][col];
  char mode;

  // Input elements for Matrix 1
  printf("For Matrix 1:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("Enter the element at (%d,%d): ", i, j);
      scanf("%d", &matr1[i][j]);
    }
  }

  // Input elements for Matrix 2
  printf("For Matrix 2:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("Enter the element at (%d,%d): ", i, j);
      scanf("%d", &matr2[i][j]);
    }
  }

  // Clear input buffer
  while (getchar() != '\n')
    ;

  // Prompt user for operation mode
  printf("Enter '+' for addition or '-' for subtraction: ");
  scanf("%c", &mode);

  // Perform matrix addition or subtraction based on user input
  if (mode == '+') {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        ans[i][j] = matr1[i][j] + matr2[i][j];
      }
    }
  } else if (mode == '-') {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        ans[i][j] = matr1[i][j] - matr2[i][j];
      }
    }
  } else {
    // Handle invalid input
    printf("Invalid Input\n");
    return 1;
  }

  // Print the result matrix
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("The element at (%d,%d) is %d\n", i, j, ans[i][j]);
    }
  }

  return 0;
}
