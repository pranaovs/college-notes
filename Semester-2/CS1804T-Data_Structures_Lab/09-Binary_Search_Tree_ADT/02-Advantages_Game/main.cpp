// Calculates the advantage of each element compared to others in an array
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // Optimize I/O operations
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    // Find the first and second maximum values in the array
    int max1 = -1, max2 = -1;
    for (int num : arr) {
      if (num > max1) {
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max2 = num;
      }
    }

    // Calculate the advantage of each element:
    // - For the maximum element: difference with the second maximum
    // - For all other elements: difference with the maximum
    for (int i = 0; i < n; i++) {
      if (arr[i] == max1) {
        cout << arr[i] - max2 << " ";
      } else {
        cout << arr[i] - max1 << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
