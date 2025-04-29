#include <iostream>
using namespace std;

class stack {
public:
  struct node {
    char data;
    struct node *next;
  } *head;

  stack() { head = NULL; }
  void push(char ch) {
    struct node *newnode = new struct node;
    newnode->data = ch;
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
    } else {
      struct node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
    }
  }

  void pop() {
    if (head == NULL) {
      cout << "List is empty";
    } else {
      struct node *temp = head;
      if (temp->next == NULL) {
        free(head);
        head = NULL;
        return;
      } else {
        while (temp->next->next != NULL) {
          temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return;
      }
    }
  }

  char peek() {
    if (head == NULL) {
      return 0;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    return temp->data;
  }
};
