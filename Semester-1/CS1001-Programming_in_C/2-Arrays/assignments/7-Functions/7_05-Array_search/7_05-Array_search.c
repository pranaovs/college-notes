// Search an element in an array using call by value and call by reference

#include <stdio.h>

int search_array(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return 1;
    }
  }
  return 0;
}

void search_array_ref(int arr[], int n, int key, int *found) {
  *found = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      *found = 1;
      return;
    }
  }
}

int main() {
  int n, key;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element to search: ");
  scanf("%d", &key);

  if (search_array(arr, n, key)) {
    printf("Element found in the array.\n");
  } else {
    printf("Element not found in the array.\n");
  }

  int found;
  search_array_ref(arr, n, key, &found);
  if (found) {
    printf("Element found in the array.\n");
  } else {
    printf("Element not found in the array.\n");
  }

  return 0;
}
