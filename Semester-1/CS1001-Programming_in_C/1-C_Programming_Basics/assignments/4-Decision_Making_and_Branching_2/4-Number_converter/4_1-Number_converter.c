// Simple program to convert decimal to binary, octal and hexadecimal values
// Only supported till 4 bits. Values are hardcoded so not extensible.

#include <stdio.h>

int main() {

  int num;

  printf("Enter a decimal number: ");
  scanf("%d", &num);

  // Break if number cannot be represented in 4 binary bits
  if (num > 15 || num < 0) {
    printf("Exception: The number %d cannot be represented in 4 bits\n", num);
    return 22; // Exit code for invalid argument
  }

  if (num == 0) {
    printf("Binary: 00\n");
    printf("Octal: 0\n");
    printf("Hexadecimal: 0\n");
  }
  if (num == 1) {
    printf("Binary: 01\n");
    printf("Octal: 1\n");
    printf("Hexadecimal: 1\n");
  }
  if (num == 2) {
    printf("Binary: 10\n");
    printf("Octal: 2\n");
    printf("Hexadecimal: 2\n");
  }
  if (num == 3) {
    printf("Binary: 11\n");
    printf("Octal: 3\n");
    printf("Hexadecimal: 3\n");
  }
  if (num == 4) {
    // Binary of numbers greater than 4 exceeds 2 bits, hence ignore binary
    printf("Octal: 4\n");
    printf("Hexadecimal: 4\n");
  }
  if (num == 5) {
    printf("Octal: 5\n");
    printf("Hexadecimal: 5\n");
  }
  if (num == 6) {
    printf("Octal: 6\n");
    printf("Hexadecimal: 6\n");
  }
  if (num == 7) {
    printf("Octal: 7\n");
    printf("Hexadecimal: 7\n");
  }
  if (num == 8) {
    printf("Octal: 10\n");
    printf("Hexadecimal: 8\n");
  }
  if (num == 9) {
    printf("Octal: 11\n");
    printf("Hexadecimal: 9\n");
  }
  if (num == 10) {
    printf("Octal: 12\n");
    printf("Hexadecimal: A\n");
  }
  if (num == 11) {
    printf("Octal: 13\n");
    printf("Hexadecimal: B\n");
  }
  if (num == 12) {
    printf("Octal: 14\n");
    printf("Hexadecimal: C\n");
  }
  if (num == 13) {
    printf("Octal: 15\n");
    printf("Hexadecimal: D\n");
  }
  if (num == 14) {
    printf("Octal: 16\n");
    printf("Hexadecimal: E\n");
  }
  if (num == 15) {
    printf("Octal: 17\n");
    printf("Hexadecimal: F\n");
  }
  return 0;
}
