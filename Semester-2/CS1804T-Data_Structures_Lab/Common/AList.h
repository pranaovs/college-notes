/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation using arrays in C++ */

class AList {
private:
  int count;
  int *ptr;
  void resize(int value);

public:
  int size;

  AList();
  int getsize();
  int copy(int **ptr);
  int copy(int **ptr, int count);
  int alloccopy(int **ptr);
  int alloccopy(int **ptr, int count);
  void display();
  void display(int n);
  void insertbeg(int ele);
  void insertbeg(int *list, int count);
  void insertend(int ele);
  void insertend(int *list, int count);
  bool insertpos(int ele, int pos);
  int deletebeg();
  bool deletebeg(int count);
  int deleteend();
  bool deleteend(int count);
  int deletepos(int pos);
  void reverse();
  bool reverse(int start, int end);
  int search(int ele);
  int linearsearch(int ele);
  int get(unsigned int pos);
  bool set(int pos, int value);
};
