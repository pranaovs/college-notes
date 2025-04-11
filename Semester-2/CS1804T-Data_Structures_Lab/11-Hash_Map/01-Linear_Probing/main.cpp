#include <iostream>

// Size of the hash table
#define TABLE_SIZE 10

class Hashtable {
private:
  struct Node {
    int data;
    bool isOccupied;
    bool isDeleted;
  };

  Node table[TABLE_SIZE];

  // Simple hash function that returns key modulo table size
  // Time Complexity: O(1)
  int hash(int key) { return key % TABLE_SIZE; }

public:
  // Constructor initializes all slots as empty
  // Time Complexity: O(TABLE_SIZE)
  Hashtable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      table[i].isOccupied = false;
      table[i].isDeleted = false;
    }
  }

  void insert(int key);
  void remove(int key);
  void search(int key);
  void display();
};

int main() {
  int choice;
  int value;
  Hashtable hashTable;

  while (true) {
    std::cout << "\n<====== MENU ======>" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Search" << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      std::cout << "Enter the value for insertion: ";
      std::cin >> value;
      hashTable.insert(value);
      break;
    case 2:
      std::cout << "Enter the value to delete: ";
      std::cin >> value;
      hashTable.remove(value);
      break;
    case 3:
      std::cout << "Enter the value to search: ";
      std::cin >> value;
      hashTable.search(value);
      break;
    case 4:
      hashTable.display();
      break;
    case 5:
      std::cout << "Exiting..." << std::endl;
      return 0;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }
}

void Hashtable::insert(int key) {
  int index = hash(key);
  int startIndex = index;

  // Direct insertion if the slot is empty or marked as deleted
  // Time Complexity: O(1) in the best case, O(TABLE_SIZE) in the worst case
  // (full table with linear probing)
  if (!table[index].isOccupied || table[index].isDeleted) {
    table[index].data = key;
    table[index].isOccupied = true;
    table[index].isDeleted = false;
    std::cout << "Inserted " << key << " at index " << index << std::endl;
    return;
  }

  // Linear probing to find next available slot
  index = (index + 1) % TABLE_SIZE;
  while (index != startIndex) {
    if (!table[index].isOccupied || table[index].isDeleted) {
      table[index].data = key;
      table[index].isOccupied = true;
      table[index].isDeleted = false;
      std::cout << "Inserted " << key << " at index " << index << std::endl;
      return;
    }
    index = (index + 1) % TABLE_SIZE;
  }

  std::cout << "The table is full" << std::endl;
}

void Hashtable::display() {
  // Time Complexity: O(TABLE_SIZE)
  std::cout << "Hashtable contents:" << std::endl;

  for (int i = 0; i < TABLE_SIZE; i++) {
    std::cout << i << " ---> ";
    if (table[i].isOccupied && !table[i].isDeleted) {
      std::cout << table[i].data;
    }
    std::cout << std::endl;
  }
}

void Hashtable::remove(int key) {
  int index = hash(key);
  int startIndex = index;

  // Check if element is at its hashed position
  // Time Complexity: O(1) in the best case, O(TABLE_SIZE) in the worst case
  // (linear probing)
  if (table[index].isOccupied && table[index].data == key &&
      !table[index].isDeleted) {
    table[index].isDeleted = true;
    std::cout << "Removed " << key << " at index " << index << std::endl;
    return;
  }

  // Linear probing to find the element
  index = (index + 1) % TABLE_SIZE;
  while (index != startIndex) {
    if (table[index].isOccupied && table[index].data == key &&
        !table[index].isDeleted) {
      table[index].isDeleted = true;
      std::cout << "Removed " << key << " at index " << index << std::endl;
      return;
    }

    if (!table[index].isOccupied) {
      break; // Element not found
    }

    index = (index + 1) % TABLE_SIZE;
  }

  std::cout << "Element " << key << " not found in the table" << std::endl;
}

void Hashtable::search(int key) {
  int index = hash(key);
  int startIndex = index;

  // Check if element is at its hashed position
  // Time Complexity: O(1) in the best case, O(TABLE_SIZE) in the worst case
  // (linear probing)
  if (table[index].isOccupied && table[index].data == key &&
      !table[index].isDeleted) {
    std::cout << "Element " << key << " found at index " << index << std::endl;
    return;
  }

  // Linear probing to find the element
  index = (index + 1) % TABLE_SIZE;
  while (index != startIndex && table[index].isOccupied) {
    if (table[index].data == key && !table[index].isDeleted) {
      std::cout << "Element " << key << " found at index " << index
                << std::endl;
      return;
    }
    index = (index + 1) % TABLE_SIZE;
  }

  std::cout << "Element " << key << " not found in the table" << std::endl;
}
