#include <iostream>

// Size of the hash table
#define SIZE 10

/**
 * A hash table implementation using quadratic probing for collision resolution
 */
class HashTable {
private:
  // Node structure to store data in the hash table
  struct Node {
    int data;
    bool isOccupied;
    bool isDeleted;
  };

  Node table[SIZE];

  // Simple hash function that returns the remainder of division by SIZE
  int hash(int key) { return key % SIZE; }

public:
  // Constructor initializes all table entries as empty
  HashTable() {
    for (int i = 0; i < SIZE; i++) {
      table[i].isOccupied = false;
      table[i].isDeleted = false;
    }
  }

  void insert(int key);
  void remove(int key);
  void display();
  void search(int key);
};

int main() {
  int choice;
  int value;
  HashTable hashTable;

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

void HashTable::insert(int key) {
  int index = hash(key);
  int startIndex = index;
  int i = 1;

  // Check if the initial position is available
  if (!table[index].isOccupied || table[index].isDeleted) {
    table[index].data = key;
    table[index].isOccupied = true;
    table[index].isDeleted = false;
    std::cout << "Inserted " << key << " at index " << index << std::endl;
    return;
  }

  // Quadratic probing to find the next available slot
  do {
    // Quadratic probing formula: (hash(key) + i^2) % SIZE
    index = (startIndex + i * i) % SIZE;

    // If we've checked all positions, the table is full
    if (startIndex == index) {
      std::cout << "The table is full" << std::endl;
      return;
    }

    i++;
  } while (table[index].isOccupied && !table[index].isDeleted);

  // Insert at the found position
  table[index].data = key;
  table[index].isOccupied = true;
  table[index].isDeleted = false;
  std::cout << "Inserted " << key << " at index " << index << std::endl;
}

void HashTable::display() {
  std::cout << "Hash Table:" << std::endl;

  for (int i = 0; i < SIZE; i++) {
    std::cout << i << " ---> ";
    if (table[i].isOccupied && !table[i].isDeleted) {
      std::cout << table[i].data << std::endl;
    } else {
      std::cout << " " << std::endl;
    }
  }
}

void HashTable::remove(int key) {
  int index = hash(key);
  int startIndex = index;
  int i = 1;

  // Check if the key is at the initial hash position
  if (table[index].data == key && table[index].isOccupied &&
      !table[index].isDeleted) {
    table[index].isOccupied = false;
    table[index].isDeleted = true;
    std::cout << "Removed " << key << " at index " << index << std::endl;
    return;
  }

  // Search with quadratic probing
  while (table[index].isOccupied) {
    // Quadratic probing to find the key
    index = (startIndex + i * i) % SIZE;

    if (startIndex == index) {
      std::cout << "Element " << key << " not found" << std::endl;
      return;
    }

    i++;

    if (table[index].data == key && !table[index].isDeleted) {
      table[index].isOccupied = false;
      table[index].isDeleted = true;
      std::cout << "Removed " << key << " at index " << index << std::endl;
      return;
    }
  }

  std::cout << "Element " << key << " not found" << std::endl;
}

void HashTable::search(int key) {
  int index = hash(key);
  int startIndex = index;
  int i = 1;

  // Check if the key is at the initial hash position
  if (table[index].data == key && table[index].isOccupied &&
      !table[index].isDeleted) {
    std::cout << "Element " << key << " found at index " << index << std::endl;
    return;
  }

  // Search using quadratic probing
  while (table[index].isOccupied) {
    // Using quadratic probing
    index = (startIndex + i * i) % SIZE;

    if (startIndex == index) {
      std::cout << "Element " << key << " not found" << std::endl;
      return;
    }

    i++;

    if (table[index].data == key && !table[index].isDeleted) {
      std::cout << "Element " << key << " found at index " << index
                << std::endl;
      return;
    }
  }

  std::cout << "Element " << key << " not found" << std::endl;
}
