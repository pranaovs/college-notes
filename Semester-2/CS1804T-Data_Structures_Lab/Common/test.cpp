#include "LList.cpp"

int main(int argc, char *argv[]) {
  LList list;

  // Insertion and deletion at the beginning
  list.insertbeg(0);
  list.deletebeg();
  list.deletebeg();
  list.insertbeg(0);
  list.deletebeg(5);
  list.deletebeg();

  // Insertion and deletion at the end
  list.insertend(1);
  list.deleteend();
  list.deleteend();
  list.insertend(1);
  list.deleteend(5);
  list.deleteend();

  // Insertion and deletion and beginning and end
  list.insertbeg(0);
  list.deleteend();
  list.insertend(1);
  list.deletebeg();

  // Deleting empty list
  list.deletebeg();
  list.deleteend();
  list.deletebeg(5);
  list.deleteend(5);
  list.deletepos(5);
  list.deletepos(0);
  list.deletepos(list.size);

  // Insertion and deletion at position
  list.insertpos(0, 0);
  list.insertpos(1, 1);
  list.insertpos(2, 2);
  list.deletepos(1);
  list.deletepos(5);
  list.insertpos(12, 12);
  list.deletepos(12);
  list.insertpos(23, list.size);
  list.deletepos(list.size);

  // Searching
  list.search(0);
  list.search(1);
  list.deletebeg(list.size);
  list.search(0); // Search in empty list

  // Displaying the list
  list.display();

  return 0;
}
