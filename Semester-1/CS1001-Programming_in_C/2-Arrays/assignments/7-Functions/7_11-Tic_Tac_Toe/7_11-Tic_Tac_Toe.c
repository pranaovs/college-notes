// Program to implement a simple 2-player Tic-Tac-Toe game
#include <stdio.h>

// Function prototypes
void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
int makeMove(char board[3][3], int row, int col, char player);
int checkWin(char board[3][3], char player);
int isBoardFull(char board[3][3]);

int main() {
  char board[3][3];         // 3x3 Tic-Tac-Toe board
  char currentPlayer = 'X'; // Player 'X' starts the game
  int row, col;             // Variables to store the row and column of the move

  // Initialize the board with empty spaces
  initializeBoard(board);

  // Main game loop
  while (1) {
    // Print the current state of the board
    printBoard(board);

    // Prompt the current player to enter their move
    printf("Player %c's turn. Enter row (0-2) and column (0-2): ",
           currentPlayer);
    scanf("%d %d", &row, &col);

    // Attempt to make the move
    if (makeMove(board, row, col, currentPlayer)) {
      // Check if the current player has won
      if (checkWin(board, currentPlayer)) {
        printBoard(board);
        printf("Player %c wins!\n", currentPlayer);
        break;
      }
      // Check if the board is full (draw)
      if (isBoardFull(board)) {
        printBoard(board);
        printf("It's a draw!\n");
        break;
      }
      // Switch to the other player
      currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } else {
      // Invalid move, prompt the player to try again
      printf("Invalid move. Try again.\n");
    }
  }

  return 0;
}

// Function to initialize the board with empty spaces
void initializeBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the current state of the board
void printBoard(char board[3][3]) {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i < 2) {
      printf("---+---+---\n");
    }
  }
  printf("\n");
}

// Function to make a move on the board
int makeMove(char board[3][3], int row, int col, char player) {
  // Check if the move is within bounds and the cell is empty
  if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
    return 0; // Invalid move
  }
  board[row][col] = player; // Place the player's mark on the board
  return 1;                 // Valid move
}

// Function to check if the current player has won
int checkWin(char board[3][3], char player) {
  // Check rows and columns for a win
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == player && board[i][1] == player &&
         board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player &&
         board[2][i] == player)) {
      return 1; // Player wins
    }
  }
  // Check diagonals for a win
  if ((board[0][0] == player && board[1][1] == player &&
       board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player &&
       board[2][0] == player)) {
    return 1; // Player wins
  }
  return 0; // No win
}

// Function to check if the board is full (draw)
int isBoardFull(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return 0; // Board is not full
      }
    }
  }
  return 1; // Board is full
}
