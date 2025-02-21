/* This is a list ADT implementation with rotation feature in C++ */

#include "CDLList.cpp"
#include <iostream>
using namespace std;

void displayMenu();
void reverse_array(int *arr, int size);

int main(int argc, char *argv[]) {

  CDLList list;

  int choice, ele, pos, k;

  while (true) {
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter element to insert at beginning: ";
      cin >> ele;
      list.insertbeg(ele);
      break;
    case 2:
      cout << "Enter element to insert at end: ";
      cin >> ele;
      list.insertend(ele);
      break;
    case 3:
      cout << "Enter element and position to insert: ";
      cin >> ele >> pos;
      list.insertpos(ele, pos);
      break;
    case 4:
      list.deletebeg();
      break;
    case 5:
      list.deleteend();
      break;
    case 6:
      cout << "Enter position to delete: ";
      cin >> pos;
      list.deletepos(pos);
      break;
    case 7:
      cout << "Enter element to search: ";
      cin >> ele;
      pos = list.search(ele);
      if (pos != -1)
        cout << "Element found at position: " << pos << endl;
      else
        cout << "Element not found" << endl;
      break;
    case 8:
      list.display();
      break;
    case 9:
      int *tmp_arr;
      list.alloccopy(&tmp_arr);

      for (int i = list.size - 1; i >= 0; i--) {
        cout << tmp_arr[i] << " ";
      }

      cout << endl;

      break;
    case 10:
      exit(0);
    default:
      cout << "Invalid choice!" << endl;
    }
  }

  return 0;
}

void displayMenu() {
  cout << "Menu:" << endl;
  cout << "1. Insert at beginning" << endl;
  cout << "2. Insert at end" << endl;
  cout << "3. Insert at position" << endl;
  cout << "4. Delete from beginning" << endl;
  cout << "5. Delete from end" << endl;
  cout << "6. Delete from position" << endl;
  cout << "7. Search" << endl;
  cout << "8. Display" << endl;
  cout << "9. Display reverse" << endl;
  cout << "10. Exit" << endl;
}
