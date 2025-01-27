#include "sort.h"
#include <iostream>
#include <vector>

using namespace std;
Arrayfun arrayfun;

void linearSearch(const vector<int> &arr, int key) {
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == key) {
      cout << "Element found at index " << i << endl;
      return;
    }
  }
  cout << "Element not found" << endl;
}

void binarySearch(const vector<int> &arr, int key) {
  int left = 0, right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
      cout << "Element found at index " << mid << endl;
      return;
    }
    if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << "Element not found" << endl;
}

int main() {
  vector<int> arr;
  int choice, element, key;

  cout << "Enter the number of elements: ";
  int n;
  cin >> n;

  cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> element;
    arr.push_back(element);
  }

  int sortChoice;
  cout << "\nEnter sorting algorithm:\n";
  cout << "1. Bubble Sort\n";
  cout << "2. Insertion Sort\n";
  cout << "3. Selection Sort\n";
  cin >> sortChoice;

  switch (sortChoice) {
  case 1:
    arrayfun.bubblesort(arr);
    break;
  case 2:
    arrayfun.insertionsort(arr);
    break;
  case 3:
    arrayfun.selectionsort(arr);
  }

  do {
    cout << "\nMenu:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter the element to search: ";
      cin >> key;
      linearSearch(arr, key);
      break;
    case 2:
      cout << "Enter the element to search: ";
      cin >> key;
      binarySearch(arr, key);
      break;
    case 3:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 3);

  return 0;
}
