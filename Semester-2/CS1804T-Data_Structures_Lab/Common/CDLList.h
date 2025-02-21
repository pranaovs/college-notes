/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* This is a simple list ADT implementation using doubly linked list in C++ */

class CDLList {
private:
  int count;

  struct Node {
    int data;
    struct CDLList::Node *prev;
    struct CDLList::Node *next;
  };

  struct CDLList::Node *head;

  struct CDLList::Node *new_node(int ele, struct CDLList::Node *next,
                                 struct CDLList::Node *prev);
  void delete_node(struct CDLList::Node *node);

public:
  int size;

  CDLList();
  int getsize();
  int copy(int **ptr);
  int copy(int **ptr, int count);
  int alloccopy(int **ptr);
  int alloccopy(int **ptr, int count);
  void display();
  void double_display();
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
  // void reverse();
  // bool reverse(int start, int end);
  int search(int ele);
  int linearsearch(int ele);
  int get(unsigned int pos);
  bool set(int pos, int value);
};
