#include <iostream>
using namespace std;

int main() {
  int test;
  cout << "Enter the number of testcases:";
  cin >> test;

  for (int i = 0; i < test; i++) {
    int size;
    cout << "Enter the number of towers:";
    cin >> size;
    int tower[size];
    cout << "Enter the number of blocks in each tower:";
    for (int j = 0; j < size; j++) {
      cin >> tower[j];
    }
    for (int k = 1; k < size; k++) {
      while (tower[k] > tower[0]) {
        tower[0] += 1;
        tower[k] -= 1;
      }
    }
    cout << "Max blocks at tower 1 is " << tower[0] << endl;
  }
}
