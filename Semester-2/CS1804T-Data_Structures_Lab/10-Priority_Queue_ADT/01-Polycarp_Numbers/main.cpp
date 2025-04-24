#include <iostream>
#include <vector>
using namespace std;

int moves(vector<int>);

int main(int argc, char *argv[]) {
  int cases;
  cin >> cases;

  for (int c = 0; c < cases; c++) {
    int count;
    cin >> count;

    vector<int> nums;
    for (int i = 0; i < count; i++) {
      int num;
      cin >> num;
      nums.push_back(num);
    }

    cout << moves(nums) + 1 << endl;
  }
  return 0;
}

int moves(vector<int> nums) {
  int removal = -1;

  for (int i = 0; i < nums.size(); i++) {
    int first = -1;
    int second = i;

    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] == nums[i]) {
        first = second;
        second = j;
      }
    }

    if (first != -1) {
      i = first;
      removal = first;
    }
  }

  return removal;
}
