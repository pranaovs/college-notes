// C++ program to demonstrate uses of Classes and Objects with Dynamic Memory
// Various number related operations are performed using the NumberFun class

#include "numbers.h"
#include <iostream>
using namespace std;

NumberFun numberfun;

int main() {

  int *input = new int();
  cout << "Enter a number: ";
  cin >> *input;

  int *choice = new int();

  bool *result = new bool();

  do {

    cout << "\nMenu:\n";
    cout << "1. Check Palindrome\n";
    cout << "2. Check Armstrong\n";
    cout << "3. Check Perfect\n";
    cout << "4. Enter new number\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> *choice;

    switch (*choice) {

    case 1:
      numberfun.isPalindrome(input, result);
      cout << "The number " << *input << " is " << (*result ? "" : "not ")
           << "a palindrome.\n";
      break;

    case 2:
      numberfun.isArmstrong(input, result);
      cout << "The number " << *input << " is " << (*result ? "" : "not ")
           << "an Armstrong number.\n";
      break;
    case 3:
      numberfun.isPerfect(input, result);
      cout << "The number " << *input << " is " << (*result ? "" : "not ")
           << "a perfect number.\n";
      break;

    case 4:
      cout << "Enter a number: ";
      cin >> *input;
      break;

    case 5:
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (*choice != 5);

  delete input;
  delete choice;
  delete result;
  return 0;
}
