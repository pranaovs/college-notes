#include "AStack.h"

void AStack::push(char ele) { AList::insertend(ele); }
void AStack::push(char *list, int count) { AList::insertend(list, count); }
char AStack::pop() { return AList::deleteend(); }
void AStack::pop(int count) { AList::deleteend(count); }
char AStack::top() { return AList::get(AList::getsize() - 1); }
char AStack::peek() { return AStack::top(); }
int AStack::size() { return AList::size; }
bool AStack::isEmpty() { return AList::getsize() == 0; }
void AStack::display() { AList::display(); }
