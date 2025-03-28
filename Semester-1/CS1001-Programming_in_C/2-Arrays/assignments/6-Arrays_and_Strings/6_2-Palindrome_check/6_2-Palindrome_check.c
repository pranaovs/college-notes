// Program to check if given string is a palindrome

#include <stdio.h>

// Program assumes maxiumu size of the string is MAX_SIZE
#define MAX_SIZE 8192

int main() {

  int size = 0, i, flag = 0;
  char strarray[MAX_SIZE], temp;

  printf("Enter a string: ");

  // BUG: Do not use spaces in string input
  // TODO: Use fgets to get spaces into variable
  scanf("%s", strarray);

  while (strarray[size] != '\0') {
    size = size + 1;
  }

  for (i = 0; i < (size / 2); i++) {
    if (strarray[i] != strarray[size - (i + 1)]) {
      flag = 1;
    }
  }

  if (flag == 0) {
    printf("%s is a palindrome\n", strarray);
  } else {
    printf("%s is not a palindrome\n", strarray);
  }
}
