/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

#include "CDLList.h"
#include <iostream>

/* Create a new node
 * Arguments:
 * int ele: The element to be inserted
 * struct CDLList::Node *next: The next node in the list
 * struct CDLList::Node *prev: The prev node in the list
 * Returns:
 * struct CDLList::Node *: The newly created node
 */
struct CDLList::Node *CDLList::new_node(int ele, struct CDLList::Node *next,
                                        struct CDLList::Node *prev) {
  struct CDLList::Node *newnode = new CDLList::Node;
  newnode->data = ele;
  newnode->next = next;
  newnode->prev = prev;

  this->count++;
  this->size = this->count;

  return newnode;
}

/* Function to delete a node (and deallocate memory)
 * Arguments:
 * struct CDLList::Node *node: The node to be deleted
 * Returns:
 * None
 */
void CDLList::delete_node(struct CDLList::Node *node) {
  delete node;
  this->count--;
  this->size = this->count;
}

/* Constructor for the CDLList class
 * Initializes the count, size and this->head variables to empty values
 * Arguments:
 * None
 * Returns:
 * None
 */
CDLList::CDLList() {
  this->head = nullptr;
  this->count = 0;
  this->size = 0;
}

/* Return the size of the list
 * A shortcut to accessing (int) this->count (which is internal)
 * (int) this->size can also be used
 */
int CDLList::getsize() { return this->size; }

/* Copies all list elements into int * ptr argument.
 * Make sure to have sufficient array size.
 * Arguments:
 * int * ptr: to copy the list elements into
 * Returns:
 * int: number of elements in the list
 */
