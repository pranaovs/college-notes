/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation in C++ */

#include <cstdlib>
#include <iostream>
#include <stdbool.h>

class AList {
protected:
  int *ptr;
  int count;

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
  void insertend(int ele);
  bool insertpos(int ele, int pos);
  bool deletebeg();
  int deleteend();
  bool deletepos(int pos);
  int search(int ele);
  int linearsearch(int ele);
};
