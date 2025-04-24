// C++ header file to abstract the sorting algorithms

#include <iostream>
#include <vector>

class Arrayfun {

private:
  void swap(int *item1, int *item2) {
    int tmp = *item1;
    *item1 = *item2;
    *item2 = tmp;
  }

public:
  void print(const std::vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
      std::cout << array[i] << " ";
    }
    std::cout << std::endl;
  }
  void bubblesort(std::vector<int> &array) {
    for (int i = 0; i < array.size(); i++) {
      for (int j = i; j < array.size(); j++) {
        if (array[i] > array[j]) {
          swap(&array[i], &array[j]);
        }
      }
    }
  }
  void insertionsort(std::vector<int> &array) {
    for (int i = 1; i < array.size(); i++) {
      int key = array[i];
      int j = i - 1;
      while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j = j - 1;
      }
      array[j + 1] = key;
    }
  }

  void selectionsort(std::vector<int> &array) {
    for (int i = 0; i < array.size() - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < array.size(); j++) {
        if (array[j] < array[minIndex]) {
          minIndex = j;
        }
      }
      if (minIndex != i) {
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
      }
    }
  }
};
