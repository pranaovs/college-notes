#include "AStack.h"

/* Time Complexity: O(1) amortized */
void AStack::push(char ele) { AList::insertend(ele); }

/* Time Complexity: O(1) */
char AStack::pop() { return AList::deleteend(); }

/* Time Complexity: O(n) */
void AStack::pop(int count) { AList::deleteend(count); }

/* Time Complexity: O(1) */
char AStack::top() { return AList::get(AList::getsize() - 1); }

/* Time Complexity: O(1) */
char AStack::peek() { return AStack::top(); }

/* Time Complexity: O(1) */
int AStack::size() { return AList::size; }

/* Time Complexity: O(1) */
bool AStack::isEmpty() { return AList::getsize() == 0; }

/* Time Complexity: O(n) */
void AStack::display() { AList::display(); }
