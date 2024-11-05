/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

/* C program to collect details of students and save it in an array, and display
using a menu-driven interface */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Number of student's details to collect
#define STUDENT_COUNT 3

// Define a new struct called Student
struct Student {
  char name[100];
  int rollno;
  int marks;
};

// Unused code
void strip0(char *ptr) {
  // Remove the newline character from the input string if present

  int len = strlen(ptr);
  if (ptr[len - 1] == '\n') {
    ptr[len - 1] = '\0';
    len--;
  }
}

// Function to return an object of student struct after taking inputs
struct Student get_details() {
  // Create a local instance/object of the struct Student
  struct Student new_student;
  printf("Enter student name: ");
  // TODO: Clear old buffer before accepting new value using fgets
  // fgets(new_student.name, sizeof(new_student.name), stdin);
  // strip0(new_student.name);
  // TODO: Accept spaces in student name. Currently, spaces break code
  scanf("%s", new_student.name);
  printf("Enter student %s's roll number: ", new_student.name);
  scanf("%d", &new_student.rollno);
  printf("Enter student %s's marks: ", new_student.name);
  scanf("%d", &new_student.marks);

  // Return the populated Student struct
  return new_student;
}

/* Function to print details of an object os struct Student
Expects a struct Student*/
void print_student(struct Student stu) {
  printf("Student name: %s\n", stu.name);
  printf("Student %s's roll number: %d\n", stu.name, stu.rollno);
  printf("Student %s's marks: %d\n", stu.name, stu.marks);
  printf("\n");
}

/* Function to print details of the all the elements
of an array of struct Student
Expects an array of struct Student */
void print_all_students(struct Student student_list[]) {
  for (int i = 0; i < STUDENT_COUNT; i++) {
    // Create an local instance of the struct Student
    // with each element of the array
    struct Student stu = student_list[i];
    print_student(stu);
  }
}

int main() {

  struct Student student_list[STUDENT_COUNT];
  int choice;
  bool details_exist = false; // Initially student_list array is not populated

  while (choice != 4) {

    printf("Enter the action to perform:\n"
           "1. Enter student details (overwrites all existing details)\n"
           "2. Edit student details\n"
           "3. View student details\n"
           "4. Quit\n"
           "\n"
           "Choice: ");

    scanf("%d", &choice);
    printf("\n");

    // Menu-driven entry
    switch (choice) {
    case 1:
      // Case: Input student details

      printf("Enter the details\n");
      // Loop through STUDENT_COUNT times to get the student details, and add it
      // in an array of struct Student
      for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the details of student %d\n", i + 1);
        student_list[i] =
            get_details(); // get_details() function returns struct Student
        printf("\n");
      }
      details_exist = true; // Set details_exist to true to allow editing
      break;

    case 2:
      // Case: Edit student details

      if (details_exist) {
        printf("Enter the student's index number to edit details:\n");

        // Print students names along with an index
        for (int i = 0; i < STUDENT_COUNT; i++) {
          // Create an instance of the struct Student
          // with each element of the array
          struct Student stu = student_list[i];
          printf("%d: %s\n", (i + 1), stu.name);
        }

        printf("\nChoice: ");
        int edit_choice;
        scanf("%d", &edit_choice);
        printf("\n");

        // If given choice lies withing STUDENT_COUNT range, edit the student
        // entry
        if (edit_choice <= STUDENT_COUNT && edit_choice > 0) {
          student_list[edit_choice - 1] = get_details();
        } else {
          printf("Invalid choice\n");
        }

      } else {
        printf("Student's details do not exist. Use option 1 to populate\n");
      }
      break;

    case 3:
      // Case: View student details
      if (details_exist) {
        printf("Enter index of student to view details\n");

        // Print students names along with an index
        for (int i = 0; i < STUDENT_COUNT; i++) {
          // Create an local instance of the struct Student
          // with each element of the array
          struct Student stu = student_list[i];
          printf("%d: %s\n", (i + 1), stu.name);
        }
        printf("%d: All details\n", STUDENT_COUNT + 1);

        printf("\nChoice: ");
        int view_choice;
        scanf("%d", &view_choice);
        printf("\n");

        // If given choice lies withing STUDENT_COUNT range, view the student
        // entry
        if (view_choice <= STUDENT_COUNT && view_choice > 0) {
          print_student(student_list[view_choice - 1]);
          // If given choise is 1 more than STUDENT_COUNT, show all students
          // details
        } else if (view_choice == (STUDENT_COUNT + 1)) {
          print_all_students(student_list);
        } else {
          printf("Invalid choice\n");
        }

      } else {
        printf("Student's details do not exist. Use option 1 to populate\n\n");
      }
      break;

    case 4:
      // Just output. Initial while loop will not re-iterate
      printf("Exiting program\n");
      break;

    default:
      printf("Invalid choice\n\n");
    }
  }

  return 0;
}
