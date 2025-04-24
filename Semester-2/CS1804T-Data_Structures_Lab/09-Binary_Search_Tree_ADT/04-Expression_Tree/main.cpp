#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Expression Tree class extends the binary tree functionality
class ExpressionTree {
private:
  struct Node {
    string data; // Value stored in the node (operand or operator)
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
  } *root;

  // Helper methods
  void preorder(Node *current);
  void inorder(Node *current);
  void postorder(Node *current);
  bool isOperator(const string &c);

public:
  ExpressionTree() { root = nullptr; }
  ~ExpressionTree();

  // Deallocates the tree recursively
  void deleteTree(Node *node);

  // Constructs an expression tree from a postfix expression
  void constructTree(const string &postfix);

  // Public traversal methods
  void preorderTraversal();
  void inorderTraversal();
  void postorderTraversal();
};

ExpressionTree::~ExpressionTree() { deleteTree(root); }

void ExpressionTree::deleteTree(Node *node) {
  if (node) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

bool ExpressionTree::isOperator(const string &c) {
  return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}

// Constructs expression tree from postfix expression
// Time Complexity: O(n) where n is the length of the postfix expression
void ExpressionTree::constructTree(const string &postfix) {
  stack<Node *> st;
  Node *t1, *t2, *temp;

  // Process each token in the postfix expression
  for (size_t i = 0; i < postfix.length(); i++) {
    if (postfix[i] == ' ')
      continue;

    // Extract token (operand or operator)
    string token;
    if (isdigit(postfix[i])) {
      // If it's a digit, extract the complete number
      while (i < postfix.length() &&
             (isdigit(postfix[i]) || postfix[i] == '.')) {
        token += postfix[i];
        i++;
      }
      i--; // Adjust for the loop increment
    } else {
      token = postfix[i];
    }

    // Create a new node with this token
    temp = new Node;
    temp->data = token;
    temp->left = temp->right = nullptr;

    if (!isOperator(token)) {
      // If operand, push to stack
      st.push(temp);
    } else {
      // If operator, pop two nodes from stack
      t1 = st.top();
      st.pop(); // First operand (right child)
      t2 = st.top();
      st.pop(); // Second operand (left child)

      // Make them children of the operator node
      temp->right = t1;
      temp->left = t2;

      // Push the operator node back to stack
      st.push(temp);
    }
  }

  // The final node in stack is the root
  root = st.top();
  st.pop();
}

// Preorder traversal: Root-Left-Right
// Time Complexity: O(n) where n is number of nodes
void ExpressionTree::preorder(Node *current) {
  if (current) {
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
  }
}

void ExpressionTree::preorderTraversal() {
  cout << "Preorder: ";
  preorder(root);
  cout << endl;
}

// Inorder traversal: Left-Root-Right
// For expression trees, need to add parentheses to preserve operator precedence
// Time Complexity: O(n) where n is number of nodes
void ExpressionTree::inorder(Node *current) {
  if (current) {
    if (isOperator(current->data))
      cout << "(";

    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);

    if (isOperator(current->data))
      cout << ")";
  }
}

void ExpressionTree::inorderTraversal() {
  cout << "Inorder: ";
  inorder(root);
  cout << endl;
}

// Postorder traversal: Left-Right-Root
// Time Complexity: O(n) where n is number of nodes
void ExpressionTree::postorder(Node *current) {
  if (current) {
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
  }
}

void ExpressionTree::postorderTraversal() {
  cout << "Postorder: ";
  postorder(root);
  cout << endl;
}

int main() {
  ExpressionTree tree;
  string postfix;
  int choice;

  while (true) {
    cout << "\n<===== EXPRESSION TREE MENU =====>" << endl;
    cout << "1. Postfix Expression" << endl;
    cout << "2. Construct Expression Tree" << endl;
    cout << "3. Preorder" << endl;
    cout << "4. Inorder" << endl;
    cout << "5. Postorder" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cin.ignore(); // Clear the input buffer
      cout << "Enter a postfix expression (separate tokens with spaces): ";
      getline(cin, postfix);
      break;

    case 2:
      cout << "Constructing expression tree from \"" << postfix << "\"" << endl;
      tree.constructTree(postfix);
      cout << "Expression tree constructed successfully!" << endl;
      break;

    case 3:
      tree.preorderTraversal();
      break;

    case 4:
      tree.inorderTraversal();
      break;

    case 5:
      tree.postorderTraversal();
      break;

    case 6:
      cout << "Exiting..." << endl;
      return 0;

    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  }

  return 0;
}
