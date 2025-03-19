#include "AList.cpp"
#include <iostream>

// Queue class inheriting from AList
// Queue class inheriting from AList
class Queue : public AList {
public:
  Queue() : AList() {}

  // Enqueue operation: add an element to the back of the queue
  // Time Complexity: O(1) - constant time operation
  void enqueue(int element) { insertend(element); }

  // Dequeue operation: remove an element from the front of the queue
  // Time Complexity: O(n) - requires shifting all elements in the array
  int dequeue() {
    if (getsize() == 0) {
      throw "Queue is empty";
    }
    return deletebeg();
  }

  // Peek operation: view the element at the front without removing it
  // Time Complexity: O(1) - constant time operation
  int peek() {
    if (getsize() == 0) {
      throw "Queue is empty";
    }
    return get(0);
  }

  // Check if queue is empty
  // Time Complexity: O(1) - constant time operation
  bool isEmpty() { return getsize() == 0; }
};

int main() {
  Queue queue;
  int choice, element;

  while (true) {
    std::cout << "1. Enqueue (Add element)" << std::endl;
    std::cout << "2. Dequeue (Remove element)" << std::endl;
    std::cout << "3. Peek (View front element)" << std::endl;
    std::cout << "4. Display Queue" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: // Enqueue
      std::cout << "Enter element to add: ";
      std::cin >> element;
      queue.enqueue(element);
      std::cout << element << " added to the queue" << std::endl;
      break;

    case 2: // Dequeue
      try {
        element = queue.dequeue();
        std::cout << element << " removed from the queue" << std::endl;
      } catch (const char *msg) {
        std::cerr << "Error: " << msg << std::endl;
      }
      break;

    case 3: // Peek
      try {
        element = queue.peek();
        std::cout << "Front element: " << element << std::endl;
      } catch (const char *msg) {
        std::cerr << "Error: " << msg << std::endl;
      }
      break;

    case 4: // Display
      if (queue.getsize() == 0) {
        std::cout << "Queue is empty" << std::endl;
      } else {
        std::cout << "Queue elements: ";
        queue.display();
      }
      break;

    case 5: // Exit
      std::cout << "Exiting program..." << std::endl;
      return 0;

    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }

  return 0;
}
