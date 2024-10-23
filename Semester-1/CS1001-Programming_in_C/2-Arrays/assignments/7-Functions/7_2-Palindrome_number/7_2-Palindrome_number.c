// Program to check if given string is a palindrome

#include <stdbool.h>
#include <stdio.h>

// Program assumes maxiumum size of the string is MAX_SIZE
#define MAX_SIZE 8192

bool checkPalindrome(char *inp) {

  int size = 0, i;
  while (inp[size] != '\0') {
    size = size + 1;
  }

  for (i = 0; i < (size / 2); i++) {
    if (inp[i] != inp[size - (i + 1)]) {
      return false;
    }
  }

  return true;
}

int main() {

  char strarray[MAX_SIZE], temp;

  printf("Enter a number: ");

  scanf("%s", strarray);

  if (checkPalindrome(strarray)) {
    printf("%s is a palindrome\n", strarray);
  } else {
    printf("%s is not a palindrome\n", strarray);
  }
}
