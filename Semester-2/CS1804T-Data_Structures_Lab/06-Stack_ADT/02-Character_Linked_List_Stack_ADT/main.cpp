#include "LLStack.cpp"
#include <iostream>

using namespace std;

void displayMenu() {
  cout << "Menu:" << endl;
  cout << "1. Push an element" << endl;
  cout << "2. Pop an element" << endl;
  cout << "3. Display top element" << endl;
  cout << "4. Display stack size" << endl;
  cout << "5. Check if stack is empty" << endl;
  cout << "6. Display stack" << endl;
  cout << "7. Exit" << endl;
  cout << "Enter your choice: ";
}

int main() {
  LLStack stack;
  int choice = 0;
  char element;

  while (choice != 7) {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter element to push: ";
      cin >> element;
      stack.push(element);
      break;
    case 2:
      stack.pop();
      break;
    case 3:
      if (!stack.isEmpty()) {
        cout << "Top element: " << (char)stack.top() << endl;
      } else {
        cout << "Stack is empty." << endl;
      }
      break;
    case 4:
      cout << "Stack size: " << stack.size() << endl;
      break;
    case 5:
      if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
      } else {
        cout << "Stack is not empty." << endl;
      }
      break;
    case 6:
      stack.display();
      break;
    case 7:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
