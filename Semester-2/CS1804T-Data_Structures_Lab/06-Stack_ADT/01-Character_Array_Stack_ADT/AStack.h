#include "AList.cpp"

class AStack : private AList {

public:
  void push(char ele);
  void push(char *list, int count);
  char pop();
  void pop(int count);
  char top();
  char peek();
  int size();
  bool isEmpty();

  int copy(char **ptr);
  int copy(char **ptr, int count);
  int alloccopy(char **ptr);
  int alloccopy(char **ptr, int count);
  void display();
  void display(int n);
};
