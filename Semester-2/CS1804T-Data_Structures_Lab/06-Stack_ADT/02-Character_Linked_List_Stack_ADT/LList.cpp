/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

#include "LList.h"
#include <iostream>

/* Create a new node
 * Arguments:
 * int ele: The element to be inserted
 * struct LList::Node *next: The next node in the list
 * Returns:
 * struct LList::Node *: The newly created node
 * Time complexity: O(1)
 */
struct LList::Node *LList::new_node(char ele, struct LList::Node *next) {
  struct LList::Node *newnode = new LList::Node;
  newnode->data = ele;
  newnode->next = next;

  this->count++;
  this->size = this->count;

  return newnode;
}

/* Function to delete a node (and deallocate memory)
 * Arguments:
 * struct LList::Node *node: The node to be deleted
 * Returns:
 * None
 * Time complexity: O(1)
 */
void LList::delete_node(struct LList::Node *node) {
  delete node;
  this->count--;
  this->size = this->count;
}

/* Constructor for the LList class
 * Initializes the count, size and this->head variables to empty values
 * Arguments:
 * None
 * Returns:
 * None
 * Time complexity: O(1)
 */
LList::LList() {
  this->head = nullptr;
  this->count = 0;
  this->size = 0;
}

/* Destructor for the LList class
 * Deallocates memory for all nodes in the list
 * Arguments:
 * None
 * Returns:
 * None
 * Time complexity: O(n) where n is the number of nodes in the list
 */
LList::~LList() {
  struct Node *current = this->head;
  struct Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    delete_node(current);
    current = next;
  }

  this->head = nullptr;
  this->count = 0;
  this->size = 0;
}

/* Return the size of the list
 * A shortcut to accessing (int) this->count (which is internal)
 * (int) this->size can also be used
 * Time complexity: O(1)
 */
int LList::getsize() { return this->size; }

/* Copies all list elements into int * ptr argument.
 * Make sure to have sufficient array size.
 * Arguments:
 * int * ptr: to copy the list elements into
 * Returns:
 * int: number of elements in the list
 * Time complexity: O(n) where n is the number of nodes in the list
 */
