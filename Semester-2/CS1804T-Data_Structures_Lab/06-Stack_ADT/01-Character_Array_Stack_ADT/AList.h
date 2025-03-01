/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation using arrays in C++ */

class AList {
private:
  int count;
  char *ptr;
  void resize(int value);

public:
  int size;

  AList();
  ~AList();
  int getsize();
  int copy(char **ptr);
  int copy(char **ptr, int count);
  int alloccopy(char **ptr);
  int alloccopy(char **ptr, int count);
  void display();
  void display(int n);
  void insertbeg(char ele);
  void insertbeg(char *list, int count);
  void insertend(char ele);
  void insertend(char *list, int count);
  bool insertpos(char ele, int pos);
  char deletebeg();
  bool deletebeg(int count);
  char deleteend();
  bool deleteend(int count);
  char deletepos(int pos);
  void reverse();
  bool reverse(int start, int end);
  int search(int ele);
  int linearsearch(int ele);
  char get(unsigned int pos);
  bool set(int pos, char value);
};
