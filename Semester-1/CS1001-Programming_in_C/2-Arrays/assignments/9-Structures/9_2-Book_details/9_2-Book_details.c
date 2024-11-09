/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

/* C program to save book details, display and handle book billing
using a menu-driven interface */

#include <stdbool.h>
#include <stdio.h>

// Define a new struct called Book
struct Book {
  char name[100];
  char author[100];
  int cost;
};

// Function to return an object of struct Book after taking inputs
struct Book get_details() {
  // Create a local instance/object of the struct Book
  struct Book new_book;
  // BUG: Doesn't accept spaces
  printf("Enter book name (avoid spaces): ");
  scanf("%s", new_book.name);
  // BUG: Doesn't accept spaces
  printf("Enter book: %s's author (avoid spaces): ", new_book.name);
  scanf("%s", new_book.author);
  printf("Enter book %s's cost: ", new_book.name);
  scanf("%d", &new_book.cost);

  // Return the populated Book struct
  return new_book;
}

/* Function to print details of an object of struct Book
Expects a struct Book*/
void print_book(struct Book stu) {
  printf("Book name: %s\n", stu.name);
  printf("Book %s's author: %s\n", stu.name, stu.author);
  printf("Book %s's cost: %d\n", stu.name, stu.cost);
  printf("\n");
}

/* Function to print details of the all the elements
of an array of struct Book
Expects an array of struct Book */
void print_all_books(struct Book book_array[], int count) {
  for (int i = 0; i < count; i++) {
    // Create an local instance of the struct Book
    // with each element of the array
    struct Book stu = book_array[i];
    print_book(stu); // use the print_book function to print details of the book
  }
}

int main() {

  int choice;
  bool details_exist = false; // Initially book_array array is not populated

  printf("Enter the maximum number of books: ");
  int max_books;
  scanf("%d", &max_books);
  struct Book book_array[max_books];

  // Variable to keep track of the number of books
  int book_count = 0;

  while (choice != 5) {

    printf("Enter the action to perform:\n"
           "1. Add a new book\n"
           "2. Delete an existing book\n"
           "3. View book details\n"
           "4. Checkout books\n"
           "5. Quit\n"
           "\n"
           "Choice: ");

    scanf("%d", &choice);
    printf("\n");

    // Menu-driven entry
    switch (choice) {
    case 1:
      // Case: Input book details

      // Don't allow to add more books than the maximum size of the array
      if (book_count >= max_books) {
        printf("Maximum books reached\n");
      } else {
        printf("Enter book details\n");
        book_array[book_count] = get_details();
        details_exist = true; // Set details_exist to true to allow editing
        book_count++;
      }

      break;

    case 2:
      // Case: Delete book

      if (details_exist) {

        printf("Enter the book's index number to delete:\n");
        for (int i = 0; i < book_count; i++) {
          printf("%d: %s\n", (i + 1), book_array[i].name);
        }
        printf("%d: Back to main menu\n", book_count + 1);

        printf("\nChoice: ");
        int delete_choice;
        scanf("%d", &delete_choice);
        printf("\n");

        if (delete_choice == book_count + 1) {
          printf("Exiting to main menu\n");
        } else if (delete_choice <= book_count && delete_choice > 0) {
          // Shift all elements to the left after the deleted element
          for (int i = delete_choice - 1; i < book_count - 1; i++) {
            book_array[i] = book_array[i + 1];
          }
          book_count--; // Decrement book_count
        } else {
          printf("Invalid choice\n");
        }
      } else {
        printf("Book's details do not exist. Use option 1 to populate\n");
      }

      break;

    case 3:
      // Case: View book details

      if (details_exist) {
        printf("Enter the book's index number to edit details:\n");

        // Print book's names along with an index
        for (int i = 0; i < book_count; i++) {
          printf("%d: %s\n", (i + 1), book_array[i].name);
        }
        printf("%d: All details\n", book_count + 1);
        printf("%d: Back to main menu\n", book_count + 2);

        printf("\nChoice: ");
        int view_choice;
        scanf("%d", &view_choice);
        printf("\n");

        // Print all books
        if (view_choice == book_count + 1) {
          print_all_books(book_array, book_count);
        }
        // Return to main menu
        else if (view_choice == book_count + 2) {
        }
        // If given choice lies withing book_count range, view the book
        // details
        else if (view_choice <= book_count && view_choice > 0) {
          print_book(book_array[view_choice - 1]);
        } else {
          printf("Invalid choice\n");
        }

      } else {
        printf("Book's details do not exist. Use option 1 to populate\n");
      }
      break;

    case 4:
      // Case: Checkout books
      if (details_exist) {
        int checkout_choice = 0;

        // Create a new array of struct Book to store the cart
        // TODO: Make it dynamic. Current implementation uses max_books
        struct Book cart[max_books];
        int cart_count = 0;

        // Print book's names along with an index
        for (int i = 0; i < book_count; i++) {
          printf("%d: %s\n", (i + 1), book_array[i].name);
        }
        printf("%d: View cart\n", book_count + 1);
        printf("%d: Checkout\n", book_count + 2);
        printf("%d: View all books\n", book_count + 3);

        printf("%d: Back to main menu\n", book_count + 4);

        // Loop until the user chooses to exit
        while (checkout_choice != book_count + 2) {

          printf("Enter the book's index number to add to cart:\n");
          printf("\nChoice: ");
          scanf("%d", &checkout_choice);
          printf("\n");

          // Case -4: Exit to main menu
          if (checkout_choice == book_count + 4) {
            printf("Exiting checkout\n");
          } // Case -3: Reprint menu
          else if (checkout_choice == book_count + 3) {

            // Print book's names along with an index
            for (int i = 0; i < book_count; i++) {
              printf("%d: %s\n", (i + 1), book_array[i].name);
            }
            printf("%d: View cart\n", book_count + 1);
            printf("%d: Checkout\n", book_count + 2);
            printf("%d: View all books\n", book_count + 3);

            printf("%d: Back to main menu\n", book_count + 4);
          }

          // Case 1 to 0: Add book to cart
          else if (checkout_choice <= book_count && checkout_choice > 0) {
            printf("Book %s added to cart\n",
                   book_array[checkout_choice - 1].name);
            cart[cart_count] = book_array[checkout_choice - 1];
            cart_count++;
          } // Case -1: Print all books in the cart
          else if (checkout_choice == book_count + 1) {
            int total_cost;
            for (int i = 0; i < cart_count; i++) {
              printf("Book %d: %s\n", (i + 1), cart[i].name);
              total_cost = total_cost + cart[i].cost;
            }
            printf("\nTotal cost: %d\n", total_cost);

          } // Case -2: Checkout
          else if (checkout_choice == book_count + 2) {
            int total_cost;
            for (int i = 0; i < cart_count; i++) {
              printf("Book %d: %s\n", (i + 1), cart[i].name);
              total_cost = total_cost + cart[i].cost;
            }
            printf("\nTotal cost: %d\n", total_cost);
            printf("Books checked out\n");
            cart_count = 0;

            // Return to main menu
            break;

          } else {
            printf("Invalid choice\n");
          }
        }
      } else {
        printf("Book's details do not exist. Use option 1 to populate\n");
      }
      break;

    case 5:
      // Just output. Initial while loop will not re-iterate
      printf("Exiting program\n");
      break;

    default:
      printf("Invalid choice\n\n");
    }
  }

  return 0;
}