int CDLList::copy(int **ptr) { return this->copy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns: int - number of elements in the new list (count)
 */
int CDLList::copy(int **ptr, int count) {

  struct CDLList::Node *tmp = this->head;
  for (int i = 0; i < count; i++) {
    (*ptr)[i] = tmp->data;
    tmp = tmp->next;
  }
  return count;
}

/* Copies all list elements into int * ptr argument.
 * Also (re)allocates memory.
 * You are responsible for freeing the memory.
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns:
 * int: number of elements in the list
 * NOTE: Any value stored in * ptr will be overwritten
 */
int CDLList::alloccopy(int **ptr) { return alloccopy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements.
 * Also (re)allocates memory.
 * You are responsible for freeing the memory.
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns:
 * int: number of elements in the list
 * NOTE: Any value stored in * ptr will be overwritten
 */
int CDLList::alloccopy(int **ptr, int count) {
  *ptr = new int[count];
  return copy(ptr, count);
}

/* Print the list elements to stdout
 * Arguments:
 * None
 * Returns:
 * None
 */
void CDLList::display() {
  if (this->head == nullptr) {
    std::cout << "List is empty" << std::endl;
    return;
  }

  struct CDLList::Node *tmp = this->head;

  do {
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  } while (tmp != this->head);

  std::cout << std::endl;
}

/* Print the list to stdout in both forward and reverse order
 * Arguments:
 * None
 * Returns:
 * None
 */
void CDLList::double_display() {
  if (this->head == nullptr) {
    std::cout << "List is empty" << std::endl;
    return;
  }

  struct CDLList::Node *tmp = this->head;

  // Forward display
  std::cout << "Forward: ";
  do {
    std::cout << tmp->data << " -> ";
    tmp = tmp->next;
  } while (tmp != this->head);
  std::cout << tmp->data << " ";
  std::cout << std::endl;

  // Backward display
  tmp = this->head->prev; // Start from the last node
  std::cout << "Reverse: ";
  do {
    std::cout << tmp->data << " <- ";
    tmp = tmp->prev;
  } while (tmp != this->head->prev);
  std::cout << tmp->data << " ";
  std::cout << std::endl;
}

/* Insert a node at the beginning of the list
 * Arguments:
 * int ele: The element to be inserted
 * Returns:
 * None
 */
void CDLList::insertbeg(int ele) { this->insertpos(ele, 0); }

/* Insert n elements from an array to the beginning of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [5, 6, 7, 1, 2, 3, 4]
 */
void CDLList::insertbeg(int *list, int count) {
  for (int i = count - 1; i >= 0; i--) {
    this->insertbeg(list[i]);
  }
}

/* Insert a node at the end of the list
 * Arguments:
 * int ele: The element to be inserted
 * Returns:
 * None
 */
void CDLList::insertend(int ele) { this->insertpos(ele, this->count); }

/* Insert n elements from an array to the end of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [1, 2, 3, 4, 5, 6, 7]
 */
void CDLList::insertend(int *list, int count) {
  for (int i = 0; i < count; i++) {
    this->insertend(list[i]);
  }
}

/* Insert a node at a specific position in the list
 * Arguments:
 * int ele: The element to be inserted
 * int pos: The position at which the element is to be inserted
 * Returns:
 * bool: True if the element was inserted, false otherwise
 */
bool CDLList::insertpos(int ele, int pos) {
  if (pos < 0 || pos > this->count) {
    return false;
  }

  // Handle the case where the element is to be inserted at the beginning
  if (pos == 0) {
    // Update the previous pointer to head only if list is empty
    if (this->head == nullptr) {
      struct CDLList::Node *newnode = new_node(ele, nullptr, nullptr);
      this->head = newnode;
      this->head->next = this->head;
      this->head->prev = this->head;
    } else {
      struct CDLList::Node *newnode =
          new_node(ele, this->head, this->head->prev);
      this->head->prev->next = newnode;
      this->head->prev = newnode;
      this->head = newnode;
    }
    return true;
  } else {
    struct CDLList::Node *tmp = this->head;
    for (int i = 0; i < pos - 1; i++) {
      tmp = tmp->next;
    }

    struct CDLList::Node *newnode = new_node(ele, tmp->next, tmp);
    tmp->next->prev = newnode;
    tmp->next = newnode;

    return true;
  }
}

/* Delete the first node from the List
 * Arguments:
 * None
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
int CDLList::deletebeg() { return this->deletepos(0); }

/* Delete the first n elements of the list
 * Returns:
 * bool: Success/failure status
 */
bool CDLList::deletebeg(int count) {
  if (count < 1 || count > this->count) {
    return false;
  }
  for (int i = 0; i < count; i++) {
    this->deletebeg();
  }
  return true;
}
/* Delete a node from the end of the list
 * Arguments:
 * None
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
int CDLList::deleteend() { return this->deletepos(this->count - 1); }

/* Delete the last n elements of the list
 * Returns:
 * bool: Success/failure status
 */
bool CDLList::deleteend(int n) {
  if (n < 1 || n > this->count) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    this->deleteend();
  }
  return true;
}

/* Delete a node from a position
 * Arguments:
 * int pos: position to delete the element from
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
int CDLList::deletepos(int pos) {
  if (pos < 0 || pos >= this->count) {
    throw "Invalid position";
  }

  struct CDLList::Node *tmp = this->head;
  for (int i = 0; i < pos; i++) {
    tmp = tmp->next;
  }

  int ele = tmp->data;

  // If the list has only one node
  if (this->count == 1) {
    this->head = nullptr;
  } else {
    // Update the next pointer of the previous node
    tmp->prev->next = tmp->next;

    // Update the prev pointer of the next node
    tmp->next->prev = tmp->prev;

    // Change head if the element to be deleted is the first element
    if (tmp == this->head) {
      this->head = tmp->next;
    }
  }

  delete_node(tmp);

  return ele;
}

/* Search for an element in the list
 * Shortcut to this->linearsearch()
 * Arguments:
 * int ele: element to search for
 * Returns:
 * int: index of the element in the list
 * -1 if not found
 */
int CDLList::search(int ele) { return this->linearsearch(ele); }

int CDLList::linearsearch(int ele) {
  struct CDLList::Node *tmp = this->head;
  for (int i = 0; i < this->count; i++) {
    if (tmp->data == ele) {
      return i;
    }
    tmp = tmp->next;
  }
  return -1;
}

/* Get the element at a given position
 * Arguments:
 * int pos: position to get the element from
 * Returns:
 * int: element at the position
 * NOTE: Uses unsigned int to handle negative positions
 * NOTE: The list is treated as a circular list
 */
int CDLList::get(unsigned int pos) {
  if (pos < 0) {
    throw "Invalid position";
  }

  pos = pos % this->count;

  struct Node *tmp = this->head;
  for (unsigned int i = 0; i < pos; i++) {
    tmp = tmp->next;
  }

  return tmp->data;
}

/* Set the value of given position
 * Arguments:
 * int pos: position to set the element
 * int value: value to set
 * Returns:
 * bool: Success/failure status
 */
bool CDLList::set(int pos, int value) {
  if (pos < 0 || pos >= this->count) {
    return false;
  }

  struct Node *tmp = this->head;
  for (int i = 0; i < pos; ++i) {
    tmp = tmp->next;
  }

  tmp->data = value;
  return true;
}
