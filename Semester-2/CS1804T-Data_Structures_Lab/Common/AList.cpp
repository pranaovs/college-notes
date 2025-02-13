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
void AList::resize(int value) {
  this->ptr = (int *)realloc(this->ptr, sizeof(int) * (this->count + value));
  this->count = this->count + (value);
  this->size = this->count;
}

/* Constructor to initialize the array */
AList::AList() {
  this->ptr = new int;
  this->count = 0;
  this->size = 0;
}

/* Return the size of the list
 * A shortcut to accessing (int) this->count (which is internal)
 * (int) this->size can also be used
 */
int AList::getsize() { return this->count; }

/* Copies all list elements into int * ptr argument.
 * Make sure to have sufficient array size.
 * Arguments:
 * int * ptr: to copy the list elements into
 * Returns:
 * int: number of elements in the list
 */
int AList::copy(int **ptr) { return this->copy(ptr, this->count); }

/* Copies the list elements into int * ptr argument until count elements
 * Arguments:
 * int * ptr: to copy the list elements into
 * int count: number of elements to copy
 * Returns: int - number of elements in the new list (count)
 */
int AList::copy(int **ptr, int count) {
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
int AList::alloccopy(int **ptr) { return alloccopy(ptr, this->count); }

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
int AList::alloccopy(int **ptr, int count) {
  *ptr = new int[count];
  return copy(ptr, count);
}

/* Print all elements of the list to stdout */
void AList::display() {
  for (int i = 0; i < this->count; i++) {
    std::cout << this->ptr[i] << " ";
  }
  std::cout << std::endl;
}

/* Print n elements of the list to stdout */
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
void AList::insertbeg(int ele) { this->insertpos(ele, 0); }

/* Insert n elements from an array to the beginning of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [5, 6, 7, 1, 2, 3, 4]
 */
void AList::insertbeg(int *list, int count) {
  for (int i = count - 1; i >= 0; i--) {
    this->insertbeg(list[i]);
  }
}

/* Insert an element ele to the end of the list */
void AList::insertend(int ele) { insertpos(ele, this->count); }

/* Insert n elements from an array to the end of the list
 * Does not rotate the list
 * Arguments:
 * int *list: array of elements to insert
 * int count: number of elements in the array
 * Example:
 * If the list is [1, 2, 3, 4] and the array is [5, 6, 7], the list will become
 * [1, 2, 3, 4, 5, 6, 7]
 */
void AList::insertend(int *list, int count) {
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
bool AList::insertpos(int ele, int pos) {
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
bool AList::deletebeg() { return this->deletepos(0); }

/* Delete the first n elements of the list
 * Returns:
 * bool: Success/failure status
 */
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
 * bool: Success/failure status
 */
bool AList::deleteend() { return this->deletepos(this->count); }

/* Delete the last n elements of the list
 * Returns:
 * bool: Success/failure status
 */
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
 * bool: Success/failure status
 */
bool AList::deletepos(int pos) {
  if (count < 1 || pos < 0 || pos > count - 1) {
    return false;
  }
  for (int i = pos; i < this->count; i++) {
    this->ptr[i] = this->ptr[i + 1];
  }
  resize(-1);
  return true;
}

/* Search for an element in the list
 * Shortcut to this->linearsearch()
 * Arguments:
 * int ele: element to search for
 * Returns:
 * int: index of the element in the list
 * -1 if not found
 */
int AList::search(int ele) { return this->linearsearch(ele); }

/* Linear search for an element in the list
 * Arguments:
 * int ele: element to search for
 * Returns:
 * int: index of the element in the list
 * -1 if not found
 */
int AList::linearsearch(int ele) {
  for (int i = 0; i < this->count; i++) {
    if (this->ptr[i] == ele) {
      return i;
    }
  }
  return -1;
}

/* Reverse the list */
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
int AList::get(unsigned int pos) {
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
bool AList::set(int pos, int value) {
  if (pos < 0 || pos >= this->count) {
    return false;
  }
  this->ptr[pos] = value;
  return true;
}
