/* This is a list ADT implementation with rotation feature in C++ */

#include "AList.cpp"
#include <iostream>
using namespace std;

class rotatelist : public AList {
public:
  void rotateWithExtraArray(int k);
  void rotateInPlace(int k);
  void rotateCyclic(int k);
};

void displayMenu();
void displayRotateMenu();

int main(int argc, char *argv[]) {

  rotatelist list;

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
      while (true) {
        displayRotateMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 4)
          break;
        cout << "Enter k: ";
        cin >> k;
        if (choice == 1)
          list.rotateWithExtraArray(k);
        else if (choice == 2)
          list.rotateInPlace(k);
        else if (choice == 3)
          list.rotateCyclic(k);
      }
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
  cout << "9. Rotate" << endl;
  cout << "10. Exit" << endl;
}

void displayRotateMenu() {
  cout << "Rotate Menu:" << endl;
  cout << "1. Rotate with extra array (O(n))" << endl;
  cout << "2. Rotate in place (O(1) space)" << endl;
  cout << "3. Rotate cyclically (O(1) space)" << endl;
  cout << "4. Back to main menu" << endl;
}

/* Rotate the list by k positions with an extra array
 * Arguments:
 * int k: number of positions to rotate
 */
void rotatelist::rotateWithExtraArray(int k) {
  int n = AList::getsize();
  k = k % n;
  int *temp = new int[n];

  for (int i = 0; i < n; i++) {
    temp[(i + k) % n] = AList::get(i);
  }

  for (int i = 0; i < n; i++) {
    AList::set(i, temp[i]);
  }

  delete[] temp;
}

/* Rotate the list in place by k positions in O(1) space
 * Arguments:
 * int k: number of positions to rotate
 */
void rotatelist::rotateInPlace(int k) {
  int n = AList::getsize();
  k = k % n;

  // Reverse the entire array
  AList::reverse(0, n - 1);
  // Reverse the first k elements
  AList::reverse(0, k - 1);
  // Reverse the remaining elements
  AList::reverse(k, n - 1);
}

/* Rotate the list cyclically by k positions in O(1) space
 * Arguments:
 * int k: number of positions to rotate
 */
void rotatelist::rotateCyclic(int k) {
  int n = AList::getsize();
  k = k % n;
  int count = 0;

  for (int start = 0; count < n; start++) {
    int current = start;
    int prev = AList::get(start);

    do {
      int next = (current + k) % n;
      int temp = AList::get(next);
      AList::set(next, prev);
      prev = temp;
      current = next;
      count++;
    } while (start != current);
  }
}
