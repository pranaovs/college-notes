#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;

Arrayfun arrayfun;

int main() {
  vector<int> arr;
  int choice, num;

  while (true) {
    cout << "Menu:\n";
    cout << "1. Add number\n";
    cout << "2. Binary sort array\n";
    cout << "3. Selection sort array\n";
    cout << "4. Insertion sort array\n";
    cout << "5. Print array\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter number to add: ";
      cin >> num;
      arr.push_back(num);
      break;
    case 2:
      arrayfun.bubblesort(arr);
      cout << "Array sorted.\n";
      break;
    case 3:
      arrayfun.selectionsort(arr);
      cout << "Array sorted.\n";
      break;

    case 4:
      arrayfun.insertionsort(arr);
      cout << "Array sorted.\n";
      break;
    case 5:
      cout << "Array: ";
      arrayfun.print(arr);
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}
