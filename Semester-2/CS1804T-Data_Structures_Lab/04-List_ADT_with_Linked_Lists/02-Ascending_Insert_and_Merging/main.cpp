#include "SortedLList.cpp"

int main() {
  SortedLList list;
  int choice, element;
  int *arr1 = nullptr, *arr2 = nullptr;
  int size1 = 0, size2 = 0;

  while (true) {
    std::cout << "\n=== menu ===\n";
    std::cout << "1. insert element\n";
    std::cout << "2. create list 1 (arr1)\n";
    std::cout << "3. create list 2 (arr2)\n";
    std::cout << "4. append list 1 and list 2 into linked list\n";
    std::cout << "5. display\n";
    std::cout << "6. exit\n";
    std::cout << "enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "enter element to insert: ";
      std::cin >> element;
      list.insert(element);
      break;

    case 2:
      std::cout << "enter size of list 1: ";
      std::cin >> size1;
      delete[] arr1;
      arr1 = new int[size1];
      std::cout << "enter " << size1 << " elements:\n";
      for (int i = 0; i < size1; i++) {
        std::cin >> arr1[i];
      }
      break;

    case 3:
      std::cout << "enter size of list 2: ";
      std::cin >> size2;
      delete[] arr2;
      arr2 = new int[size2];
      std::cout << "enter " << size2 << " elements:\n";
      for (int i = 0; i < size2; i++) {
        std::cin >> arr2[i];
      }
      break;

    case 4:
      if (arr1 == nullptr || arr2 == nullptr) {
        std::cout << "please create both lists first!\n";
      } else {
        list.insertArrays(arr1, size1, arr2, size2);
      }
      break;

    case 5:
      list.display();
      break;

    case 6:
      delete[] arr1;
      delete[] arr2;
      return 0;

    default:
      std::cout << "invalid choice! please try again.\n";
    }
  }
  return 0;
}
