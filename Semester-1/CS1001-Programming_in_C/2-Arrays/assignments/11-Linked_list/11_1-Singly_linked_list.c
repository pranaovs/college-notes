/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

// Menu driven program to implement a singly linked list

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// Returns a pointer to the head of the linked list
struct Node *create_list() {
  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head = NULL;
  return head;
}

/* Passing a pointer to a function paasses address of the variable, not variable
 * itself To modify head, we pass pointer to head Using head in itself, it only
 * modifies the local copy of head
 */
// Inserts a node at the beginning of the linked list
void insert_beginning(struct Node **head, int data) {
  // Create a new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  // Set the data of the new node
  new_node->data = data;
  // Set the next of new_node to the previous head
  new_node->next = *head;
  // Set the head to point to new_node
  *head = new_node;
}

// Inserts a node at the end of the linked list
void insert_end(struct Node **head, int data) {
  // Create a new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (*head == NULL) {
    // If the list is empty, set the head to the new node
    *head = new_node;
  } else {

    // Traverse to the end of the linked list
    while ((*head)->next != NULL) {
      *head = (*head)->next;
    }
  }

  // Set the next of the last node to the new node
  (*head)->next = new_node;
  // Set the data of the new node
  new_node->data = data;
  // Set the next of the new node to NULL
  new_node->next = NULL;
}

void insert_pos(struct Node **head, int data, int pos) {
  // Create a new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  // Traverse to the position before the position to insert the new node

  for (int i = 0; i < pos - 2; i++) {
    *head = (*head)->next;
    if (*head == NULL) {
      printf("Invalid position\n");
      return;
    }
  }

  // Set data of the new node
  new_node->data = data;
  // Set the next of the new node to the next of the current node
  new_node->next = (*head)->next;
  // Set the next of the current node to the new node
  (*head)->next = new_node;
}

void delete_beginning(struct Node *head) {
  struct Node *temp = head->next;

  // Set the head to the next of the current head
  head = head->next;

  // Free the memory of the previous head
  free(temp);
}

// BUG: Causes segfault
void delete_end(struct Node *head) {
  while (head->next->next != NULL) {
    head = head->next;
  }

  struct Node *temp = head;

  // Set the next of the second last node to NULL
  head->next = NULL;

  // Free the memory of the last node
  free(temp);
}

void delete_pos(struct Node *head, int pos) {
  // Traverse to the position before the position to insert the new node

  for (int i = 0; i < pos - 1; i++) {
    if (head->next->next == NULL) {
      printf("Invalid position\n");
      return;
    } else {
      head = head->next;
    }
  }

  struct Node *temp = head->next;

  // Set the next of the current node to the next of the next node
  head->next = head->next->next;

  // Free the memory of the node to be deleted
  free(temp);
}

void display(struct Node *head) {

  // If head points to null, it means list is empty
  if (head == NULL) {
    printf("Empty list");
  } else {

    while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
    }
  }
  printf("\n");
}

int main() {

  bool created = false;
  struct Node *head = create_list();

  int choice = 1;

  while (choice != 0) {

    printf("1. Insert a node at the beginning\n"
           "2. Insert a node at the end\n"
           "3. Insert a node at a position\n"
           "4. Delete the first node\n"
           "5. Delete the last node\n"
           "6. Delete a node at a position\n"
           "0. Exit\n");

    int data;
    int pos;

    display(head);

    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the data: ");
      scanf("%d", &data);
      insert_beginning(&head, data);
      break;

    case 2:
      printf("Enter the data: ");
      scanf("%d", &data);
      insert_end(&head, data);
      break;

    case 3:
      printf("Enter the position: ");
      scanf("%d", &pos);
      printf("Enter the data: ");
      scanf("%d", &data);
      insert_pos(head, data, pos);
      break;

    case 4:
      delete_beginning(head);
      break;

    case 5:
      delete_end(head);
      break;

    case 6:
      printf("Enter the position: ");
      scanf("%d", &pos);
      delete_pos(head, pos);
      break;

    case 0:
      printf("Exiting...\n");
      return 0;
      break;

    default:
      printf("Invalid choice\n");
      break;
    }
  }
}
