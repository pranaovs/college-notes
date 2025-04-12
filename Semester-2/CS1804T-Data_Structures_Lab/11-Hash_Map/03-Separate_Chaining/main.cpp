#include <iostream>
#include <vector>

// Size of the hash table
#define TABLE_SIZE 10

class Hashtable {
private:
  // Using vector for each bucket (separate chaining)
  std::vector<int> table[TABLE_SIZE];

  // Simple hash function that returns key modulo table size
  // Time Complexity: O(1)
  int hash(int key) { return key % TABLE_SIZE; }

public:
  // Constructor - no need to initialize vectors, they start empty
  // Time Complexity: O(1)
  Hashtable() {
    // Vectors are automatically initialized as empty
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
  // Get the hash index
  int index = hash(key);

  // Simply add the element to the end of the vector at the hash index
  // Time Complexity: O(1) on average
  table[index].push_back(key);
  std::cout << "Inserted " << key << " at index " << index << std::endl;
}

void Hashtable::display() {
  // Time Complexity: O(n) where n is total number of elements in the table
  std::cout << "Hashtable contents:" << std::endl;

  for (int i = 0; i < TABLE_SIZE; i++) {
    std::cout << i << " ---> ";
    if (!table[i].empty()) {
      for (size_t j = 0; j < table[i].size(); j++) {
        std::cout << table[i][j];
        if (j < table[i].size() - 1) {
          std::cout << " -> ";
        }
      }
    }
    std::cout << std::endl;
  }
}

void Hashtable::remove(int key) {
  // Get the hash index
  int index = hash(key);
  bool found = false;

  // Time Complexity: O(m) where m is the number of elements in the specific
  // bucket
  std::vector<int> &bucket = table[index];
  for (size_t i = 0; i < bucket.size(); i++) {
    if (bucket[i] == key) {
      // Erase the element by shifting all elements after it
      bucket.erase(bucket.begin() + i);
      std::cout << "Removed " << key << " from index " << index << std::endl;
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Element " << key << " not found in the table" << std::endl;
  }
}

void Hashtable::search(int key) {
  // Get the hash index
  int index = hash(key);
  bool found = false;

  // Time Complexity: O(m) where m is the number of elements in the specific
  // bucket
  for (size_t i = 0; i < table[index].size(); i++) {
    if (table[index][i] == key) {
      std::cout << "Element " << key << " found at index " << index
                << ", position " << i << std::endl;
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Element " << key << " not found in the table" << std::endl;
  }
}
