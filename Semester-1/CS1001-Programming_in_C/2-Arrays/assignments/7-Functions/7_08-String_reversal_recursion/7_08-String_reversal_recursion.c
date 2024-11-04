// Program to reverse a string using recursion

#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverse(const char str1[], char str2[], int index, int len);

int main() {
  char str1[100];
  int len;

  // Prompt user for input
  printf("Enter the string you wish to reverse: ");
  fgets(str1, sizeof(str1), stdin);

  // Remove the newline character from the input string if present
  len = strlen(str1);
  if (str1[len - 1] == '\n') {
    str1[len - 1] = '\0';
    len--;
  }

  // Create an array to hold the reversed string
  char str2[len + 1]; // +1 for the null terminator

  // Initialize the index for recursion
  int index = 0;

  // Call the recursive function to reverse the string
  reverse(str1, str2, index, len);

  // Null-terminate the reversed string
  str2[len] = '\0';

  // Print the reversed string
  printf("The reversed string is: %s\n", str2);

  return 0;
}

// Recursive function to reverse a string
void reverse(const char str1[], char str2[], int index, int len) {
  if (index < len) {
    // Copy character from the end of str1 to the beginning of str2
    str2[index] = str1[len - 1 - index];
    // Recur for the next character
    reverse(str1, str2, index + 1, len);
  }
}
