#include "LList.cpp"

class SortedLList : public LList {

private:
  void customSort(int arr[], int size);

public:
  void insert(int ele);
  void insertArrays(int arr1[], int size1, int arr2[], int size2);
};
