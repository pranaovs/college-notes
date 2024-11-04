// Count the number of characters using call by value and call by reference

#include <stdio.h>

int char_count_val(char str[]) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}

int char_count_ref(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    (count)++;
  }
  return count;
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);

  printf("Number of characters in the string using call by value: %d\n",
         char_count_val(str));

  printf("Number of characters in the string using call be reference: %d\n",
         char_count_ref(str));

  return 0;
}
