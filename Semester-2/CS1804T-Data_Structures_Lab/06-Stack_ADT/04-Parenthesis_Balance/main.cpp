#include "AStack.cpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * Function to check if a string of parentheses is balanced
 * A string is balanced if every opening parenthesis has a
 * matching closing parenthesis in the correct order
 *
 * @param parentheses the string to check
 * @return true if balanced, false otherwise
 */
bool isBalanced(const string &parentheses) {
  AStack stack;

  for (char c : parentheses) {
    if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      if (stack.isEmpty()) {
        return false; // Unmatched closing parenthesis
      }
      stack.pop();
    }
  }

  return stack.isEmpty(); // If stack is empty, all parentheses are matched
}

/**
 * Function to validate that the input string contains only valid parentheses
 *
 * @param s the input string
 * @return true if valid, false otherwise
 */
bool isValidInput(const string &s) {
  for (char c : s) {
    if (c != '(' && c != ')') {
      return false;
    }
  }
  return true;
}

int main() {
  int choice;
  string parentheses;

  do {
    cout << "\n=== Parenthesis Balancer ===\n";
    cout << "1. Enter a parenthesis string\n";
    cout << "2. Check if the entered string is balanced\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter a string of '(' and ')' parentheses: ";
      cin >> parentheses;

      if (!isValidInput(parentheses)) {
        cout << "Invalid input! Please enter only '(' and ')' characters.\n";
        parentheses = ""; // Reset the string
      }
      break;

    case 2:
      if (parentheses.empty()) {
        cout << "Please enter a parenthesis string first.\n";
      } else {
        if (isBalanced(parentheses)) {
          cout << "The parentheses in \"" << parentheses
               << "\" are balanced.\n";
        } else {
          cout << "The parentheses in \"" << parentheses
               << "\" are NOT balanced.\n";
        }
      }
      break;

    case 3:
      cout << "Exiting the program.\n";
      break;

    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 3);

  return 0;
}
