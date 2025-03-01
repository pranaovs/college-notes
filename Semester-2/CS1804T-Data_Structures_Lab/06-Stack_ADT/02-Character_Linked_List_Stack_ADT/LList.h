/*
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
*/

/* Character version of the linked list implementation */

class LList {

private:
  int count;

protected:
  struct Node {
    char data;
    struct LList::Node *next;
  };

  struct LList::Node *head;

  struct LList::Node *new_node(char ele, struct LList::Node *next);
  void delete_node(struct LList::Node *node);

public:
  int size;

  LList();
  ~LList();
  int getsize();
  int copy(char **ptr);
  int copy(char **ptr, int count);
  int copy(char **ptr, int start, int end);
  int alloccopy(char **ptr);
  int alloccopy(char **ptr, int count);
  int alloccopy(char **ptr, int start, int end);
  void display();
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
  int search(char ele);
  int linearsearch(char ele);
  char get(unsigned int pos);
  bool set(int pos, char value);
};
