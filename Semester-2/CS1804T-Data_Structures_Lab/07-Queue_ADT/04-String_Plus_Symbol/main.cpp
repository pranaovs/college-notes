#include "stack-sll.h"
#include <iostream>
using namespace std;

void removePlus(string s) {
  stack s1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+') {
      s1.pop();
    } else {
      s1.push(s[i]);
    }
  }
  while (s1.head != NULL) {
    cout << s1.head->data;
    s1.head = s1.head->next;
  }
}

int main() {
  string s;
  cout << "Enter a string: ";
  cin >> s;
  removePlus(s);
  return 0;
}
