// Convert a decimal number to binary number using recursion

#include <stdio.h>

// Global variable to store the quotient
int quo;

// Function to calculate the number of binary digits needed for a given decimal
// number
int Digits(int num) {
  int count = 1;
  while (num != 1) {
    num = num / 2;
    count += 1;
  }
  return count;
}

// Recursive function to convert decimal to binary
int Convert(int quo, int *ptr) {
  int rem;    // Remainder when dividing by 2
  int choice; // Choice to continue recursion or not

  if (quo == 1) {
    rem = 1;
    choice = 0; // Base case: stop recursion
  } else {
    rem = quo % 2; // Get remainder
    quo = quo / 2; // Update quotient
    choice = 1;    // Continue recursion
  }

  *ptr = rem; // Store remainder in the array

  if (choice) {
    ptr += 1;          // Move pointer to next position
    Convert(quo, ptr); // Recursive call
  }

  return 0;
}

int main() {
  int num, count;

  // Prompt user for input
  printf("Enter the number:");
  scanf("%d", &num);

  // Initialize global quotient variable
  quo = num;

  // Calculate the number of binary digits
  count = Digits(num);

  // Create an array to store binary digits
  int arr[count];
  int *ptr = arr;

  // Convert decimal to binary
  Convert(quo, ptr);

  // Print the binary number in reverse order
  for (int i = 0; i < count; i++) {
    printf("%d", arr[count - i - 1]);
  }

  printf("\n");

  return 0;
}
