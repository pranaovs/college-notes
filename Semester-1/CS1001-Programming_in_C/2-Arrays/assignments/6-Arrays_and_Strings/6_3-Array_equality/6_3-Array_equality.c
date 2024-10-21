// Program to check if two arrays are identical

#include <stdio.h>

int main() {

  int size, i, flag = 0;

  printf("Enter size of arrays: ");
  scanf("%d", &size);

  char array1[size], array2[size];

  printf("Enter characters for array 1:");
  for (i = 0; i < size; i++) {
    scanf(" %c", &array1[i]);
  }

  printf("Enter characters for array 2:");
  for (i = 0; i < size; i++) {
    scanf(" %c", &array2[i]);
  }

  for (i = 0; i < size; i++) {
    if (array1[i] != array2[i]) {
      flag = 1;
      // Break out of the loop if any one element is different
      break;
    }
  }

  if (flag == 0) {
    printf("Both arrays are equal\n");
  } else {
    printf("Both arrays are not equal\n");
  }
}
