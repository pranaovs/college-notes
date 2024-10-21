// Program to reverse a string
#include <stdio.h>

// Program assumes maxiumu size of the string is MAX_SIZE
#define MAX_SIZE 2048

int main() {
  int size = 0, i;
  char strarray[MAX_SIZE], temp;

  printf("Enter a string: ");

  // BUG: Do not use spaces in string input
  // TODO: Use fgets to get spaces into variable
  scanf("%s", strarray);

  while (strarray[size] != '\0') {
    size = size + 1;
  }

  for (i = 0; i < (size / 2); i++) {
    temp = strarray[i];
    strarray[i] = strarray[size - (i + 1)];
    strarray[size - (i + 1)] = temp;
  }

  printf("%s\n", strarray);
}
