/*
This code is licensed under the MIT License
Copyright 2024 Pranaov S
https://opensource.org/license/MIT
*/

// This code was forked from:
// https://github.com/pranaovs/college-notes/tree/main/Semester-1/CS1001-Programming_in_C/2-Arrays/assignments/9-Structures/9_3-Employee_details/9_3-Employee_details.c

// C program to collect details of employees display the details and save it in
// a file

#include <stdio.h>

// Define a new struct called Employee
struct Employee {
  char name[100];
  int empid;
  int age;
  char sex[10];
  char position[100];
  int salary;
};

// Function to return an object of employee struct after taking inputs
struct Employee get_details() {
  // Create a local instance/object of the struct Employee
  struct Employee new_employee;
  printf("Enter employee name: ");
  scanf("%s", new_employee.name);
  printf("Enter employee %s's employee id: ", new_employee.name);
  scanf("%d", &new_employee.empid);
  printf("Enter employee %s's age: ", new_employee.name);
  scanf("%d", &new_employee.age);
  printf("Enter employee %s's sex: ", new_employee.name);
  scanf("%s", new_employee.sex);
  printf("Enter employee %s's position: ", new_employee.name);
  scanf("%s", new_employee.position);
  printf("Enter employee %s's salary: ", new_employee.name);
  scanf("%d", &new_employee.salary);

  // Return the populated Employee struct
  return new_employee;
}

/* Function to print details of the all the members
of an array of struct Employee
Expects an array of struct Employee and
count (number of elements in the array of struct Employee) */
// TODO: calculate count inside function
void print_details(struct Employee employee_list[], int count) {
  for (int i = 0; i < count; i++) {
    // Create an local instance of the struct Student
    // with each element of the array
    struct Employee emp = employee_list[i];
    printf("Employee name: %s\n", emp.name);
    printf("Employee %s's employee id: %d\n", emp.name, emp.empid);
    printf("Employee %s's age: %d\n", emp.name, emp.age);
    printf("Employee %s's sex: %s\n", emp.name, emp.sex);
    printf("Employee %s's position: %s\n", emp.name, emp.position);
    printf("Employee %s's salary: %d\n", emp.name, emp.salary);
    printf("\n");
  }
}

// Function to print the details of all the employees to a file
void dump_details(FILE *f, struct Employee employee_list[], int count) {

  for (int i = 0; i < count; i++) {
    // Create an local instance of the struct Student
    // with each element of the array
    struct Employee emp = employee_list[i];
    fprintf(f, "Employee name: %s\n", emp.name);
    fprintf(f, "Employee %s's employee id: %d\n", emp.name, emp.empid);
    fprintf(f, "Employee %s's age: %d\n", emp.name, emp.age);
    fprintf(f, "Employee %s's sex: %s\n", emp.name, emp.sex);
    fprintf(f, "Employee %s's position: %s\n", emp.name, emp.position);
    fprintf(f, "Employee %s's salary: %d\n", emp.name, emp.salary);
    fprintf(f, "\n");
  }
}

int main() {

  printf("Enter number of employees: ");
  int empcount;
  scanf("%d", &empcount);
  struct Employee employee_list[empcount];

  printf("Enter the details\n");
  // Loop through empcount times to get the employee details, and add it in
  // an array of struct Employee
  for (int i = 0; i < empcount; i++) {
    printf("Enter the details of employee %d\n", i + 1);
    employee_list[i] = get_details();
  }

  printf("\n========== Recalling Details ==========\n");
  print_details(employee_list, sizeof(employee_list) / sizeof(*employee_list));

  char filename[100];
  printf("Enter filename to save the employee details to: ");
  scanf("%s", filename);

  FILE *f = fopen(filename, "w+");

  dump_details(f, employee_list,
               sizeof(employee_list) / sizeof(*employee_list));

  fclose(f);

  return 0;
}
