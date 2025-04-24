/*
 * Binary Search Tree (BST) Implementation
 *
 * This program implements the following Tree ADT operations:
 * 1. Insert - O(h) where h is the height of the tree (best: O(logn), worst:
 * O(n))
 * 2. Preorder traversal - O(n)
 * 3. Inorder traversal - O(n)
 * 4. Postorder traversal - O(n)
 * 5. Search - O(h) where h is the height of the tree (best: O(logn), worst:
 * O(n))
 *
 * The program uses a menu-driven approach to allow user interaction.
 */

#include <iostream>
using namespace std;

/**
 * Tree class implements a Binary Search Tree data structure
 */
class tree {
private:
  // Node structure for BST
  struct node {
    int data;        // Value stored in the node
    node *left;      // Pointer to left child
    node *right;     // Pointer to right child
  } *root = nullptr; // Root node pointer initially set to null

  // Private helper methods (internal implementation)
  node *insert(node *newroot, int value); // Recursive insert operation
  node *createnewnode(int val);           // Creates a new node with given value
  void preorder(node *current);           // Recursive preorder traversal
  void inorder(node *current);            // Recursive inorder traversal
  void postorder(node *current);          // Recursive postorder traversal

public:
  // Constructor to initialize empty tree
  tree() { root = nullptr; }
  // Public interface methods
  void inserthelper(int val); // Public method to insert value
  void preorderhelper();      // Public method for preorder traversal
  void inorderhelper();       // Public method for inorder traversal
  void postorderhelper();     // Public method for postorder traversal
  void search(int value);     // Search for a value in the tree
};

int main() {
  tree adt; // Create a BST object
  int choice;
  while (1) { // Infinite loop for menu-driven program
    cout << "\n<===== MENU =====>" << endl;
    cout << "1.Insert" << endl;
    cout << "2.Preorder" << endl;
    cout << "3.Inorder" << endl;
    cout << "4.Postorder" << endl;
    cout << "5.Search" << endl;
    cout << "6.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: // Insert operation
      int value;
      cout << "Enter the value to insert: ";
      cin >> value;
      adt.inserthelper(value);
      break;
    case 2: // Preorder traversal
      adt.preorderhelper();
      break;
    case 3: // Inorder traversal
      adt.inorderhelper();
      break;
    case 4: // Postorder traversal
      adt.postorderhelper();
      break;
    case 5: // Search operation
      int v;
      cout << "Enter the value you want to search: ";
      cin >> v;
      adt.search(v);
      break;
    case 6: // Exit program
      cout << "Exiting...." << endl;
      return 0;
    default: // Invalid choice
      cout << "The selected choice cease to Exist\nPlease Try Again" << endl;
    }
  }
}

/**
 * Recursively inserts a value into the BST
 * Time Complexity: O(h) where h is the height of the tree
 */
tree::node *tree::insert(node *newroot, int value) {
  if (newroot == nullptr) {         // Base case: empty spot found
    newroot = createnewnode(value); // Create new node here
    return newroot;
  }

  // Recursively find the correct position based on BST property
  if (value < newroot->data) { // If value is less, go left
    newroot->left = insert(newroot->left, value);
  } else { // If value is greater or equal, go right
    newroot->right = insert(newroot->right, value);
  }

  return newroot;
}

/**
 * Public interface for insert operation
 */
void tree::inserthelper(int val) { root = insert(root, val); }

/**
 * Creates and initializes a new node with given value
 */
tree::node *tree::createnewnode(int val) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = val;
  newnode->left = newnode->right = nullptr;
  return newnode;
}

/**
 * Preorder traversal (Root-Left-Right)
 * Time Complexity: O(n) where n is number of nodes
 */
void tree::preorder(node *current) {
  if (current != nullptr) {
    cout << current->data << " "; // Visit root
    preorder(current->left);      // Visit left subtree
    preorder(current->right);     // Visit right subtree
  }
}

/**
 * Public interface for preorder traversal
 */
void tree::preorderhelper() {
  cout << "Preorder Traversal: ";
  preorder(root);
  cout << endl;
}

/**
 * Inorder traversal (Left-Root-Right)
 * Time Complexity: O(n) where n is number of nodes
 * Note: Inorder traversal of BST produces sorted output
 */
void tree::inorder(node *current) {
  if (current != nullptr) {
    inorder(current->left);       // Visit left subtree
    cout << current->data << " "; // Visit root
    inorder(current->right);      // Visit right subtree
  }
}

/**
 * Public interface for inorder traversal
 */
void tree::inorderhelper() {
  cout << "Inorder Traversal: ";
  inorder(root);
  cout << endl;
}

/**
 * Postorder traversal (Left-Right-Root)
 * Time Complexity: O(n) where n is number of nodes
 */
void tree::postorder(node *current) {
  if (current != nullptr) {
    postorder(current->left);     // Visit left subtree
    postorder(current->right);    // Visit right subtree
    cout << current->data << " "; // Visit root
  }
}

/**
 * Public interface for postorder traversal
 */
void tree::postorderhelper() {
  cout << "Postorder Traversal: ";
  postorder(root);
  cout << endl;
}

/**
 * Search for a value in the BST iteratively
 * Time Complexity: O(h) where h is the height of the tree
 */
void tree::search(int value) {
  struct node *temp = root;
  int flag = 0; // Flag to track if value is found

  while (temp != nullptr) {
    if (value == temp->data) { // Value found
      flag = 1;
      break;
    } else {
      if (value < temp->data) { // If value is less, search left subtree
        temp = temp->left;
      } else if (value >
                 temp->data) { // If value is greater, search right subtree
        temp = temp->right;
      }
    }
  }

  // Display search result
  if (flag) {
    cout << value << " is found in the tree" << endl;
  } else {
    cout << value << " is not found in the tree" << endl;
  }
}
