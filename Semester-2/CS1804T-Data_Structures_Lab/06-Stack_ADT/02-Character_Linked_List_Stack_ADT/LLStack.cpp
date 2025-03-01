#include "LLStack.h"

// Time complexity: O(1)
void LLStack::push(char ele) { LList::insertend(ele); }

// Time complexity: O(n) where n is the number of elements in the list
char LLStack::pop() { return LList::deleteend(); }

// Time complexity: O(n * count) where n is the number of elements in the list
// and count is the number of elements to pop
void LLStack::pop(int count) { LList::deleteend(count); }

// Time complexity: O(n) where n is the number of elements in the list
char LLStack::top() { return LList::get(LList::getsize() - 1); }

// Time complexity: O(n) where n is the number of elements in the list
char LLStack::peek() { return LLStack::top(); }

// Time complexity: O(1)
int LLStack::size() { return LList::size; }

// Time complexity: O(1)
bool LLStack::isEmpty() { return LList::getsize() == 0; }

// Time complexity: O(n) where n is the number of elements in the list
void LLStack::display() { LList::display(); }
