/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation using doubly linked list in C++ */

class LList {
private:
  int count;

  struct Node {
    int data;
    struct LList::Node *next;
  };

  struct LList::Node *head;

  struct LList::Node *new_node(int ele, struct LList::Node *next);
  void delete_node(struct LList::Node *node);

public:
  int size;

  LList();
  int getsize();
  int copy(int **ptr);
  int copy(int **ptr, int count);
  int copy(int **ptr, int start, int end);
  int alloccopy(int **ptr);
  int alloccopy(int **ptr, int count);
  int alloccopy(int **ptr, int start, int end);
  void display();
  void double_display();
  void insertbeg(int ele);
  void insertbeg(int *list, int count);
  void insertend(int ele);
  void insertend(int *list, int count);
  bool insertpos(int ele, int pos);
  bool deletebeg();
  bool deletebeg(int count);
  bool deleteend();
  bool deleteend(int count);
  bool deletepos(int pos);
  void reverse();
  bool reverse(int start, int end);
  int search(int ele);
  int linearsearch(int ele);
  int get(unsigned int pos);
  bool set(int pos, int value);
};