int LList::copy(char **ptr) { return this->copy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns: int - number of elements in the new list (count)
 * Time complexity: O(n) where n is the number of nodes to copy
 */
int LList::copy(char **ptr, int count) { return this->copy(ptr, 0, count - 1); }

/* Copies the list elements into int * ptr argument from given
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns: int - number of elements in the new list (count)
 * Time complexity: O(end) to reach the end position from the beginning
 */
int LList::copy(char **ptr, int start, int end) {

  if (start < 0 || end >= this->count) {
    return -1;
  }

  struct LList::Node *tmp = this->head;
  for (int i = 0; i < start; i++) {
    tmp = tmp->next;
  }

  int arr_pos = 0;
  for (int j = start; j <= end; j++) {
    (*ptr)[arr_pos] = tmp->data;
    arr_pos++;
    tmp = tmp->next;
  }
  return end - start + 1;
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
 * Time complexity: O(n) where n is the number of nodes in the list
 */
int LList::alloccopy(char **ptr) { return alloccopy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements.
 * Also (re)allocates memory.
 * You are responsible for freeing the memory.
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns:
 * int: number of elements in the list
 * NOTE: Any value stored in * ptr will be overwritten
 * Time complexity: O(count) where count is the number of elements to copy
 */
int LList::alloccopy(char **ptr, int count) {
  return this->alloccopy(ptr, 0, count - 1);
}

int LList::alloccopy(char **ptr, int start, int end) {

  if (start < 0 || end >= this->count) {
    return -1;
  }

  int arr_size = end - start + 1;
  *ptr = new char[arr_size];
  return copy(ptr, start, end);
}

/* Print the list elements to stdout
 * Arguments:
 * None
 * Returns:
 * None
 * Time complexity: O(n) where n is the number of nodes in the list
 */
void LList::display() {
  struct LList::Node *tmp = this->head;

  while (tmp != nullptr) {
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  }

  std::cout << std::endl;
}

/* Insert a node at the beginning of the list
 * Arguments:
 * int ele: The element to be inserted
 * Returns:
 * None
 * Time complexity: O(1)
 */
void LList::insertbeg(char ele) { this->insertpos(ele, 0); }

/* Insert n elements from an array to the beginning of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [5, 6, 7, 1, 2, 3, 4]
 * Time complexity: O(count) where count is the number of elements in the array
 */
void LList::insertbeg(char *list, int count) {
  for (int i = count - 1; i >= 0; i--) {
    this->insertbeg(list[i]);
  }
}

/* Insert a node at the end of the list
 * Arguments:
 * int ele: The element to be inserted
 * Returns:
 * None
 * Time complexity: O(n) where n is the number of nodes in the list
 */
void LList::insertend(char ele) { this->insertpos(ele, this->count); }

/* Insert n elements from an array to the end of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [1, 2, 3, 4, 5, 6, 7]
 * Time complexity: O(n*count) where n is the list size and count is array size
 */
void LList::insertend(char *list, int count) {
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
 * Time complexity: O(pos) where pos is the position at which the element is to
 * be inserted
 */
bool LList::insertpos(char ele, int pos) {
  if (pos < 0 || pos > this->count) {
    return false;
  }

  // Handle the case where the element is to be inserted at the beginning
  if (pos == 0) {

    struct LList::Node *newnode = new_node(ele, this->head);

    this->head = newnode;
    return true;

  } else {

    struct LList::Node *tmp = this->head;
    for (int i = 0; i < pos - 1; i++) {
      tmp = tmp->next;
    }

    struct Node *newnode = new_node(ele, tmp->next);
    tmp->next = newnode;

    return true;
  }
}

/* Delete the last node from the List
 * Arguments:
 * None
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 * Time complexity: O(1)
 */
char LList::deletebeg() { return this->deletepos(0); }

/* Delete the first n elements of the list
 * Returns:
 * bool: Success/failure status
 * Time complexity: O(n) where n is the number of elements to delete
 */
bool LList::deletebeg(int count) {
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
 * Time complexity: O(n) where n is the number of nodes in the list
 */
char LList::deleteend() { return this->deletepos(this->count - 1); }

/* Delete the last n elements of the list
 * Returns:
 * bool: Success/failure status
 * Time complexity: O(n^2) where n is the number of elements to delete
 */
bool LList::deleteend(int n) {
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
 * Time complexity: O(pos) where pos is the position of the element to delete
 */
char LList::deletepos(int pos) {
  if (pos < 0 || pos >= this->count) {
    throw "Invalid position";
  }

  struct LList::Node *tmp = this->head;

  // Handle we need to delete first element (head modification)
  if (pos == 0) {
    this->head = tmp->next;
    char ele = tmp->data;
    this->delete_node(tmp);
    return ele;
  }

  for (int i = 0; i < pos - 1; i++) {
    tmp = tmp->next;
  }

  struct LList::Node *to_delete = tmp->next;
  char ele = to_delete->data;

  tmp->next = to_delete->next;

  delete_node(to_delete);

  return ele;
}

/* Reverse the entire list
 * Time complexity: O(n) where n is the number of nodes in the list
 */
void LList::reverse() { this->reverse(0, this->count - 1); }

/* Reverse a portion of the list from start to end
 * Time complexity: O(n) where n is the number of nodes in the list
 */
bool LList::reverse(int start, int end) {

  if (start < 0 || end >= this->count) {
    return false;
  }

  // Coping required elements from linked list to array
  char *tmparr;
  int tmparr_size = this->alloccopy(&tmparr, start, end);

  // Reversing the array
  char tmpele;
  for (int i = 0; i < (tmparr_size / 2); i++) {
    tmpele = tmparr[i];
    tmparr[i] = tmparr[tmparr_size - 1 - i];
    tmparr[tmparr_size - 1 - i] = tmpele;
  }

  // Deleting elements from list
  for (int j = start; j <= end; j++) {
    this->deletepos(start);
  }

  // TODO: Write insertpos(int **ptr, int pos) function

  // Adding the reversed array back to the list
  int arr_pos = 0;
  for (int k = start; k <= end; k++) {
    this->insertpos(tmparr[arr_pos], k);
    arr_pos++;
  }

  return true;
}

/* Search for an element in the list
 * Shortcut to this->linearsearch()
 * Arguments:
 * int ele: element to search for
 * Returns:
 * int: index of the element in the list
 * -1 if not found
 * Time complexity: O(n) where n is the number of nodes in the list
 */
int LList::search(char ele) { return this->linearsearch(ele); }

int LList::linearsearch(char ele) {
  struct LList::Node *tmp = this->head;
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
 * Time complexity: O(pos % n) where pos is the position and n is list size
 */
char LList::get(unsigned int pos) {
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
 * Time complexity: O(pos) where pos is the position to set the element
 */
bool LList::set(int pos, char value) {
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
