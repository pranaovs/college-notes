#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k;
    int q;
    cin >> k >> q;
    vector<int> a;
    vector<int> n;
    for (int i = 0; i < k; i++) {
      int e;
      cin >> e;
      a.push_back(e);
    }

    for (int i = 0; i < q; i++) {
      int e;
      cin >> e;
      n.push_back(e);
    }

    // Process each query number
    for (int num : n) {
      int count = 0;
      // Count iterations up to min(a[0], num+1)
      for (int i = 0; i < a[0] && i <= num; i++) {
        count++;
      }
      cout << count - 1 << " ";
    }
    cout << endl;
  }
}
