#include <iostream>
using namespace std;

class tree {
  struct node {
    char data;
    node *left;
    node *right;
  };
  node *root;

public:
  tree() { root = NULL; }
  void insert(char x) {
    node *temp = new node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
      root = temp;
    } else {
      node *p = root;
      while (p->left != NULL && p->right != NULL) {
        if (p->left != NULL) {
          p = p->left;
        } else {
          p = p->right;
        }
      }
      if (p->left == NULL) {
        p->left = temp;
      } else {
        p->right = temp;
      }
    }
  }
  void inorder(node *p) {
    if (p != NULL) {
      inorder(p->left);
      cout << p->data << " ";
      inorder(p->right);
    }
  }
  void postorder(node *p) {
    if (p != NULL) {
      postorder(p->left);
      postorder(p->right);
      cout << p->data << " ";
    }
  }
  void preorder(node *p) {
    if (p != NULL) {
      cout << p->data << " ";
      preorder(p->left);
      preorder(p->right);
    }
  }
  void inorder() { inorder(root); }
  void postorder() { postorder(root); }
  void preorder() { preorder(root); }

  void search(char x) {
    node *p = root;
    while (p != NULL) {
      if (p->data == x) {
        cout << "Element found";
        return;
      } else {
        if (p->left != NULL) {
          p = p->left;
        } else {
          p = p->right;
        }
      }
    }
    cout << "Element not found";
  }
};

int main() {
  int exit = 0;
  tree t;
  while (exit != 1) {
    cout << "1.Insert\n2.Inorder\n3.Postorder\n4.Preorder\n5.Search\n6.Exit\n";
    int ch;
    cin >> ch;
    switch (ch) {
    case 1: {
      char x;
      cout << "Enter element to insert: ";
      cin >> x;
      t.insert(x);
      break;
    }
    case 2: {
      t.inorder();
      cout << endl;
      break;
    }
    case 3: {
      t.postorder();
      cout << endl;
      break;
    }
    case 4: {
      t.preorder();
      cout << endl;
      break;
    }
    case 5: {
      char x;
      cout << "Enter element to search: ";
      cin >> x;
      t.search(x);
      cout << endl;
      break;
    }
    case 6: {
      exit = 1;
      break;
    }
    }
  }
}
