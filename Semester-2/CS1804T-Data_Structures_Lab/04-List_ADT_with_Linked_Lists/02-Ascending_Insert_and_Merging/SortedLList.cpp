#include "SortedLList.h"

void SortedLList::insert(int ele) {

  // If list is empty or element is smaller than head
  if (head == nullptr || ele <= head->data) {
    insertbeg(ele);
    return;
  }

  Node *current = head;
  Node *prev = nullptr;

  // Find position to insert
  while (current != nullptr && current->data < ele) {
    prev = current;
    current = current->next;
  }

  // Insert new node between prev and current
  Node *newNode = new_node(ele, current);
  prev->next = newNode;
  size++;
}

void SortedLList::insertArrays(int arr1[], int size1, int arr2[], int size2) {
  int totalSize = size1 + size2;
  int *mergedArray = new int[totalSize];

  // Merge the two arrays
  std::copy(arr1, arr1 + size1, mergedArray);
  std::copy(arr2, arr2 + size2, mergedArray + size1);

  // Sort the merged array
  customSort(mergedArray, totalSize);

  // Insert the sorted elements into the linked list
  for (int i = 0; i < totalSize; ++i) {
    insert(mergedArray[i]);
  }

  delete[] mergedArray;
}

void SortedLList::customSort(int arr[], int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
