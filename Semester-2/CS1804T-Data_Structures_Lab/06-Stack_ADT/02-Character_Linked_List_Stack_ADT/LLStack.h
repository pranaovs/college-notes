#include "LList.cpp"

class LLStack : private LList {

public:
  void push(char ele);
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
