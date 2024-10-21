// Program to merge two arrays in ascending order into a single array in
// ascending order
#include <stdio.h>

int main() {

  int i = 0, j = 0, n = 0, m = 0, size;

  printf("Enter array size: ");
  scanf("%d", &size);

  int array1[size], array2[size], merged[size * 2];

  printf("Enter numbers for array 1 (separated by newline): ");
  for (i = 0; i < size; i++) {
    scanf("%d", &array1[i]);
  }

  printf("Enter numbers for array 2 (separated by newline): ");
  for (i = 0; i < size; i++) {
    scanf("%d", &array2[i]);
  }

  while (n < size && m < size) {
    if (array1[n] <=
        array2[m]) { // if elements being compared are equal, still the element
                     // will be taken from array1 to put in merged array (you
                     // can take it from array2 also, it makes no difference.
                     // We're just making sure sorting continues even if
                     // elements being compared are equal)
      merged[j] = array1[n];
      j++;
      n++;
    }

    if (array2[m] < array1[n]) {
      merged[j] = array2[m];
      j++;
      m++;
    }
  }

  if (n < size) { // if some elements still remaining in array1 after array2
                  // elements have all been put into merged array,they are put
                  // into merged array directly
    while (n < size) {
      merged[j] = array1[n];
      j++;
      n++;
    }

  } else if (m < size) { // if some elements still remaining in array2 after
                         // array1 elements have all been put into merged
                         // array,they are put into merged array directly
    while (m < size) {
      merged[j] = array2[m];
      j++;
      m++;
    }
  }

  printf("Merged array: ");
  for (j = 0; j < (size * 2); j++) {
    printf("%d ", merged[j]);
  }
  printf("\n");
}
