#include <stdio.h>
#include <string.h>

// Function to reverse the string using recursion
void reverse(const char str1[], char str2[], int i, int len);

int main() {
  char str1[100];
  int len;

  // Prompt user for input
  printf("Enter the string: ");
  fgets(str1, sizeof(str1), stdin);

  // Calculate the length of the input string
  len = strlen(str1);

  // Remove the newline character if present
  if (str1[len - 1] == '\n') {
    str1[len - 1] = '\0';
    len--;
  }

  // Declare the reversed string with the same length as the input string
  char str2[len + 1];

  // Initialize the reversed string
  reverse(str1, str2, 0, len);
  str2[len] = '\0'; // Null-terminate the reversed string

  // Check if the original string and the reversed string are the same
  if (strcmp(str1, str2) == 0) {
    printf("%s is a palindrome\n", str1);

  } else {
    printf("%s is not a palindrome\n", str1);
  }

  return 0;
}

// Function to reverse the string using recursion
void reverse(const char str1[], char str2[], int i, int len) {
  if (i < len) {
    str2[i] = str1[len - 1 - i];
    reverse(str1, str2, i + 1, len);
  }
}
