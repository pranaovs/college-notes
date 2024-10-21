// Program to sort and invert sort an array

#include <stdio.h>

int main() {

  int size, i, j, k, temp;
  printf("Enter size of array: ");
  scanf("%d", &size);

  int numarray[size];
  printf("Enter numbers for array:");
  for (i = 0; i < size; i++) {
    scanf("%d",
          &numarray[i]); // doing "%d\n" here will cause the scanf to get one
                         // extra input from user, though it won't include it
  }

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) { // j=i+1 so that it always compares with
                                     // the NEXT element in the array
      if (numarray[i] > numarray[j]) {
        temp = numarray[i];
        numarray[i] = numarray[j];
        numarray[j] = temp;
      }
    }
  }

  printf("Ascending order: ");
  for (i = 0; i < size; i++) {
    printf("%d ", numarray[i]);
  }

  printf("\n");

  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      if (numarray[i] < numarray[j]) {
        temp = numarray[i];
        numarray[i] = numarray[j];
        numarray[j] = temp;
      }
    }
  }

  printf("Descending order: ");
  for (i = 0; i < size; i++) {
    printf("%d ", numarray[i]);
  }

  printf("\n");
}
