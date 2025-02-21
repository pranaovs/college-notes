#include "CDLList.cpp"
#include "DLList.cpp"
#include "LList.cpp"

using namespace std;
int main(int argc, char *argv[]) {
  CDLList list;

  // Insertion and deletion at the beginning
  list.insertbeg(0);
  list.deletebeg();
  try {
    list.deletebeg();
  } catch (const char *msg) {
    cout << msg << endl;
  }
  list.insertbeg(0);
  list.deletebeg(5);
  list.deletebeg();

  // Insertion and deletion at the end
  list.insertend(1);
  list.deleteend();
  try {
    list.deleteend();
  } catch (const char *msg) {
    cout << msg << endl;
  }
  list.insertend(1);
  list.deleteend(5);
  list.deleteend();

  // Insertion and deletion and beginning and end
  list.insertbeg(0);
  list.deleteend();
  list.insertend(1);
  list.deletebeg();

  try {
    list.deletebeg();
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deleteend();
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletebeg(5);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deleteend(5);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(5);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(0);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(list.size);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  // Insertion and deletion at position
  try {
    list.insertpos(0, 0);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.insertpos(1, 1);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.insertpos(2, 2);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(1);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(5);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.insertpos(12, 12);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(12);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.insertpos(23, list.size);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  try {
    list.deletepos(list.size);
  } catch (const char *msg) {
    cout << msg << endl;
  }

  // Array insertions
  int arr[] = {0, 1, 2, 3, 4, 5};
  list.insertbeg(arr, 6);
  list.insertend(arr, 6);

  // Searching
  list.search(0);
  list.search(1);
  list.search(0); // Search in empty list

  // Displaying the list
  list.display();

  return 0;
}
