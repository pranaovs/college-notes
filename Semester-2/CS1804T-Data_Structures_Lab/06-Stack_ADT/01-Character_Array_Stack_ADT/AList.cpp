/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation using arrays in C++ */

#include "AList.h"
#include <cstdlib>
#include <iostream>

/* Resize the list by a given value */
/* Time Complexity: O(n) */
void AList::resize(int value) {
  this->ptr = (char *)realloc(this->ptr, sizeof(char) * (this->count + value));
  this->count = this->count + (value);
  this->size = this->count;
}

/* Constructor to initialize the array */
/* Time Complexity: O(1) */
AList::AList() {
  this->ptr = new char;
  this->count = 0;
  this->size = 0;
}

/* Destructor to free the allocated memory */
/* Time Complexity: O(1) */
AList::~AList() { delete[] this->ptr; }

/* Return the size of the list
 * A shortcut to accessing (int) this->count (which is internal)
 * (int) this->size can also be used
 */
/* Time Complexity: O(1) */
int AList::getsize() { return this->count; }

/* Copies all list elements into int * ptr argument.
 * Make sure to have sufficient array size.
 * Arguments:
 * int * ptr: to copy the list elements into
 * Returns:
 * int: number of elements in the list
 */
/* Time Complexity: O(n) */
int AList::copy(char **ptr) { return this->copy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns: int - number of elements in the new list (count)
 */
/* Time Complexity: O(n) */
int AList::copy(char **ptr, int count) {
  for (int i = 0; i < count; i++) {
    (*ptr)[i] = this->ptr[i];
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
/* Time Complexity: O(n) */
int AList::alloccopy(char **ptr) { return alloccopy(ptr, this->count); }

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
/* Time Complexity: O(n) */
int AList::alloccopy(char **ptr, int count) {
  *ptr = new char[count];
  return copy(ptr, count);
}

/* Print all elements of the list to stdout */
/* Time Complexity: O(n) */
void AList::display() {
  for (int i = 0; i < this->count; i++) {
    std::cout << this->ptr[i] << " ";
  }
  std::cout << std::endl;
}

/* Print n elements of the list to stdout */
/* Time Complexity: O(n) */
void AList::display(int n) {
  if (n < 0 || n > count) {
    return;
  }
  for (int i = 0; i < n; i++) {
    std::cout << this->ptr[i] << " ";
  }
  std::cout << std::endl;
}

/* Insert an element ele to the beginning of the list */
/* Time Complexity: O(n) */
void AList::insertbeg(char ele) { this->insertpos(ele, 0); }

/* Insert n elements from an array to the beginning of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [5, 6, 7, 1, 2, 3, 4]
 */
/* Time Complexity: O(n^2) */
void AList::insertbeg(char *list, int count) {
  for (int i = count - 1; i >= 0; i--) {
    this->insertbeg(list[i]);
  }
}

/* Insert an element ele to the end of the list */
/* Time Complexity: O(1) amortized */
void AList::insertend(char ele) { insertpos(ele, this->count); }

/* Insert n elements from an array to the end of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [1, 2, 3, 4, 5, 6, 7]
 */
/* Time Complexity: O(n) */
void AList::insertend(char *list, int count) {
  for (int i = 0; i < count; i++) {
    this->insertend(list[i]);
  }
}

/* Insert an element ele to a position pos
 * Arguments:
 * int ele: element to be inserted
 * int pos: list index to insert to
 * Returns: bool - success/failure status
 */
/* Time Complexity: O(n) */
bool AList::insertpos(char ele, int pos) {
  if (pos < 0 || pos > count) {
    return false;
  }
  resize(+1);
  for (int i = this->count - 1; i > pos; i--) {
    this->ptr[i] = this->ptr[i - 1];
  }
  this->ptr[pos] = ele;
  return true;
}

/* Delete the first element of the list */
/* Time Complexity: O(n) */
char AList::deletebeg() { return this->deletepos(0); }

/* Delete the first n elements of the list
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
/* Time Complexity: O(n^2) */
bool AList::deletebeg(int count) {
  if (count < 1 || count > this->count) {
    return false;
  }
  for (int i = 0; i < count; i++) {
    this->deletebeg();
  }
  return true;
}

/* Delete the last element of the list
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
/* Time Complexity: O(1) */
char AList::deleteend() { return this->deletepos(this->count - 1); }

/* Delete the last n elements of the list
 * Returns:
 * bool: Success/failure status
 */
/* Time Complexity: O(n) */
bool AList::deleteend(int n) {
  if (n < 1 || n > this->count) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    this->deleteend();
  }
  return true;
}

/* Delete an element from a given position pos
 * Arguments:
 * int pos: List position to delete
 * Returns:
 * int: the element deleted
 * throws:
 * "invalid position" if the position is invalid
 */
/* Time Complexity: O(n) */
char AList::deletepos(int pos) {
  if (pos < 0 || pos > count - 1) {
    throw "Invalid position";
  }
  char ele = this->ptr[pos];
  for (int i = pos; i < this->count; i++) {
    this->ptr[i] = this->ptr[i + 1];
  }
  resize(-1);
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
/* Time Complexity: O(n) */
int AList::search(int ele) { return this->linearsearch(ele); }

/* Linear search for an element in the list
 * Arguments:
 * int ele: element to search for
 * Returns:
 * int: index of the element in the list
 * -1 if not found
 */
/* Time Complexity: O(n) */
int AList::linearsearch(int ele) {
  for (int i = 0; i < this->count; i++) {
    if (this->ptr[i] == ele) {
      return i;
    }
  }
  return -1;
}

/* Reverse the list */
/* Time Complexity: O(n) */
void AList::reverse() {
  int start = 0;
  int end = this->size - 1;

  this->reverse(start, end);
}

/* Reverse the list from start to end index
 * Arguments:
 * int start: start index
 * int end: end index
 * Returns:
 * bool: Success/failure status
 */
/* Time Complexity: O(n) */
bool AList::reverse(int start, int end) {

  if (start < 0 || end >= this->count) {
    return false;
  }

  while (start < end) {
    int temp = this->ptr[start];
    this->ptr[start] = this->ptr[end];
    this->ptr[end] = temp;
    start++;
    end--;
  }

  return true;
}

/* Get the element at a given position
 * Arguments:
 * int pos: position to get the element from
 * Returns:
 * int: element at the position
 * NOTE: Uses unsigned int to handle negative positions
 * NOTE: The list is treated as a circular list
 */
/* Time Complexity: O(1) */
char AList::get(unsigned int pos) {
  if (pos < 0) {
    throw "Invalid position";
  }

  pos = pos % this->count;
  return this->ptr[pos];
}

/* Set the value of given position
 * Arguments:
 * int pos: position to set the element
 * int value: value to set
 * Returns:
 * bool: Success/failure status
 */
/* Time Complexity: O(1) */
bool AList::set(int pos, char value) {
  if (pos < 0 || pos >= this->count) {
    return false;
  }
  this->ptr[pos] = value;
  return true;
}
